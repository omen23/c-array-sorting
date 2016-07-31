/* © oMeN23 aka David Schuster in 2016
 * program that shows new C programmers the easiest array sorting/array-member swapping mechanisms ...
 * free of charge - atleast please mention me
 * hope this helps anyone
 * contact: https://twitter.com/oMeN2351
 */ 
#include <stdlib.h>
#include <stdio.h>

int compar_fn(const void* a, const void* b) 
{
if (*(int*)a > *(int*)b) return 1;
if (*(int*)a == *(int*)b) return 0;
if (*(int*)a < *(int*)b) return -1;
printf("problem in function %s in file %s:%d\n", __PRETTY_FUNCTION__, __FILE__, __LINE__ );
return 0;
}

void xor_swap(int* v1, int* v2)
{
  if (v1 != v2)
      *v1^=*v2^(*v2=*v1);
}

#define xor_swap2(a, b) ((&(a) == &(b)) ? (a) : ((a)^=(b),(b)^=(a),(a)^=(b))) 

void insertion_sort(int a[], int n)
{
    int c, d;
    
    for (c = 1; c < n; c++)
    {
        d = c;
        
        while (d > 0 && a[d] < a[d-1])
        {
            xor_swap2(a[d], a[d-1]);
            d--;
        }
    }
}

void heap_sort(int a[], int n)
{
    int i, j, c, root;
    
    for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;
            if (a[root] < a[c])            
                xor_swap2(a[root], a[c]);
                        
            c = root;
        } while (c != 0);
    }
    
    for (j = (n - 1); j >= 0; j--)
    {
        xor_swap2(a[0], a[j]);
        
        root = 0;
        
        do
        {
            c = 2 * root + 1;
            if ((a[c] < a[c+1]) && c < j - 1)
                c++;
            
            if (a[root] < a[c] && c < j)            
                xor_swap2(a[root], a[c]);            
            
            root = c;
        } while (c < j);
    }
}    

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
      xor_swap2(a[j], a[min]);
    }
  }
}

void gnome_sort(int a[], int n)
{
    void _gsort(int a[], int n)
    {
        int pos = n - 1;
        while (pos > 0 && a[pos-1] > a[pos])
        {
            xor_swap2(a[pos-1], a[pos]);
            pos--;        
        }
    }
    
    for (int pos = 1; pos <= n; pos++)
        _gsort(a, pos);
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
        xor_swap2(a[d], a[d+1]);
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

  puts("calling insertion_sort(...)");
  insertion_sort(a, array_size);
//   heap_sort(a, array_size);
//   gnome_sort(a, array_size);
//   bubble_sort(a, array_size);
//   selection_sort(a, array_size);
//   qsort((void*)a, array_size, sizeof(int), compar_fn);

  display_array(a, array_size);

  return 0;
}
