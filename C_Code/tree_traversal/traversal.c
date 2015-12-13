#include<stdio.h>
#include<stdlib.h>

typedef struct node
	{
	  int info;
	  struct node * lChild ;
	  struct node * rChild;
	}node;
node *createNode(int value)
	{
         node *temp=(node*)malloc(1*sizeof(node)) ;
	 temp->info=value;
	 temp->lChild=NULL;
	 temp->rChild=NULL;
	 return temp;
	}
node *insertNode(struct node* root,int value)
	{	
          if(root == NULL)
		return createNode(value) ;
	  else if(node->info > value)
		node->lChild= createNode(value) ;
	  else
		node->rChild= createNode(value) ;
	 return node;
	}

int main()
	{
	 int opt,data;
	 char ch= 'y' ;
	 node *root=NULL;

	 printf("\nProgram For Tree Traversal without using Recursion:\n") ;
	 printf("Enter Node for Tree Traversal:") ;
	 scanf("%d",&data)

	 insertNode(root,data) ;

	 printf("\n1.Preorder Traversal::") ;
	 printf("\n2.Inoreder Traversl::") ;
	 printf("\n3.Posorder Traversal::") ;
	 printf("\nEnter your Choice::\n") ;
	 scanf("%d",&opt) ;
	  do{
	      switch(opt)
		{
		 case 1://preorder() ;
		 break;

		 case 2://inorder() ;
		 break;
		
		 case 3://postorder() ;
		 break ;
		 
		 default:printf("\nHello Invalid Choice::\n") ;
		 break;
		}printf("\nDo you want to Contiune .....????[y/s]:") ;
		 scanf("\n%d",&ch) ;
	    }while(ch == 'y' || ch == 'Y') ;

	}
