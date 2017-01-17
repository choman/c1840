/* Chad Homan
   $Author: ff006 $
   $Date: 1994/09/16 14:52:47 $
   $Source: /u/ff006/hw3/RCS/c3n36.c,v $
   $Revision: 1.2 $
   Matt Payne
   508-21-2554
   ff006@thor
   choman@s-cwis
*/

#include <stdio.h>

	main()
	{
	/* Intialization phase */
	int rem,num,dec = 0,base = 1,org;   
	/* Asks user for a binary number */
	printf("Enter in the binary number: ");
	scanf("%d", &num);
	printf("\n");
	/* sets org to equal num */
	org = num;
	printf("Rem  Num  Dec  Base\n");
	/* starts the while loop for right to left picking */
	while (num > 0){
		rem = num % 10;    /* rem is modulos of num by 10 */
		num = num / 10;    /* num is reset to num div 10 */
		dec = dec + ( rem * base );  /* dec = dec plus rem * base*/
		printf("%d    %d    %d     %d\n",rem,num,dec,base);
		base = base * 2; /* resets base to base times two */
		}
	printf("The Decimal equivalant of %d is %d\n", org, dec);
	return(0);
	}



