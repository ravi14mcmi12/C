/*  This program approximates the integral e^(-x^2/2) from 0 to 1 by using Monte Carlo integration.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dran(u1)   \
                    ( (rand()/(double) \
                         RAND_MAX)*(u1))

#define Answer(a) \
  printf("Integral = %f\n", a)

double area(int);

 int main()
{
   int resp, trials;

   do {
       printf("\n\nRun again(1 = Yes, 0 = No)? ");
      scanf("%d",&resp);
      if (resp) {
       printf("How many trials? :");
       scanf("%d",&trials);
       printf("The value of function is:%f",area(trials));
      }
   } while(resp);
   return 0;
}
double area(int trials)
{
   double x, y,z;
   int k, hit;

   hit = 0;
   for(k=0; k<trials; k++) {
      x = dran(1.0);
      y = dran(2.0);
      z=x*x*x;
      if (y <= (z) )
         hit++;
   }
   return (double) hit/trials;
}
