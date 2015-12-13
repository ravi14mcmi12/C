#include <stdio.h>
#include <stdlib.h>

#define row 20
#define coln 20


void display(int x[row][coln],int );
int probCost(int p[row][coln],int,int);
int obst(int w[row][coln],int p[row][coln],int probEle[row],int root[row][coln],int );
int minCost(int w[row][coln],int p[row][coln],int root[row][coln],int,int);

int main()
	{
	  int n,i,Weight;
	  int w[row][coln],root[row][coln],p[row][coln] ;
	  int probEle[row];
	  printf("\nEnter Total Number of  Element:") ;
	  scanf("%d",&n) ;
	  printf("\nNow Entered prob. of those number::\n") ;

       for(i=0;i<n;i++)
	   scanf("%d",&probEle[i]);
	   
	  
	  printf("\nWeight Matrix:\n");
	    Weight=obst(w,p,probEle,root,n);
         display(w,n);
         
      printf("\nProbability cost Matrix:\n") ;
	     display(p,n);
	     
	  printf("\nOtimal Binary Search Tree:\n");
	      display(root,n);
	      
      printf("\nOptimal Binary Search Tree Cost is:%d",Weight);
       return 0;
	}
int obst(int w[row][coln],int p[row][coln],int probEle[row],int root[row][coln],int n)
	{
		int i,j,k;
	 for(i=0;i<=n;i++)
	  {
	  for(j=0;j<=n;j++)
	    {
	     if(i==j)
	     {
		  p[i][j]=0;
	      w[i][j]=0;
	     }
	     else if(j==i+1)
	     {
	      p[i][j]=probEle[i];
	      w[i][j]=p[i][j];
	      root[i][j]=j;
	     }
	      else
	      {
			p[i][j]=-1;
	        w[i][j]=-1;
	        
	      }
	    }
	  }
	   k=n-1;
     for(i=0;i<k;i=0)
	     {
	      for(j=n-k+1;j<=n;j++,i++)
	         {
			   p[i][j]=probCost(p,i,j);
			   w[i][j]=minCost(w,p,root,i,j);
		     }
		     k--;
	      }
	      return (w[0][5]);
	}
int minCost(int w[row][coln],int p[row][coln],int root[row][coln],int i,int j)
    {
		int min,newMin,r;
		min=w[i][i]+w[i+1][j];
		root[i][j]=i+1;
		for(r=i+1;r<j;r++)
		 {
		   newMin=w[i][r]+w[r+1][j];
		   if(newMin<min)
		    {
		     min=newMin;
		     root[i][j]=r+1;
	    	}
		 }
		 return (min+p[i][j]);
	}

int probCost(int p[row][coln],int i,int j)
	{
		int k,val;
		val=0;
		for(k=i;k<j;k++)
		 {
		  val+=p[k][k+1];
	     }
	     return val;
	}
void display(int x[row][coln],int n)
	{
	  int i,j;
         for(i=0;i<n+1;i++)
	   {
            for(j=0;j<n+1;j++)
	     {
	      printf("%4d",x[i][j]);
	     }
	     printf("\n");
       }
    }
