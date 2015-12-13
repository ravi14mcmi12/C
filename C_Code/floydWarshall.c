#include <stdio.h>
#include <stdlib.h>

#define v 9
#define INF 99

int graph[v][v];
int path[v][v];

void display(int graph[v][v],int );
void floydWarshall(int graph[v][v],int n);
void printPath(int path[v][v],int n);
void pathRecursive(int i,int j);
void printPathWithoutRecursive(int path[v][v],int n);
void path1(int i,int j);

int main()
	{
		int n,i,j;
		printf("\nEnter the number of total Node in Graph:");
		scanf("\n%d",&n) ;
		printf("\nEnter the distance between vertices.....\nIf no edge put 99(say infinity):\n\n");
		for(i=0;i<n;i++)
		   {
			   for(j=0;j<n;j++)
			      {
					  printf("\nEnter value for Graph[%d][%d]:",i,j);
					  scanf("%d",&graph[i][j]);
				  }
		   }
		 for(i=0;i<n;i++)
			{
			  for(j=0;j<n;j++)
			    {
				  if(i==j)
				    path[i][j]=-1;
				  else
				    path[i][j]=i;
				}
			}
		   display(graph,n);
		   floydWarshall(graph,n);
		   printf("\nAfter Algo Appiled: \n");
		   display(graph,n);
		   printPath(path,n);
		   printf("\nPath Without Recursion:\n");
		   printPathWithoutRecursive(path,n);
	return 0;
	}
void floydWarshall(int graph[v][v],int n)
	{
		int i,j,k;
		for(k=0;k<n;k++)
		    {
			 for(i=0;i<n;i++)
			      {
				   for(j=0;j<n;j++)
					 {
						 if(i==j)
						    graph[i][j]=0;
					     if( ( graph[i][j] >  (graph[i][k] + graph[k][j]) ) && (graph[i][k]!=INF) & (graph[i][k]!=INF) )
							 {
						      graph[i][j] = (graph[i][k] + graph[k][j]);
						      path[i][j] = path[k][j];
						     }
						 
					 }
				  }
			}
			
	}
void printPathWithoutRecursive(int path[v][v],int n)
	 {
		int i,j;
		for(i=0;i<n;i++)
		  {
		    for(j=0;j<n;j++)
		      {
				  printf("Shortest path Between (%d , %d):",i,j);
				  path1(i,j);
				  printf("\t  Cost of path::%d",graph[i][j]);
				  printf("\n");
				  				    
			  }
		  } 
	 }
void path1(int i,int j)
     {
	  int newJ,count,k;
	  int temp[9];
	  count=0;
	  temp[count]=j;
	  count++;
	  newJ=path[i][j];
	  
	   
	     while(newJ>=0)
	     {
		  if(newJ==0)
	       {
	        temp[count]=i;
	        break;
	       }
	      else
	       {
		   temp[count]=newJ;
		   newJ=path[i][newJ];
		   count++;
	      }
	    }
	    for(k=count;k>-1;k--)
	      printf("->%d",temp[k]);
	 }
	 
void printPath(int path[v][v],int n)
	{
		int i,j;
		for(i=0;i<n;i++)
		  {
		    for(j=0;j<n;j++)
		      {
				  printf("Shortest path Between (%d , %d):",i,j);
				  pathRecursive(i,j);
				  printf("\t  Cost of path::%d",graph[i][j]);
				  printf("\n");
				  				    
			  }
		  }
	}
void pathRecursive(int i,int j)
	{
		int newJ;
	   if(i == j)
		   printf(" ->%d ",i);
	   else if(path[i][j] == -1)
	          printf("\nNo path Exist:") ;
	   else
			{
		     newJ=path[i][j];
		     pathRecursive(i,newJ);
		     printf(" ->%d ",j);
		    }
	}
void display(int graph[v][v],int n)
	{
		int i,j;
		printf("Graph Adjancy matrix:\n");
		for(i=0;i<n;i++)
		   {
			   for(j=0;j<n;j++)
			      {		  
					  printf("%4d",graph[i][j]);
				  }
				  printf("\n");
		   }
		for(i=0;i<n;i++)
		  {
			 if(graph[i][i]<0)
			 {
			 printf("Negative Cycle Exist");
			 printf("\nFloyd-Warshall algorithm will not output the correct result");
			 break;
		     }
			 
		  }
	}
