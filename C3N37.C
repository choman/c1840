/* Chad Homan
   $Author: ff006 $
   $Date: 1994/09/16 14:52:50 $
   $Source: /u/ff006/hw3/RCS/c3n37.c,v $
   $Revision: 1.2 $
   Matt Payne, Instructor
   508-21-2554
   ff006@thor
   choman@s-cwis
*/

#include <stdio.h>

	main()
	{
	int x = 1;    /* initializes & declares x to equal one */
	while (x <= 3000000){  /* starts while loop with condition for x */
	x = x + 1;             /*  continues to add one to x until 3000000 */
	     if (x == 1000000){     /* when x equals 1000000 print next line*/
		printf("x = %d\n", x); /* prints a line containing 1000000 */
		}
	     if (x == 2000000){     /* when x equals 2000000 print next line*/
		printf("x = %d\n", x); /* prints a line containing 2000000*/
		}
	     if (x == 3000000){  /* when x equals 3000000 print next line*/
		printf("x = %d\n", x); /* prints line 3000000 */
		}
	}  /* ends while loop */
	return (0); /* returns zero for successful run */
	} /* ends program */
