/* Chad Homan
   $Author: ff006 $
   $Date: 1994/09/16 14:52:51 $
   $Source: /u/ff006/hw3/RCS/c3n40.c,v $
   $Revision: 1.2 $
   Matt Payne
   508-21-2554
   ff006@thor
   choman@s-cwis
*/

#include <stdio.h>

	main()
	{
	int x = 1, count = 1; /* intializes x & count to equal one */
   	      while (count <= 8) { /* starts a while loop for lines */	
		if ((count%2) == 0)   /* sets condition for even lines */
			printf(" ");  /* prints a blank space before even line*/
          	while(x <= 8) {  /* starts while loop for colums */
		 printf("* "); /* prints a star and a space */
		 x++;         /* tells it to print it 8 times */
		 }            /* ends nested while loop for colums */
		 printf("\n"); /* prints a new line */
		 count += 1; /* adds one to count */
		 x = 1; /* resets x condition so new line can be printed */
		} /* ends oringinal while loop */
	return(0);  /* shows prog. ended successfully */
	} /* ends program */
