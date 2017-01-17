/* Chad Homan
   508-21-2554
   ff006@thor.unomaha.edu
   choman@s-cwis
   program 1 for csci-1840
   for the almighty Matt Payne
   
   this program is a valid attempt
   add, multiply and average 3 integers
*/
#include <stdio.h>

main ()

{
int x,y,z,sum=0,  /* sets vaiables x,y,z & sum and initializes sum */
         prod=0,  /* sets & initializes prod variable */
         ave=0,   /* sets & initializes ave variable */
         high=0,  /* sets & initializes high variable */
         low=0,   /* initializes & sets low variable */
       max,min;     /* sets max & min variables */
printf("Please enter three integers\n");
scanf("%d", &x); /* scans for integers and places them in x,y,&x */
     max = x;    /* sets max equal to x */ 
     min = x;    /* sets min equal to x */
scanf("%d", &y);
     if (y > max)
        max = y; /* sets new max if y is larger than max */
     if (min > y)
        min = y; /* sets new min if y is smaller than min */
scanf("%d", &z);
     if (z > max)
        max = z; /* sets mew max if z is larger than max */
     if (min > z)
        min = z; /* sets new min if z is smaller than min */ 
sum = x + y + z;  /* totals three integers */ 
prod = x * y *z;  /* multiplies three integers */
ave = sum/3;      /* averages three integers */
printf("The sum is %d\n", sum); /* displays results for next 3 lines*/
printf("The product is %d\n", prod);
printf("The average is %d\n", ave);
printf("The high is %d\nand the low is %d\n", max,min);
return(0); /* shows that the program ended successfully */
}
