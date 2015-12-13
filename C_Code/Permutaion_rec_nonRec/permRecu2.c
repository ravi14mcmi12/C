#include<stdio.h>

void swap(int *,int*);

void permute(void);

int noofpermutations();

void display(void);

int m,n,noofterms,count=0;
int a[100];

void swap(int *p1,int *p2)
	{ int temp;
          temp = *p1;
 	  *p1 = *p2;
	  *p2 = temp;
	}

int noofpermutations()
 	{
	  int permutations=1,x;

	  for(x=1;x<=noofterms;x++)
               permutations=permutations*x;

	  return permutations;
  	}

void display()
	{
	  int x;
	   for(x=0;x<noofterms;x++)
	      printf("%d",a[x]);

           printf(" \n");
	   count++;
	}

void permute()
	{
	  int y;
	    while(count<noofpermutations())
		{
			for(y=0;y<noofterms-1;y++)
		     { 
	                swap(&a[y],&a[y+1]);
			        display();
		     }
		swap(&a[0],&a[1]);
		display();
		for(y=noofterms-1;y>0;y--)
		      	{ 
   			     swap(&a[y],&a[y-1]);
			     display();
			    }
        swap(&a[noofterms-1],&a[noofterms-2]);
        display();
		}
	}	

int main()
   {
      int x;
        printf("Enter Number of terms : ");
	scanf("%d",&noofterms);
	printf("Enter the terms : ");
	     for(x=0;x<noofterms;x++)
	     scanf("%d",&a[x]);
       printf("\nPermutations are : \n");

       permute();

      printf("\nTotal Permutations : %d",noofpermutations());
      return 0;
  }

