
/* Chad Homan
   $Author: ff006 $
   $Date: 1994/10/07 00:22:36 $
   $Source$
   $Revision$
   Matt Payne
   CSCI-1840
   ff006@thor
   choman@s-cwis
*/

/* Card dealing program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function prototypes */

void shuffle(int [][13]);
int deal(const int [][13], const char *[], const char *[]);
int deal2(const int [][13], const char *[], const char *[]);
int drop_card(const int [][13], const char *[], const char *[], int[], int[]);
int count(int[],int[]); 
int pair1( int[]);
int pair2( int[]);
int kind3( int[]);
int kind4( int[]);
int flush( int[]);
int strait( int[]);
int strait_flush( int[], int[]);
int royal_flush( int[],  int[]);
void caset(int);
void winner(int,int);

main()
{
   const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
   const char *face[13] = {"Ace", "Two", "Three", "Four",
                     "Five", "Six", "Seven", "Eight",
                     "Nine", "Ten", "Jack", "Queen", "King"};
   int deck[4][13] = {0};
   int tmp1 = 0, tmp2 = 0;

   srand(time(NULL));

   printf("\n");
   shuffle(deck);
   tmp1 = deal(deck, face, suit);
   tmp2 = deal2(deck, face, suit);
   winner(tmp1, tmp2);
   return(0);
  }

void winner(int play, int deal)

{ 

   if (play == deal)
	printf("It's a DRAW, NO winner\n");
   if (play > deal)
	printf("You beat the dealer, DIE!\n");
   if (play < deal)
	printf("The dealer wins, YOU LOSER!\n"); 
   printf("\n");

}

void shuffle(int wDeck[][13])
{
   int card, row, column;

   for(card = 1; card <= 52; card++) {
      row = rand() % 4;
      column = rand() % 13;

      while(wDeck[row][column] != 0) {
         row = rand() % 4;
         column = rand() % 13;
      }

      wDeck[row][column] = card;
   }
}

int deal(const int wDeck[][13], const char *wFace[],
          const char *wSuit[])
{
   int tmp1 = 0, handtype = 0, card, row, column;
   int tot_valu[13] = {0};
   int tot_suit[4] = {0};

  for (card = 1; card <= 5; card++)
     for (row = 0; row <= 3; row++)
         for (column = 0; column <= 12; column++)
            if (wDeck[row][column] == card){ 
               printf("%5s of %-8s%c\n",
                      wFace[column], wSuit[row],
		      card%5 == 0 ? '\n' : '\t');
			tot_valu[column]++;
			tot_suit[row]++;
		}
		tmp1 = count(tot_valu,tot_suit);
		caset(tmp1); 
		return(tmp1);
}


int deal2(const int wDeck[][13], const char *wFace[],
          const char *wSuit[])
{
   int tot_valu[13] = {0};
   int tot_suit[4] = {0};
   int tmp2 = 0, tmp3 = 0,  x, handtype = 0, card, row, column;

  for (card = 6; card <= 10; card++)
     for (row = 0; row <= 3; row++)
         for (column = 0; column <= 12; column++)
            if (wDeck[row][column] == card){
               printf("%5s of %-8s%c\n",
                      wFace[column], wSuit[row],
		      card%5 == 0 ? '\n' : '\t');
			tot_valu[column]++;
			tot_suit[row]++;
		}
			tmp2 = count(tot_valu,tot_suit);
			caset(tmp2);
			printf("I am going to drop_card\n");
   			tmp3 = drop_card(wDeck,wFace,wSuit, tot_valu, tot_suit);
			caset(tmp3);
			return(tmp3);
	}
		
int count(int tot_value[],int tot_suit[]) 
{
	int row, column, handtype = 0, tmp = 0;
		
		printf("Iam in count");
		handtype += pair1(tot_value);
		handtype += pair2(tot_value);
		handtype += kind3(tot_value);
		handtype += kind4(tot_value);
 		handtype += flush(tot_suit);
		handtype += strait(tot_value);
		handtype += strait_flush(tot_value,tot_suit);
		handtype += royal_flush(tot_value,tot_suit);
		tmp = handtype;
		printf("i am leaving count");
		return(tmp);
}
int drop_card (const int wDeck[][13], const char *wFace[],
          const char *wSuit[], int tot_val[], int tot_sut[])
{
	int hand[5] = {6,7,8,9,10};
	int number_to_drop=0, drop_card = 0, card, tmp = 0;
	int x, col, row, nrow, ncol, next_card = 11;

printf(" hi i am in drop card\n");	
	number_to_drop = rand()%3;
  for (card = 0; card <= number_to_drop; card++){
	drop_card = rand() %4;
     for (row = 0; row <= 3; row++)
         for (col = 0; col <= 12; col++)
          if (wDeck[row][col] == hand[drop_card]){
	   for (x = 1; x < drop_card; x++){
		tot_val[col]--;
		tot_sut[row]--;
		printf(" HI i just did the decrement\n");
			/* starts replace card loop */
     		for (row = 0; row <= 3; row++)
         		for (col = 0; col <= 12; col++)
         		 if (wDeck[nrow][ncol] == next_card){
		 		tmp = wDeck[row][col];
		 		wDeck[row][col] = wDeck[nrow][ncol];
		 		wDeck[nrow][ncol] = tmp;
				tot_val[col]++;
				tot_sut[row]++;
				next_card++;
				} /* if loop */
			}/*end replace card loop*/
		}
	}
	printf("i am right before nhand");
	tmp = count(tot_val,tot_sut);
	return(tmp);
}

