/* Chad Homan
   $Author: ff006 $
   $Date: 1994/11/06 21:06:12 $
   $Source: /u/ff006/hw9/RCS/c11n13.c,v $
   $Id: c11n13.c,v 1.54 1994/11/06 21:06:12 ff006 Exp $
   $Revision: 1.54 $
   Matt Payne
   CSCI-1840
   ff006@thor
   choman@corona or @s-cwis
*/

#include <stdio.h>
#include <strings.h>
#include <sys/stat.h>

void wordget( char [], const char *[]);

main(){   /* sets up map configuration */
	const char *map[] = {"",    /* 0 digit */
			  "",    /* 1 digit */
			  "ABC", /* 2 digit */
		   	  "DEF", /* 3 digit */
		  	  "GHI", /* 4 digit */
			  "JKL", /* 5 digit */
			  "MNO", /* 6 digit */
			  "PRS", /* 7 digit */
			  "TUV", /* 8 digit */
			  "WXY", /* 9 digit */
			   NULL}; /* map config */
	char	digit[7] = {0};

  	printf("[H[J");  /*** Clearscreen command ***/
	printf("Enter in a seven digit phone number\n");
	scanf("%s", &digit); /* scans phone# into mem */
  	printf("[H[J");  /*** Clearscreen command ***/
 	wordget(digit, map);
	return(0);
}/* main */

void wordget( char phone_number[7], const char *map[])

{
	int	a, b, c, d, e, f, g, i;

 	for (a = 0; a < 3; a++) /* loops for 1 of 3 num on digit */
	  for (b = 0; b < 3; b++)
	    for (c = 0; c < 3; c++)
	      for (d = 0; d < 3; d++)
		for (e = 0; e < 3; e++)
		  for (f = 0; f < 3; f++){
		    for (g = 0; g < 3; g++){
			printf("%c%c%c%c%c%c%c\t\t",
					map[phone_number[0] - 48][a],
					map[phone_number[1] - 48][b],
					map[phone_number[2] - 48][c],
					map[phone_number[3] - 48][d],
					map[phone_number[4] - 48][e],
					map[phone_number[5] - 48][f],
					map[phone_number[6] - 48][g]);
			} /* for g */
		printf("\n");} /* for f */
}/* wordget */
