#include<stdio.h>
#include<stdlib.h>
#define stack_size 20

 struct bst
	{
          int info;
          struct bst *lNode;
          struct bst *rNode;
	}*root=NULL,*temp=NULL;

typedef struct stack
	{
	 int top;
	 int items[stack_size] ;
	}stack;

void insertNode();
void create();
void insertSearch(struct bst *t);
void inorder(struct bst *t);
void preorder(struct bst *t);
void postorder(struct bst *t);

void push(stack *st,int value)
	{
	  if(st->top < stack_size-1)
	    st->items[++(st->top)]=value;
	  else
	    printf("\nSorry Stack is Full");
	} 
int pop(stack *st)
	{
	 if(st->top < 0)
	   return st->items[(st->top)--];
	 else
	  printf("\nHello STACK is EMPTY:");
	}
int isEmpty(stack *st)
	{
          if(st->top < 0) 
		return 1;
	  else
		return 0;
	}
int main()
	{
	  int opt,h,data,noOfNode,i;
	  char ch='y';

	  do	
	   {
             printf("\n Program for  BST Traversal without Recursion....\n") ;
	     printf("\n1.To insert an element in BST::\n") ;
             printf("\n2.Inorder Traversal...................::\n ") ;
	     printf("\n3.Preorder Traversal.................::\n") ;
	     printf("\n4.Postorder Traversal.................::\n") ;
	     printf("\nEnter your Choice......................::") ;
             scanf("%d",&opt) ;

	    switch(opt)
	  	{
		  case 1:printf("\nHow many nodes do you want Enter:") ;
		         scanf("%d",&noOfNode) ;
 			   for(i=0;i<noOfNode;i++)
			     insertNode();
			break;

		  case 2:inorder(root);
                        break;

		  case 3://preorder(root);
                        break;

		  case 4://postorder(root);
                        break;

		  default:printf("\n Hello you Entered wrong Choice ..\n") ;
                        
		}printf("\nDo you want to continue ?? [y/n]:") ;
		 scanf("\n%c",&ch) ;
	   }while(ch == 'y' || ch == 'Y');
	    
	}

void inorder(struct bst *t)
	{
         stack st;
  	 st.top = -1;
	 temp = t;
		while(!isEmpty(&st) || temp)
			{
			 if(temp)
			  {
 			    push(&st, temp);
			    temp = temp->lNode;
			  }
			else
			  {
			    temp = pop(&st);
			    printf("%d ", temp->info);
			    temp = temp->rNode;
			  }
 			}
	}	

void insertNode()
        {
           create();
           if(root==NULL)
            root=temp;
	   else
           insertSearch(root);
        }

void create()
	{
	 int data;
         temp=(struct bst*)malloc(1*sizeof(struct bst));
	 printf("\nEnter a element to insert in BST:") ;
	 scanf("%d",&data) ;
	 temp->info=data;
	 temp->lNode=NULL;
	 temp->rNode=NULL;
	}

void insertSearch(struct bst *t)
	{
         if( (temp->info > t->info) && (t->rNode !=NULL) )
	  insertSearch(t->rNode) ;
         else if( (temp->info > t->info) && (t->rNode==NULL) )
          t->rNode=temp;
        if( (temp->info < t->info) && (t->lNode !=NULL))
	  insertSearch(t->lNode) ;
        else if( (temp ->info < t->info) && (t->lNode==NULL) )
          t->lNode=temp;
	}
          
	 












