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

void show(stack *st1,stack *st2,stack *st3,int n)
 	{
	 int i,l1,l2,l3;
         node *temp1=st1->top;
	 node *temp2=st2->top;
	 node *temp3=st3->top;
	  

	 l1=st1->size;
	 l2=st2->size;
	 l3=st3->size;
		printf("\n%s %s %s","TOWER1","TOWER2","Tower3\n");
	 for(i=0;i<n;i++)
	  {
           if(n-l1-i>0)
	     printf("%8s"," ");
	      else if(temp1 !=NULL)
		     {
		      printf("%d%t",temp1->data);
		      temp1=temp1->next;
		     }
	    if(n-l2-i>0)
	          printf("%8s"," ");
	      else if(temp2 !=NULL)
	            { 
                      printf("%d%t",temp2->data);
		      temp2=temp2->next;
		    }
	     if(n-l3-i>0)
		 printf("%8s"," ");
	        else if(temp3 !=NULL)
		   {
		     printf("%d%t",temp3->data);
		     temp3=temp3->next;

		   }

		printf("\n");
	  }
		 
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
          
	  show(&st1,&st2,&st3,n);
	   

	 printf("------\n");
         
          for(i=1;i<(1<<n);i++)
	   {		  
	   from=( i & i-1 ) % 3 + 1;
	   to=(( i | i-1) +1) % 3 +1;

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
	       show(&st1,&st2,&st3,n);
	       

	   } 
 }

