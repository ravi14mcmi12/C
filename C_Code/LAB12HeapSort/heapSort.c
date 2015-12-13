//Max Heap sort
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
 
int arr[MAX];

void display(int *arr,int num)
	{
		int i;
		for(i=0;i<num;i++)
    	printf(" %d",arr[i]);
	}
void swap(int x,int  y)
{
	int temp;
	temp=arr[x];
	arr[x]=arr[y];
	arr[y]=temp;
}
void percolate_down(int *arr,int i,int num)
{
	int max,lChild,rChild ,temp;
 do{
	lChild=2*i+1;
	rChild=2*i+2;
	max=i;
	
	if( (lChild <= num ) && (arr[max]<arr[lChild]) )
	 	 max=lChild;
	 	 
	if ( (rChild <= num ) &&  (arr[max]<arr[rChild]) )
	   max=rChild ;
	 
	 if(max!=i)
	  {
		 temp=arr[i];
		 arr[i]=arr[max];
		 arr[max]=temp;
	  }
	  i++;
	 } 
	  while(i<num);
	  
}
void delete_sort(int *arr,int num)
{
	int i,newNum,k;
	newNum=num;
	printf("\n\nMax Heap Building Started....:");
	for(i=num;i>0;i--)
	{
		k=0;
		newNum -= 1;
		swap(k,newNum);
		printf("\n\n");
		display(arr,num);
		
	 percolate_down(arr,k,newNum-1);
		
		
	}
}

int main()
{
	int num,i;
	
	printf("\nEnter the toal Number of Element for Heap Sort:");
	scanf("%d",&num) ;
	printf("\nNow Enter those Element:") ;
	for(i=0;i<num;i++)
		{
			scanf("%d",&arr[i]);
		}
	printf("\nInput List of Element:");
	display(arr,num);
	
	printf("\n\nBuilding Max Heap..:\n");
	for(i=(num-1)/2;i>=0;i--)
	{
	 percolate_down(arr,i,num);
	 display(arr,num);
	 printf("\n\n");
    }
	
	
	printf("\nAfter Percolate Down Operation:");
	display(arr,num);
	
	delete_sort(arr,num);
	printf("\nAfter Heap Sort Sorted Array:");
	display(arr,num);
	
	return 0;
}
