#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{
		int value;
		struct node *left;
		struct node *right;
	   }Node;

typedef struct stack
	{
 	  Node *st;
	  struct stahck *next;
	} stack;

 stack *top=NULL;
 
 void inorder(Node* root);
void preorder(Node* root) ;
void postorder(Node* root);

stack push(Node *tp)
{
 if(top==NULL)
	{
		top = (stack*)malloc(sizeof(stack));
		top->st = tp;
		top->next = NULL;
	}
	else
	{
		stack *temp;
		temp = (stack*)malloc(sizeof(stack));
		temp->st=tp;
		temp->next=top;
		top = temp;
	}
 
 
}

node* pop()
{
        node *new = top->st;
	top = top->next;
	return new;
}

node* peek(stack ms)
	{
	  if(st.top<0)
	   {
	    printf("Stack empty\n");
	    return 0;
	   }
 	   return new;
	}
int is_empty(stack ms)
	{
	  if(ms.top <0) return 1;
	  else return 0;
	}
	Node * create_node(int value)
	{
	  Node * temp = (Node *)malloc(sizeof(Node));
	  temp->value = value;
	  temp->right= NULL;
	  temp->left = NULL;
	  return temp;
        }

Node * addNode(Node *node, int value)
	{
	  if(node == NULL)
             {
		return create_node(value);
 	     }
	else
	    {
		if (node->value > value)
		{
	         node->left = addNode(node->left, value);
		}
  		else
		{
	 	 node->right = addNode(node->right, value);
	        }
  	    }
          return node;
       }
 
int main()
	{
	   Node *root = NULL;
	   Node * last = NULL;
	   Node *ptrToHead = NULL;
//Creating a binary tree
 	   root = addNode(root,30);
           root = addNode(root,20);
           root = addNode(root,15);
           root = addNode(root,25);
           root = addNode(root,40);
           root = addNode(root,37);
           root = addNode(root,45);

         inorder(root);
	 preorder(root);
	 postorder(root);
         return 0;
	}

void inorder(Node * root)
	{
	  stack ms;
	  ms.top = -1;
 	  Node * temp = root;
  	 while(!is_empty(ms) || temp)
 	     {
		if(temp)
		{
		push(&ms, temp);
		temp = temp->left;
	        }
		else
		 {
		  temp = pop(&ms);
		  printf("%d ", temp->value);
		  temp = temp->right;
 		 }
	     }
	}
void preorder(Node *root)
	{
	  stack ms;
	  ms.top = -1;
	  int i;
 
	if(root == NULL) return ;
 
	Node * temp ;
	/* Step 1 : Start with root */
	push(&ms,root);
 
	while(!is_empty(ms))
 	   {
	     /* Step 5 : Pop the node */
	       temp = pop(&ms);
	     /* Step 2 : Print the node */
	       printf("output : %d ", temp->value);
 
	     /* Step 3: Push right child first */
	       if(temp->right)	
		{
	          push(&ms, temp->right);
	        }
	     /* Step 4: Push left child */
	       if(temp->left)
		{
	         push(&ms, temp->left);
		}
	    }
 
 
	}

void postorder(Node * root)
	{
	   stack ms;
	    ms.top = -1;
	    if(root == NULL) return ;
 
	 	Node * temp ;
		push(&ms,root);
		Node * prev = NULL;
		while(!is_empty(ms))
		   {
                	temp = peek(ms);
	/* case 1. We are nmoving down the tree. */
		    if(prev == NULL || prev->left == temp || prev->right == temp)
		      {
		  	  if(temp->left)
		             push(&ms,temp->left);
		          else if(temp->right)
	 	          push(&ms,temp->right);
			  else
			    {
			/* If node is leaf node */
				printf("%d ", temp->value);
				pop(&ms);
			    }
		       }
	/* case 2. We are moving up the tree from left child */
		   if(temp->left == prev)
			{
			   if(temp->right)
			       push(&ms,temp->right);
			   else
 			     {
				printf("%d ", temp->value);
				pop(&ms);
			     }
			}
 
	/* case 3. We are moving up the tree from right child */
		  if(temp->right == prev)
			{
			   printf("%d ", temp->value);
			   pop(&ms);
			}
		  prev = temp;
		  }
 
	}
