
/* Chad Homan
   $Author: ff006 $
   $Date: 1994/11/30 05:13:11 $
   $Source: /u/ff006/hw11/RCS/c14n8.c,v $
   $Id: c14n8.c,v 1.6 1994/11/30 05:13:11 ff006 Exp ff006 $
   $Revision: 1.6 $
   Matt Payne
   CSCI-1840
   ff006@thor
   choman@corona or @s-cwis or @ccsn.edu
*/

/* Using command-line arguments */
/* This program takes two command-line arguments that are file names,
   reads the characters the the first file one at a time, and writes
   the charaters in reverse order to the second file.
*/


#include <stdio.h>

main(int argc, char *argv[])
{
   FILE *inFilePtr, *outFilePtr;
   int c;

   printf("[H[J");  /*** Clearscreen command ***/
   if (argc != 3)
      printf("Usage: flip infile outfile\n");
   else
     
      if ((inFilePtr = fopen(argv[1], "r")) != NULL)  /* gets names from command line */
         if ((outFilePtr = fopen(argv[2], "w")) != NULL){
	    fseek(inFilePtr, -1, SEEK_END); /* seeks for last item in the infile */
	    while(1){
	       c = fgetc(inFilePtr);   /* gets last item and sets it in temp slot c */
               fputc(c, outFilePtr);   /* writes c to outfile */
	       if (fseek(inFilePtr, -2, SEEK_CUR)) /* seeks next to last character */
			break;
	    }/* while */
	   printf("\n");
	  } /* if ourfile */

         else
            printf("File \"%s\" could not be opened\n", argv[2]); 

      else
         printf("File \"%s\" could not be opened\n", argv[1]);
    printf("\n");
   return 0;
}

