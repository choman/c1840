/* Chad Homan
   $Author: ff006 $
   $Date: 1994/11/09 22:35:35 $
   $Source: /u/ff006/hw4/RCS/c5n39.c,v $
   $Revision: 1.5 $
    ff006@thor
   choman@s-cwis
coll   The one & only Matt Payne

	The Towers of Hanoi problem
*/

/* #include <hanoi.h> ...... I wish!!! */

int move(int, int, int, int); /* function proto */

#include <stdio.h>

	main()
	{
	int num; 
	printf("Enter number of disks to solve: ");
	scanf("%d*c\n", &num); /* scan # of disc user wants to solve for*/ 
	move(num,1,3,2); /* calls function called move */
	}	

	/* Function for MOVE command */

	int move(int num, int old_src, int old_dest, int old_tmp)
	{
	if (num < 1)     /* flag for zero discs */
		return(0);
	move((num-1), old_src, old_tmp, old_dest); /* left move */
	printf("%d --> %d\n", old_src, old_dest);  /* prints move */
	move((num-1), old_tmp, old_dest, old_src); /* right move */
	return(0);
	}



		

