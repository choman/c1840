
/* Chad Homan
   $Author: ff006 $
   $Date: 1994/11/30 17:54:46 $
   $Source: /u/ff006/hw11/RCS/c14n6.c,v $
   $Id: c14n6.c,v 1.6 1994/11/30 17:54:46 ff006 Exp $
   $Revision: 1.6 $
   Matt Payne
   CSCI-1840
   ff006@thor
   choman@corona or @s-cwis or @ccsn.edu
*/

/* Using signal handling */
/* This program uses the signal header library to recognize
   the standard signal of SIGABRT and SIGINT. This program 
   should test the trapping of these signals by calling function
   abort to generate a signal of type SIGABRT, and by typing
   <ctrl> c to generate a signal of type SIGINT.
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void signal_cancel(int);
void signal_handler(int);

main()
{
   int i, x;
 
   signal(SIGABRT, signal_cancel);
   signal(SIGINT, signal_handler);
   srand(clock());
   
  printf("[H[J");  /*** Clearscreen command ***/
   for (i = 1; i <= 10000; i++) {
      x = 1 + rand() % 50;
      
      if (x == 50)        /* if fifty then raise SIGABRT */
         raise(SIGABRT);
         
      printf("%4d", i);
      
      if (i % 10 == 0)
         printf("\n");
   }

   return 0;
} /* main */

/* if a SIGINT or SIGABRT then one of these two functions are used to ask the 
   user if they would like to continue
*/

void signal_handler(int signalValue)
{
   int response;
   
   printf("%s%d%s\n%s",
          "\nInterrupt signal (", signalValue, ") received.",
          "Do you wish to continue (1 = yes or 2 = no)? ");
   
   scanf("%d", &response);
   
   while (response != 1 && response != 2) {
      printf("(1 = yes or 2 = no)? ");
      scanf("%d", &response);
   }
   
   if (response == 1)
      signal(SIGINT, signal_handler);
   else
      exit(EXIT_SUCCESS);
} /* signal_handler */

void signal_cancel(int signal_cancelValue)
{
   int other_response;
   
   printf("%s%d%s\n%s",
          "\nInterrupt signal (", signal_cancelValue, ") received.",
          "Do you wish to continue (1 = yes or 2 = no)? ");
   
   scanf("%d", &other_response);
   
   while (other_response != 1 && other_response != 2) {
      printf("(1 = yes or 2 = no)? ");
      scanf("%d", &other_response);
   }
   
   if (other_response == 1)
      signal(SIGABRT, signal_handler);
   else
      exit(EXIT_SUCCESS);
}/* signal_cancel */
