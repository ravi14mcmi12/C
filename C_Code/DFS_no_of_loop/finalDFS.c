#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef enum boolean{false,true} bool;
int adj[MAX][MAX];
bool visited[MAX];
int stack[MAX];
int copyStack[MAX];


void create_graph();
void display();
void dfs(int v);
void cycleCheck();

int n; /* Denotes number of nodes in the graph */
int top=-1,t=-1;
void push(int val)
{
     stack[++top]=val;
     copyStack[++t]=val;
}
int pop()
{
     return stack[top--];
}

int main()
  {
	  int i,v,choice;

	  create_graph();

	while(1)
	{
	  printf("\n");
	  printf("1. Adjacency matrix.\n");
	  printf("2. Depth First Search using stack.\n");
	  printf("3.Cycle Check in DFS.\n4. Exit.\n");
      printf("Enter your choice : ");
      scanf("%d",&choice);

     switch(choice)
		{
		 case 1:
		        printf("Adjacency Matrix\n");
				display();
				break;
		case 2:
				printf("Enter starting node for Depth First Search : ");
				scanf("%d",&v);
				for(i=1;i<=n;i++)
				visited[i]=false;
				dfs(v);
				break;
        case 3:cycleCheck();
			   break;
		case 4:
				exit(1);
		default:
				printf("Wrong choice\n");
				break;
		}
	}
}

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of nodes : ");
	scanf("%d",&n);
	max_edges=n*(n-1);
      printf("\nStart with 1 as index in 2-D Array:\n");
	for(i=1;i<=max_edges;i++)
		{   
			
		    printf("Enter edge %d( 0 0 to quit ) : ",i);
			scanf("%d %d",&origin,&destin);

			if((origin==0) && (destin==0))
			break;

			if( (origin > n ) && (destin > n) && (origin<=0) && (destin<=0))
			{
				printf("Invalid edge!\n");
				i--;
			}
			else
			{
				adj[origin][destin]=1;
			}
		}
	}
void display()
{
	int i,j;
	for(i=1;i<=n;i++)
		{
		for(j=1;j<=n;j++)
		printf("%4d",adj[i][j]);
		printf("\n");
		}
}

void dfs(int v)
{
	
    int i,pop_v;
      top++;
   stack[top]=v;
   while (top>=0)
     {
		
	   pop_v=pop();
	  if( visited[pop_v]==false)
		{
	      printf("%d ",pop_v);
		  visited[pop_v]=true;
		}
	 else
	    continue;

	for(i=n;i>=1;i--)
		{
			if( (adj[pop_v][i]==1 )&& (visited[i]==false) )
				{
					//printf("push:%d\n",i);
				   
					push(i);
					
				}
		}
	 }
	
}

void cycleCheck()
{   int i,j,flag;
	for(i = t; i > -1; i--)
	{
	  for(j = i-1; j > -1; j--)
	    {
			if(copyStack[i] == copyStack[j])
			 {
			   flag = 1;
			   break;
			 }
		}
	}
	 
	 if(flag==1)
	 printf("\nGraph Contain Cycle...\n");
	 else
	 printf("\nThere is NO cycle in Graph:");
}

