#include<stdio.h>
#include<stdlib.h>

#define n 20

int setArr[n];
int elementArr[n];
static int count;

int insertSet();
int hashFunction1(int );
int hashFunction2(int );
void check();

int main()
	{
		int opt;
	  while(1)
	   {
		  printf("1.Insertion. \n2.check Set Membership.\n3.Exit:");
		  printf("\nEnter your Choice:") ;
		  scanf("%d",&opt);
		  switch(opt)
		   {
			   case 1: insertSet();
					  break;
			   case 2:check();
				       break;
			   case 3: exit(1);
			          break;
			  default:printf("\nInvalid Choice:");
		   }
	   }
	  return 0;
	}
int insertSet()
	{
		int data,opt,index1,index2,i;
		while(1)
		{
	      printf("\nEnter the Element:");
	      scanf("%d",&data);
	      
	      elementArr[count++]=data;
	      
	      index1=hashFunction1(data);
	       setArr[index1]=1;
	      index2=hashFunction2(data);
	        setArr[index2]=1;
	        
	       printf("your Current Set is:") ;
	       for(i=0;i<count;i++)
	         printf(" %d",elementArr[i]) ;
	         
	      printf("\nDo u want to enter more Number???[0/1]:") ;
	      scanf("%d",&opt) ;
	      if(opt !=1)
	      break;
	   }
	   return 0;
	}
void check()
	{
		int data,index1,index2;
		printf("\nEnter Elemet for Membership Check:");
		scanf("%d",&data);
		index1=hashFunction1(data);
	    index2=hashFunction2(data);
	     if(setArr[index1] && setArr[index2])
	      printf("\nMay Be Element Exist:\n");
	      else
	      printf("\nElement doesn't Exist:\n\n");
	}
	
int hashFunction1(int data)	
	{
		int val;
		val = data % n;
		return val;
	}
int hashFunction2(int data)	
	{
		int val;
		val = (data*data) % n;
		return val;
	}
