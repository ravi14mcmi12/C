#include<stdio.h>
#include<stdlib.h>
int s[10];

typedef struct tnode
	{
	 int info;
 	 struct tnode *l;
	 struct tnode *r;
	} node;

node *root;

typedef struct stack
	{
 	  node *st;
	  struct stack *next;
	} stack;

 stack *top=NULL;

stack push(node *tp)
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

void create()
{
 int n,i;
 node *new, *ptr, *pptr;
 printf("\n Enter no of node :");
 scanf("%d",&n);
 printf("\n Enter %d value :",n);

 root=(node*) malloc(sizeof(node));

 root->l=root->r=NULL;
 scanf("%d",&root->info);

 for(i=2;i<=n;i++)
 {
  new=(node*)malloc(sizeof(node));
  new->l=new->r=NULL;
  scanf("%d",&new->info);
  ptr=root;
  while(ptr!=NULL)
  {
   pptr=ptr;
   if(new->info < ptr->info)
   {
    ptr=ptr->l;
    if(ptr==NULL)
    pptr->l=new;
   }
   else
   {
    ptr=ptr->r;
    if(ptr==NULL)
    pptr->r=new;
   }
  }
 }
}
void inorder(node *t)
{
	int f =1;
	while(f!=0)
	{	while(t!=NULL)
		{
			push(t);
			t = t->l;
		}
		if(top!=NULL)
		{
			t = pop();
			printf("%d  ",t->info);
			t = t->r;
		}
		else
			f=0;
	}
}
void preorder(node *e)
{
	int f=1;
	while(f!=0)
	{
		while(e!=NULL)
		{
			printf("%d  ",e->info);
			push(e);
			e = e->l;
		}
		if(top!=NULL)
		{
			e = pop();
			e = e->r;
		}
		else
			f=0;
	}
}
void postorder(node *p)
{
	int x = 0;
	push(p);
	while(top!=NULL)
	{
		p=pop();
		if(p->l!=NULL)
			push(p->l);
		if(p->r!=NULL)
			push(p->r);
		s[x] = p->info;
		++x;
	}
	while(x>0)
	{
		printf("%d  ",s[x-1]);
		--x;
	}

}
int main()
{
 create();
 printf("\n Inorder \n");
 inorder(root);
 printf("\n Preorder \n");
 preorder(root);
 printf("\n Postorder \n");
 postorder(root);
  return 0;

}
