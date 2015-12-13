/*  This program approximates the integral e^(-x^2/2) from 0 to 1 by using Monte Carlo integration.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dran(u1)   \
                    ( (rand()/(double) \
                         RAND_MAX)*(u1))
#define Prompt(p)  printf(p)
#define Response(r)  \
             scanf("%d", &r)
#define Answer(a) \
  printf("Integral = %f\n", a)

double area(int);

 int main()
{
   int resp, trials;

   do {
    Prompt("\n\nRun again"
       "(1 = Yes, 0 = No)? ");
      Response(resp);
      if (resp) {
       Prompt(
         "How many trials? ");
       Response(trials);
       Answer( area(trials) );
      }
   } while(resp);
   return EXIT_SUCCESS;
}
double area(int trials)
{
   double x, y,z;
   int k, hit;

   hit = 0;
   for(k=0; k<trials; k++) {
      x = dran(1.0);
      y = dran(1.0);
      z=-(x*x)/2;
      if (y <= exp(z) )
         hit++;
   }
   return (double) hit/trials;
}
