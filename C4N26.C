/* Chad Homan
   $Author: ff006 $
   $Date: 1994/09/16 15:06:12 $
   $Revision: 1.8 $
   508-21-2554
   ff006@thor
   choman@s-cwis
   for the amazing Matt Payne
	test on make
*/

#include <stdio.h>

	main()
	{
	double a = 0, terms, count, sum; /* intializes a,count,sum as doubles */
	sum = 0;
	count = 1;
	terms = 0; 	
	printf("");
	printf("At Term      PI equals approx.\n");
	printf("-------      -----------------\n");
	/* start of while loop... loops approx 400,000 times */
	while (count <= 753700){
			/* basic equation for pi */ 
			a = (4 / count) - (4 / (count + 2));
			/* accumolator for PI Number */
			sum = sum + a;
				/* if statement to produce Pi numbers */
			if (sum > 3.139999991 && sum < 3.1400040060001)
			    printf("%1.0f          %1.10f\n", terms, sum);
			if (sum > 3.1409999999 && sum < 3.14100031)
			    printf("%1.0f         %1.10f\n", terms, sum);
			if (sum > 3.14149999999  &&  sum < 3.14150000991)
			    printf("%1.0f        %1.10f\n", terms, sum);
			if (sum > 3.14159000001 && sum < 3.141590000110001)
			    printf("%1.0f       %1.10f\n", terms, sum);
			count += 4;  /* adds 4 to count for next loop */
			terms += 2;  /* adds 1 to interations of loop */
			}
	return(0);
	}


