/* Chad Homan
   $Author: ff006 $
   $Date: 1994/11/07 17:45:17 $
   $Source: /u/ff006/hw9/RCS/c11n14.c,v $
   $Id: c11n14.c,v 1.7 1994/11/07 17:45:17 ff006 Exp $
   $Revision: 1.7 $
   Matt Payne
   CSCI-1840
   ff006@thor
   choman@corona or @s-cwis
*/

#include <stdio.h>
#include <strings.h>
#include <sys/stat.h>
#include <assert.h>

#define SS 256

void wordget( char [], const char *[]);

main(){   /* sets up map configuration */
	
	const char *map[] = {"",    /* 0 digit */
			  "",    /* 1 digit */
			  "abc", /* 2 digit */
		   	  "def", /* 3 digit */
		  	  "ghi", /* 4 digit */
			  "jkl", /* 5 digit */
			  "mno", /* 6 digit */
			  "prs", /* 7 digit */
			  "tuv", /* 8 digit */
			  "wxy", /* 9 digit */
			   NULL}; /* map config */
	char	wordstr[SS], *cp;
	char	digit[7] = {0};

  	printf("[H[J");  /*** Cleardscreen command ***/
	printf("Enter in a seven digit phone number\n");
	scanf("%s", &digit); /* scans phone# into mem */
  	printf("[H[J");  /*** Clearscreen command ***/
	wordget(digit, map);
	printf("Now comparing words with dictionary\n");
	wordcomp();
	printf("\n");
	printf("Done with process\n");
	printf("\n");
	return(0);
}

void wordget(char phone_number[7], const char *map[])

{
	FILE	*words; 
	int	a, b, c, d, e, f, g, i;
	
	if ((words = fopen("/u/ff006/hw9/words.dat", "w")) != NULL){
	for (a = 0; a < 3; a++) /* loops for 1 of 3 num on digit */
	  for (b = 0; b < 3; b++)
	    for (c = 0; c < 3; c++)
	      for (d = 0; d < 3; d++)
		for (e = 0; e < 3; e++)
		  for (f = 0; f < 3; f++){
		    for (g = 0; g < 3; g++){
			fprintf(words, "%c%c%c%c%c%c%c\n",
					map[phone_number[0] - 48][a],
					map[phone_number[1] - 48][b],
					map[phone_number[2] - 48][c],
					map[phone_number[3] - 48][d],
					map[phone_number[4] - 48][e],
					map[phone_number[5] - 48][f],
					map[phone_number[6] - 48][g]);
			}} /* for g */
		fclose(words);
		}/* if */
	}/* wordget */

int wordcomp()

{
	FILE *dict = NULL;
	FILE *words = NULL;
	char phone_words[SS];
	char actual_wrds[SS];

	words = fopen("/u/ff006/hw9/words.dat", "r");
	dict = fopen("/usr/share/dict/words", "r");
	assert(dict); assert(words);
	while(!feof(dict)){ 			/* gets words from dictionary */
	fgets(actual_wrds, SS-1, dict);          /* puts dict word into array */
	actual_wrds[strlen(actual_wrds) - 1] = '\0'; /* kills \n fgets leaves */
	if ((strlen(actual_wrds) > 1) && (strlen(actual_wrds) <= 7))
		while(!feof(words)){              /* gets words from dat file */
		fgets(phone_words, SS-1, words);/* puts phone word into array */
		phone_words[strlen(phone_words) - 1] = '\0';    /* removes \n */
		if (strstr(phone_words, actual_wrds) != NULL){
		printf("Word found in phone number : %s\n", actual_wrds); break;
		} /* if strstr */
	} /* while feof words */
	rewind(words);  /* resets fileptr words */
	} /* while feof dict */
	fclose(words);
	fclose(dict);
	return(0);
} /* wordcomp */

