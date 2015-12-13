#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
int size;
    
void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

int partion(int arr[], int p, int r)
    {
        int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
        int pivot;
        int i = p - 1;
        int j;
        pivot = arr[pivotIndex];
        swap(&arr[pivotIndex], &arr[r]);

        for (j = p; j < r; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            } 
        }
        swap(&arr[i+1], &arr[r]);
        return i + 1;
    }    
void quick_sort(int arr[], int p, int q)
    {
        int j;
        if (p < q)

        {
            j = partion(arr, p, q);
            quick_sort(arr, p, j-1);
            quick_sort(arr, j+1, q);
        }
    }
// This function is used in qsort to decide the relative order
// of elements at addresses p and q.
int comparator(const void *p, const void *q)
{
    // Get the values at given addresses
    int l = *(const int *)p;
    int r = *(const int *)q;
 
    // both odd, put the greater of two first.
    if ((l&1) && (r&1))
        return (r-l);
 
    // both even, put the smaller of two first
    if ( !(l&1) && !(r&1) )
        return (l-r);
 
    // l is even, put r first
    if (!(l&1))
        return 1;
 
    // l is odd, put l first
    return -1;
}  
    
int main()
    {
       int i;
        int arr[MAX];
        clock_t start, end,start1,end1;
		printf("\nEnter the Size of Array::") ;
		scanf("%d",&size);
        for (i = 0; i < size; i++)
            arr[i] = rand()%100;

         printf("\nRandomize Array of size[%d]::",size) ;   
           for (i = 0; i < size; i++)
             printf("  %d", arr[i]);
             printf("\n\n") ;
        
		start=clock();
        quick_sort(arr, 0, size-1); //function to sort the elements of array
        end=clock();
        
        printf("\nSorted Array :") ;
        for (i = 0; i < size; i++)
             printf(" %d", arr[i]);
         printf("\n\n") ;
        
        printf("\nRunning time of the randomized quick sort is ::%f sec\n",(end-start)/(double)CLOCKS_PER_SEC);
            
        //Quick sort by system
       int size = sizeof(arr) / sizeof(arr[0]);
       
       start1=clock();
       qsort((void*)arr, size, sizeof(arr[0]), comparator); 
       end1=clock();        
 
      printf("\nRunning time of the randomized quick sort by system is ::%f sec\n",(end1-start1)/(double)CLOCKS_PER_SEC);
        return 0;

    }