int pair1(int tval[])

{
	int  col, pair = 0, handtype = 0;

	   for (col = 0; col <= 12; col++){
		if (tval[col] == 2){  /* pair */ 
			pair++;
			}
		}
		if (pair == 1) 
			handtype = 1;
		else handtype = 0;
	return(handtype);
 } /* pair */

int pair2(int tval[])

{
	int  pair = 0, col, handtype = 0;
 	for (col = 0; col <= 12; col++){
		if (tval[col] == 2){  /* pair */ 
			pair++;
			}
		}
		if (pair == 2)            /* two pair */
			handtype = 2;
		else handtype = 0;		
	return(handtype);
}/* two pair */

int kind3(int tval[])

{
	int col, handtype = 0;

 	for (col = 0; col <= 12; col++){
		if (tval[col] == 3)   /* 3 of kind */
			handtype = 3;
		else handtype = 0;
		}
		return(handtype);
} /* three of kind */

int kind4(int tval[])

{
	int col, handtype = 0;
 	for (col = 0; col <= 12; col++){
		if (tval[col] == 4)  /* 4 of Kind */
			handtype = 7;
		else handtype = 0;
		}
		return(handtype);
} /* four of kind */

int strait(int tval[])

{ 
	int col, handtype = 0;

 	for (col = 0; col <= 12; col++){
		if ((5 >= tval[col] >= 1) &&
		   (6 >= tval[col] >= 2) &&
		   (7 >= tval[col] >= 3) &&
		   (8 >= tval[col] >= 4) &&
		   (9 >= tval[col] >= 5) &&
		   (10 >= tval[col] >= 6 ) &&
		   (11 >= tval[col] >= 7 ) &&
		   (12 >= tval[col] >= 8 )) 
			handtype = 5;
		else handtype = 0;
		   }
	return(handtype);
} /* straight */

int flush(int tsuit[])
{
	int row, handtype = 0;
	for (row = 0; row < 4; row++){    /* Flush */
		if (tsuit[row] == 5)
			handtype = 6;
		else handtype = 0;
	}
	return(handtype);
} /* flush */

int strait_flush(int tval[], int tsuit[])

{
	int col, row, handtype = 0;
	for (row = 0; row < 4; row++){    /* straight Flush */
 	   for (col = 0; col <= 12; col++){
		if ((tsuit[row] == 5) &&
		   (5 >= tval[col] >= 1) &&
		   (6 >= tval[col] >= 2) &&
		   (7 >= tval[col] >= 3) &&
		   (8 >= tval[col] >= 4) &&
		   (9 >= tval[col] >= 5) &&
		   (10 >= tval[col] >= 6 ) &&
		   (11 >= tval[col] >= 7 ))
			handtype = 8;
		else handtype = 0;
		    }
		}
	return(handtype);
}     /* straight flush */

int royal_flush(int tval[], int tsuit[])
						/* Royal Flush */

{
	int col, row, handtype = 0;
	for (row = 0; row < 4; row++){    /* straight Flush */
 	   for (col = 0; col <= 12; col++){
		if ((tsuit[row] == 5) &&    
		   (12 >= tval[col] >= 8 )) 
			handtype = 9;
		else handtype = 0;
		}
	}
	return(handtype);
} /* royal flush */

void caset(int type)

/* switches handtype into case */	
	
{
	switch (type){
	
	case 0 :
		printf("You have no hand of value\n");
		printf("\n");
		break;
	case 1 :
		printf("You have one pair\n");
		printf("\n");
		break;
	case 2 :
		printf(" You have two pairs\n");
		printf("\n");
		break;
	case 3 :
		printf(" You have three of a kind\n");
		printf("\n");
		break;
	case 5 :
		printf(" You have a straight\n");
		printf("\n");
		break;
	case 6 :
		printf(" You have a flush\n");
		printf("\n");
		break;
	case 4 :
		printf(" You have a full house\n"); 
		printf("\n");
		break;
	case 7 :
		printf(" You have four of a kind\n");
		printf("\n");
		break;
	case 8 :
		printf(" You have a straight flush\n");
		printf("\n");
		break;
	case 9 :
		printf(" You have a royal flush\n");
		printf("\n");
		break;
	}
	}

