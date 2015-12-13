#include<stdio.h>
#include<stdlib.h>

 struct bst
	{
          int info;
          struct bst *lNode;
          struct bst *rNode;
	}*root=NULL,*temp=NULL,*t1,*t2;

static int index;
void insertNode();
void create();
void delete();
void deleteSearch(struct bst *t,int data) ;
void delete1(struct bst *t) ;
int smallest(struct bst *t) ;
int largest(struct bst *t) ;
void find(struct bst *t,int data);
void insertSearch(struct bst *t);
void inorder(struct bst *t);
void preorder(struct bst *t);
void postorder(struct bst *t);
 int height(struct bst *t);
int flag =1;
int main()
	{
	  int opt,h,data;
	  char ch='y';

	  do	
	   {
         printf("\n Program for  Binary Search Tree....\n") ;
	     printf("\n1.To insert an element in BST(Please maintain Acending order)::\n") ;
         printf("\n2.To Delete an element from created BST::\n") ;
	     printf("\n3.To Search an element in Created BST..::\n") ;
         printf("\n4.Inorder Traversal...................::\n ") ;
	     printf("\n5.Preorder Traversal.................::\n") ;
	     printf("\n6.Postorder Traversal.................::\n") ;
	     printf("\n7.Hight of BST is.....................::\n") ;
	     printf("\nEnter your Choice......................::") ;
             scanf("%d",&opt) ;

	    switch(opt)
	  	{
		  case 1:insertNode();
			     break;

		  case 2:
			  delete();
                          break;

	 	  case 3:printf("\nEnter an Element for search :");
			     scanf("%d",&data);
			     index=0;
			     find(root,data);
                 break;

		  case 4:inorder(root);
                 break;

		  case 5:preorder(root);
		         break;

		  case 6:postorder(root);
                 break;

		  case 7:h=height(root);
			     printf("\nHeight of given BST is..::%d",h) ;
			     break;
		 default:printf("\n Hello you Entered wrong Choice ..\n") ;
                        
		}printf("\nDo you want to continue ?? [y/n]:") ;
		 scanf("\n%c",&ch) ;
	   }while(ch == 'y' || ch == 'Y');
	    
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
void find(struct bst *t,int data)
         {
	     if(root ==NULL)
	      {
	      printf("\nsorry In BST there is no element::\n");
              return;
	      }
            if(t->info==data)
	      {

	        printf("\nElement found in BST successfuly at Index ::%d",index);
	       
	      } 
              else if(data < t->info)
	        {
	          index=2*index+1;
                find(t->lNode,data);
	        }
	      else if(data > t->info)
	        {
	          index=2*index+2;
   	       find(t->rNode,data);
	        }
	    else
	     printf("\nElement not found in BST::\n");
            return;
	}
	
/* To check for the deleted node */
void delete()
         {
          int data;
          if (root == NULL)
           {
             printf("No elements in a tree to delete");
            return;
           }
          printf("Enter the data to be deleted : ");
          scanf("%d", &data);
          t1 = root;
          t2 = root;
         deleteSearch(root,data);
        }
        
 /* Search for the appropriate position to insert the new node */
void deleteSearch(struct bst *t,int data)
		{
		if ((data > t->info))
			{
			t1 = t;
			deleteSearch(t->rNode, data);
			}
		else if ((data < t->info))
			{
			t1 = t;
			deleteSearch(t->lNode, data);
			}
		else if ((data==t->info))
			{
			delete1(t);
			}
		}
/* To delete a node */
void delete1(struct bst *t)
		{
		int k;
	/* To delete leaf node */
		if ( (t->lNode == NULL) && (t->rNode == NULL) )
		{
	          if (t1->lNode == t)
		   {
		    t1->lNode = NULL;
		   }
	          else
		   {
                    t1->rNode = NULL;
		   }
		t = NULL;
		free(t);
		return;
              }
    /* To delete node having one left hand child */
            else if ((t->rNode == NULL))
		{
	          if (t1 == t)
		    {
                     root = t->lNode;
                     t1 = root;
			}
			else if (t1->lNode == t)
			{
            		t1->lNode = t->lNode;
			}
			else
			{
			t1->rNode = t->lNode;
			}
			t = NULL;
        free(t);
        return;
		}
    /* To delete node having right hand child */
    else if (t->lNode == NULL)
		{
                  if (t1 == t)
			{
		         root = t->rNode;
          		  t1 = root;
			}
       	        else if (t1->rNode == t)
                   t1->rNode = t->rNode;
                else
                   t1->lNode = t->rNode;
             t == NULL;
             free(t);
             return;
             }
    /* To delete node having two child */
    else if ((t->lNode != NULL) && (t->rNode != NULL))  
		{
	           t2 = root;
		    if (t->rNode != NULL)
			{
                          k = smallest(t->rNode);
                          flag = 1;
			}
			else
			{
                          k =largest(t->lNode);
                          flag = 2;
			}
                  deleteSearch(root, k);
                  t->info = k;
		}
	}
/* To find the smallest element in the right sub tree */
int smallest(struct bst *t)
	{
		t2 = t;
		if (t->lNode != NULL)
			{
			t2 = t;
			return(smallest(t->lNode));
			}
		else    
        return (t->info);
	}

 

/* To find the largest element in the left sub tree */
int largest(struct bst *t)
	{
	    if (t->rNode != NULL)
		{
        	 t2 = t;
       		 return(largest(t->rNode));
		}
	   else    
	       return(t->info);
	}
       
void inorder(struct bst *t)
	{
          if(root == NULL)
	   {
	    printf("\nSorry In BST there is no element::\n") ;
	    return;
	   }
	   if(t->lNode !=NULL)
	     inorder(t->lNode);
	  printf("%d ->",t->info);
	   if(t->rNode != NULL)
	    inorder(t->rNode);
     	}
void preorder(struct bst *t)
	{
	  if(root==NULL)
	   {
	    printf("\nSorry In BST there is no Element::\n") ;
	    return;
	   }
          printf("%d ->",t->info) ;
	  if(t->lNode !=NULL)
		preorder(t->lNode);
	  if(t->rNode !=NULL)
		preorder(t->rNode);
	}
void postorder(struct bst *t)
	{
	  if(root==NULL)
	   {
	    printf("\nsorry In BST there is no Element::\n") ;
	    return;
	   }
	  if(t->lNode !=NULL)
		postorder(t->lNode);
	  if(t->rNode !=NULL)
		postorder(t->rNode);
 	 printf("%d ->",t->info) ;
	}
int height(struct bst *t)
	{
	  int hL,hR;
	  if(!t)
	  return 0;
	  hL=height(t->lNode);
	  hR=height(t->lNode);
   	  if(hL>hR )
	  return hL+1;
	  else
	  return hR+1;
	}













