/* Chad Homan
   $Author: ff006 $
   $Date: 1994/11/30 16:22:26 $
   $Source: /u/ff006/hw11/RCS/c14n4.c,v $
   $Id: c14n4.c,v 1.11 1994/11/30 16:22:26 ff006 Exp ff006 $
   $Revision: 1.11 $
   Matt Payne
   CSCI-1840
   ff006@thor
   choman@corona or @s-cwis or @ccsn.edu
*/

/* Using Command-line arguments */
/* This program sorts an array of integers into ascending or descending order.
   The program uses the command-line arguements to pass either -a for ascending
   or -d for descending.
*/


#include <stdio.h>
#include <string.h>
#define SS 256

void bubblesort(int *, int);
void debubblesort(int *, int);
void swap(int *, int *);

main(int argc, char *argv[])
{
    int i, x, tot_numbers;
    int numbers[SS] = {0};

    printf("[H[J");  /*** Clearscreen command ***/
/*    
    if (((strcmp(argv[1],"-a")) || (strcmp(argv[1],"-d"))) != 0)
	printf("Usage : command <-a or -d> numbers...\n");
    else
*/
	/* reads everything from argv[2] to end of array into a numbers array*/
	for (i = 2; argv[i]; i++){ 	
		printf("argv[%d]=\"%s\"\n", i, argv[i]);
		numbers[i - 2] = atoi(argv[i]);
		printf("Num array[%d] >>> %d\n", i - 2, numbers[i - 2]);
		printf("\n");
		}
	tot_numbers = argc - 2;  /* sets tot_numbers to equal the arg count */

 /* check flag in argv[1] if -a goto ascending bubblesort if -d goto descending bubblesort */
	if (strcmp(argv[1],"-a") == 0)   
		bubblesort(numbers, tot_numbers); 
	if (strcmp(argv[1],"-d") == 0)
		debubblesort(numbers, tot_numbers); 
  	printf("[H[J");  /*** Clearscreen command ***/
	printf("\nThe total number of numbers sorted is : %d\n", tot_numbers);
	printf("The sorted array of numbers is :\n");
	for (x = 0; x < tot_numbers; x++)
	    printf("Numbers[%d] >>> %d\n", x, numbers[x]);
	return 0;
} /* main */

/* Bubblesorts check for which number is greater and switches there slots depending upon which 
   flag was used
*/
void bubblesort(int *array, int size)
{
	int pass, j;
	void swap(int *, int *);
	
	for (pass = 0; pass < size; pass++)
		for (j = 0; j < size - 1; j++)
		   if (array[j] > array[j + 1])
			swap(&array[j], &array[j + 1]);
} /* bubblesort function */

void debubblesort(int *array, int size)
{
	int pass, j;
	void swap(int *, int *);
	
	for (pass = 0; pass < size; pass++)
		for (j = 0; j < size - 1; j++)
		   if (array[j] < array[j + 1])
			swap(&array[j], &array[j + 1]);

} /* descending bubblesort function */

void swap(int *element1Ptr, int *element2Ptr)
{
	int temp = 0;

	temp = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = temp;
} /* swap function */ 



