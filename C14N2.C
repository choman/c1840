/* Chad Homan
   $Author: ff006 $
   $Date: 1994/11/30 05:12:35 $
   $Source: /u/ff006/hw11/RCS/c14n2.c,v $
   $Id: c14n2.c,v 1.6 1994/11/30 05:12:35 ff006 Exp ff006 $
   $Revision: 1.6 $
   Matt Payne
   CSCI-1840
   ff006@thor
   choman@corona or @s-cwis or @ccsn.edu
*/

/* Using variable-length argument lists ...this program calculates
   the product of a series of integers that are passed to the function
   product.
*/

#include <stdio.h>
#include <stdarg.h>

double product(int, ...);    /* function prototype */

main()
{
   double w = 37.5, x = 22.5, y = 1.7, z = 10.2;

   printf("[H[J");  /*** Clearscreen command ***/
   printf("%s%.1f\n%s%.1f\n%s%.1f\n%s%.1f\n\n",
          "w = ", w, "x = ", x, "y = ", y, "z = ", z);
   printf("%s%.3f\n%s%.3f\n%s%.3f\n",
          "The product of w and x is ",
          product(2, w, x),
          "The procuct of w, x, and y is ",
          product(3, w, x, y),
          "The product of w, x, y, and z is ",
          product(4, w, x, y, z));
  printf("\n");
  return 0;
}


double product(int i, ...)
{
   double total = 1;                         /* sets total to 1 because we are mutiplying */
   int j;
   va_list ap;                                         /* sets va_list var */

   va_start(ap, i);                                 /* starts computation */

   for (j = 1; j <= i; j++)                         
      total *= va_arg(ap, double);                  /* multiplys va_arg(ap, double) which is */
                                                   /* integers to be multipied */
   va_end(ap);
   return total;
}

