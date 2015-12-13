#include <stdio.h>
#include <stdlib.h>
static int count;
void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(int *a, int i, int n)
{
   int j;
   
   if (i == n)
      {
       for(i=0;i<n;i++)
       {
        printf("%d", a[i]);
        
       }
       count++;
       printf("\n");
	  } 
   else
   {
        for (j = i; j <n; j++)
       {
          swap((&a[i]), (&a[j]));
          permute(&a[0], i+1, n);
          swap((&a[i]), (&a[j])); //backtrack
       }
   }
}
 
/* Driver program to test above functions */
int main()
{
   int a[100];
   int n,i;
   printf("\nEnter the Digit for Permutation Generation(It should be between 1 to 100):");
    scanf("%d",&n);
   printf("\nNowEntered those Number:");
//  printf("\nEnter Number for Permutation Generation:");
 //  scanf("%d",&n);
  for(i=0;i<n;i++)
     {
       scanf("%d",&a[i]);
     } 
    printf("\nPermutation of your Given number is as Follow:\n");
   permute(&a[0],0, n);
   printf("\nThe total number of permutation  of Entered Number is:%d\n\n\n",count);
   return 0;
}
