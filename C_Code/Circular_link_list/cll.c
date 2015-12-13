#include<stdio.h>
#include<stdlib.h>

typedef struct circularlinklist
	{
	 int info;
	 struct circularlinklist *next;
	}cl;
	
cl *head=NULL;

void display(cl *t);
void insertNode();
int survivor(cl *t,int skip);

void display(cl *t)
	{
		if(t==NULL)
		  printf("\nNo Element::");
	   if(t==head)
	     {
		  printf("%d  ",head->info);
		  t=head->next;
	     }
          while(t!=head)
	     {
		   printf("%d  ",t->info);
		   t=t->next;
	     }
	}

void insertNode()
	{
	   int n;
	 cl *temp,*p=NULL;
	 //head=(cl*)malloc(sizeof(cl));
	// head->next=NULL;
	 printf("\nEnter the total number of node :");
	 scanf("%d",&n);
	 printf("Enter the value for Node:");
	
	 while(n>0)
		{
	       	   temp=(cl*)malloc(sizeof(cl));
		   if(temp==NULL)
		    {
			printf("Insufficent Memory:");
			exit(0);
		    }
		   scanf("%d",&temp->info);
		   temp->next=NULL;
		   if(head==NULL)
		    {
		      head=temp;
		      temp->next=head;//making circular
		      p=temp;//take reference to insert next element.
		     // p->next=head;
		    }
	           else
		    {
			  p->next=temp;//Inserting at the tail
			  p=temp;
		    }
		 p->next=head;//making circular
	     n=n-1; 
		}
		
	}
	
int survivor(cl *head, int k)
	{
	   cl *p, *q;
	   int i;
	   q= p = head;
	 while (p->next != p)
          {
             for (i = 0; i < k - 1; i++)
              {
               q = p;
               p = p->next;
              }
              q->next = p->next;
              printf("%d has been Remove\n", p->info);
             free(p);
             p = q->next;
          }
      head = p;
      return (p->info);
    }
int main()
	{
	  int opt,skip,survive;
	  char ch='y';

	  do	
	   {
         
	    printf("\n1.To insert element in Circular Link List:\n") ;
            printf("\n2.Display List:\n") ;
	    printf("\n3.To Find Survivor:\n") ;
            printf("\nEnter your Choice......................::") ;
            scanf("%d",&opt) ;

	    switch(opt)
	  	{
		  case 1:insertNode();
			     break;

		  case 2:
			  display(head);
              		  break;

	 	  case 3:
               		 printf("Enter the number of persons to be skipped: ");
			 scanf("%d", &skip);
			 survive = survivor(head, skip);
		         printf("The person to survive is : %d\n", survive);
			 free(head);
                 	 break;

		  default:printf("\n Hello you Entered wrong Choice ..\n") ;
                        
		}printf("\nDo you want to continue ?? [y/n]:") ;
		 scanf("\n%c",&ch) ;
	   }while(ch == 'y' || ch == 'Y');
	 return 0;
	}
