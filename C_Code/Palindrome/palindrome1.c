#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	   char data ;
	   struct node *next ;
} node ;

typedef struct stack{
	             node *top ;
	             int size ;
                    } stack ;

stack stackInit() {
	           stack st ;
	           st.top = NULL ;
	           st.size = 0 ;
	           return st ;
                  }

void stackPush(stack *st, char c) {
	                            node *ptr = (node*)malloc(sizeof(node)) ;
	                            ptr->data = c ;
	                            ptr->next = st->top ;
	                            st->size += 1;
	                            st->top = ptr ;
                                 }

char stackPop(stack *st) {
	                   char ch = ' ' ;
	                   node *temp ;
	                   if(st->size)
			   {
	                   temp = st->top->next ;
	                   ch   = st->top->data ;
	                   free(st->top) ;
	                   st->top = temp ;
	                   st->size -= 1 ;
	                } else
		       	{
	                 printf("\nStack is empty!") ;
	                 }
	    return ch ;
}

typedef struct queue {
	              node *front ;
	              node *rear ;
	              int size ;
                     } queue ;
queue queueInit() {
	           queue qu ;
	           qu.front = NULL ;
	           qu.rear  = NULL ;
	           qu.size  = 0 ;
	           return qu ;
                 }

void queueInsert(queue *qu, char c) {
	                              node *ptr = (node*)malloc(sizeof(node)) ;
		                      ptr->data = c ;
			              ptr->next = NULL ;
				       if(qu->front == NULL && qu->rear == NULL)
				       {
				          qu->front = qu->rear = ptr ;
				        } else {
				           qu->rear = qu->rear->next = ptr ;
				        }
				        qu->size += 1 ;
                                     }

char queueDelete(queue *qu) {
	                     char ch = ' ' ;
	                     node *temp ;
	                     if(qu->front == NULL && qu->rear == NULL) 
	                	{
	                          printf("\nQueue is empty!") ;
	                        } else
	                        {
	                          ch = qu->front->data ;
	                          temp = qu->front ;
	                          if(qu->front == qu->rear)
				  {
	                            qu->front = qu->rear = NULL ;
	                            }
				  else
				  {
	                           qu->front = qu->front->next ;
	           }
	             qu->size -= 1 ;
	         free(temp) ;
	        }
	        return ch ;
}

int checkPalindromeStackQueue() {
	                         char ch ;
	                         stack st = stackInit() ;
	                         queue qt = queueInit() ;
                                 while((ch = getchar()) != '\n')
				 {
                                 stackPush(&st, ch) ;
                                 queueInsert(&qt, ch) ;
                                 }
         while(st.size) {
              if(stackPop(&st) != queueDelete(&qt)) {
              return 0 ;
           }
	      return 1;
         }
}
 int checkPalindromeStack()
                {
	            char ch ;
	             stack st1 = stackInit() ;
	             stack st2 = stackInit() ;
	             stack st3 = stackInit() ;
	             while((ch = getchar()) != '\n') {
                     stackPush(&st1, ch) ;
                     stackPush(&st2, ch) ;
               }
          while(st2.size) {
                         stackPush(&st3, stackPop(&st2)) ;
	                  }
	         while(st1.size) {
              if(stackPop(&st1) != stackPop(&st3)) {
               return 0 ;
                 }
          }
        return 1 ;
	 }

 int main() {
              int ch ;
              char x = 'y' ;
        do {
                  printf("\nProgram To Check Palindrome...") ;
                  printf("\n1. Using Three Stacks") ;
                  printf("\n2. Using a Stack and a Queue") ;
                  printf("\n\nEnter your choice [1-2]: and then String ") ;
                  scanf("%d\n", &ch) ;
                     switch(ch) {
	                     case 1: if(checkPalindromeStack())
		                   {
		                     printf("It's a Palindrome!") ;
			            }
                               else {
                                     printf("Sorry It's Not a Palindrome!") ;
                                    }
                                break ;
                         case 2: if(checkPalindromeStackQueue()) {
	 	                                        printf("It's a Palindrome!") ;
	                                       }
				 else {
	                                printf("Sorry it's Not a Palindrome!") ;
	                                }
                                break ;
                        default: printf("\nInvalid choice!\n") ;
 
                }
                printf("\nDo you want to continue y/n] ?") ;
                scanf("%c", &x) ;
        }while(x == 'y' || x == 'Y') ;
        return 0 ;
}
	       	              

	 
	

