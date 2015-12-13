#include<stdio.h>
#include<stdlib.h>

int num;
int count;
int a[100];

void swap(int *,int *);

int noOfPermutation(void);

void input(void);

void display(void);

void permutationRecursion(int *,int,int);

void permutation(int *,int,int) ;
 
void swap(int *n1,int *n2)
         {
	  int temp;
          temp=*n1;
          *n1=*n2;
          *n2=temp;
	 }

int noOfPermutation()
	{
	 int permutation=1;
	 int i;
	   for(i=1;i<=num;i++)
		{
		  permutation=permutation*i;
		}
		//printf("%d\n",permutation);
  	 return permutation;
	}
void input()
	 {
           int i;
          printf("\nEnter Digit for Permutation Generation:") ;
          scanf("%d",&num);
	  printf("\nNow Enter those numbers:\n");
           for(i=0;i<num;i++)
		{
		  scanf("%d",&a[i]);
		} 
 	 }

void display()
	{
	 int i;
         for(i=0;i<num;i++)
           {
	     printf("%d",a[i]) ;
	   }
           count++;
         printf("\n") ;
	}	

void permutationRecursion(int *a,int i,int num)
	{
          int j;
            if(i == num)
                {
		  display();
		}
	    else
                {
		  for(j=i;j<num;j++)
		    {
                      swap(&a[i],&a[j]) ;
		      permutationRecursion(&a[0],i+1,num) ;
 		      swap(&a[i],&a[j]) ;
		    }
		}
	}

void permutation(int *a,int i,int num)
         {
	        int y;
          // x=noOfPermutation() ;
            while(count<noOfPermutation())
             {
		          for(y=0;y<num-1;y++)
		            {
		             swap(&a[y],&a[y+1]) ;
                     display();
		            }
              swap(&a[0],&a[1]) ;
              display();
   
		         for(y=num-1;y>0;y--)
		           {
		            swap(&a[y],&a[y-1]) ;
                    display() ;	
		           }
	         swap(&a[num-1],&a[num-2]) ;
	         display() ;
	       }
	 }

int main()
 {
   int opt;
   char ch='y';
   

      do{
          printf("\nProgram for Permutation of Number:\n") ;
	  printf("1.Permutation Using Recursion:\n") ;
          printf("2.Permutation Using Without Recursion:\n") ;
          printf("\nEnter your choice [1-2]:") ;
          scanf("%d",&opt) ;
        // fscanf(stdin, "%d",&opt) ;
   
          switch(opt)
              {
		case 1: input();
			printf("\nPermutation of Entered number are as Follow:\n\n");
			count=0;
			permutationRecursion(&a[0],0,num);
			printf("\n\nTotal number of Permutaion is:%d\n",count);
                break ;
                
		case 2: input() ;
			printf("\nPermutation of Entered number are as Follow:\n\n") ;
			count=0;
 			permutation(&a[0],0,num);
 			printf("\n\nToral number fo Permutation is:%d\n",count) ;
                break ;

		default: printf("\nHello you have entered wrong choice !!!!\n") ;

	      }
                 printf("\n Do you want to continue-? [y/n]:") ;
                 scanf("\n%c",&ch) ;
         }while( ch =='Y' || ch =='y') ;
       return 0 ;
 }
