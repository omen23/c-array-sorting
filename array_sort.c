/* © oMeN23 aka David Schuster in 2016
 * program that shows new C programmers the easiest array sorting/array-member swapping mechanisms ...
 * free of charge - atleast please mention me
 * hope this helps anyone
 * contact: https://twitter.com/oMeN2351
 */ 
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <err.h>

int compar_fn(const void* a, const void* b) 
{
if (*(int*)a > *(int*)b) return 1;
if (*(int*)a == *(int*)b) return 0;
if (*(int*)a < *(int*)b) return -1;

err(errno, "The qsort comparison function encountered an error.\n");
}

void xor_swap(int* v1, int* v2)
{
  if (v1 != v2)
      *v1^=*v2^(*v2=*v1);
}
#define xor_swap2(a, b) ((&(a) == &(b)) ? (a) : ((a)^=(b),(b)^=(a),(a)^=(b))) 

void selection_sort(int a[], int n)
{
  int i, j;
  
  for (j = 0; j < (n - 1); j++)
  {
    int min = j;
    
    for (i = (j + 1); i < n; i++)
    {
      if (a[i] < a[min])
      {
        min = i;
      }
    }
    
    if (min != j)
    {      
      xor_swap(&a[j], &a[min]);
    }
  }
}

void bubble_sort(int a[], int n)
{
  int c, d;
  
  for (c = 0; c < (n - 1); c++)
  {
    for (d = 0; d < n - c - 1; d++)
    {
      if (a[d] > a[d+1])
      {
        xor_swap(&a[d], &a[d+1]);
      }
    }
  }
}

void display_array(int a[], int n) 
{
  for (int x  = 0; x < n; x++)
    printf("a[%d] = %d\n", x, a[x]);
}

int 
main(void)
{
  int a[] = { 26, 9, 88, 12, 55, 99, 12324, 111, 43, 42, 41, 88, 102 , 55, 66, 77, 88, 123, 10000, 103, 105 };
  size_t array_size = (sizeof a / sizeof a[0]);

  display_array(a, array_size);

  puts("calling selection_sort(...)");
//   bubble_sort(a, array_size);
  selection_sort(a, array_size);
//   qsort((void*)a, array_size, sizeof(int), compar_fn);

  display_array(a, array_size);

  return 0;
}
