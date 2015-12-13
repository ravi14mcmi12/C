#include<stdio.h>
#include<stdlib.h>

typedef struct node
       {
        int data;
        struct node *next;
       }node;

typedef struct stack
	{
	  node *top;
	  int size;
	}stack;
 
stack initStack()
	{
          stack st;
	  st.top=NULL;
	  st.size=0;
	  return st;
	}
void pushStack(stack *st,int ch)
	{
	 node *temp=(node*)malloc(sizeof(node));
	 temp->data=ch;
	 temp->next=st->top;
	 st->top=temp;
	 st->size +=1;
	}
int popStack(stack*st)
	{
	 node *temp=st->top;
	 char ch;
	 ch=temp->data;
	 st->top=temp->next;
	 free(temp);
	 st->size -=1;
	 return ch;
	}

void show(stack *st,int n)
 	{
         node *temp=st->top;
	 int i;
	 if(temp !=NULL)
          {		 
	   for(i=0;i<2*(n - st->size);i++)
	      {                                                                                   
		      printf(" ");
	      }
	  }
	 else
         {
            for(i=0;i<(2*(n - st->size)) -1;i++)
              {
		printf(" "); 
	      }
	    printf("|");
          }
	 while(temp !=NULL)
              {
		 printf(" %d",temp->data);
		 temp=temp->next;
	      }
	 printf("\n");
	}
int main()
 {
	 int i,j,from,to,n;
	 char ch;

	 stack st1=initStack();
	 stack st2=initStack();
	 stack st3=initStack();

	 scanf("%d",&n);
         
	 for(i=n;i>=1;i--)
          {
		 pushStack(&st1,i);
	  }
          
	  show(&st1,n);
	  show(&st2,n);
	  show(&st3,n); 

	 printf("------\n");
         
          for(i=1;i<(1<<n);i++)
	   {		  
	   from=( i & i-1 ) % 3 + 1;
	   to=(( i | i-1) +1) % 3 +1;

	  printf("Disk moving from %d to %d:\n",from,to);

	   switch(from)
		  {
	              case 1:j=popStack(&st1);
		      break;
	
		      case 2:j=popStack(&st2);
		      break;
	              
		      case 3:j=popStack(&st3);
		      break;
                  }

	   switch(to)
                  {
	              case 1:pushStack(&st1,j);
		      break;

                      case 2:pushStack(&st2,j);
		      break;

                      case 3:pushStack(&st3,j);
	              break;
		   }
	       show(&st1,n);
	       show(&st2,n);
	       show(&st3,n);

	     //  printf("Disk moving From %d to %d:\n",from,j);
	       printf("------\n");
	   } 
 }

