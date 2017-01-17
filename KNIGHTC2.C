/*
 * Chad Homan
   $Author: ff006 $
   $Date: 1994/09/30 20:07:53 $
   $Source: /u/ff006/hw5/RCS/knightc2.c,v $
   $Revision: 1.4 $
    Matt Payne CSCI-1840
 * ff006@thor choman@s-cwis 
 */
/* Knights tour problem part C with prompting */

/* Declarations */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define NUM_COLS 8
#define NUM_ROWS 8

/* Function prototypes */
int move(int[][], int[][], int, int, int[], int[]);
int print_board(int[][]);
int adjustment(int[][],int,int,int[],int[]);

main()
	{
	/* this will initialize the following variables
		and will also set up the two dimensional 
		array which in turn is the chessboard */
 
	int current_row = 0, current_col = 0, move_number, move; 
	int horizontal[NUM_ROWS] = {2, 1, -1, -2, -2, -1, 1, 2};
	int vertical[NUM_COLS] = {-1, -2, -2, -1, 1, 2, 2, 1};
	int board[NUM_ROWS][NUM_COLS] = {0};
	int accessibility[NUM_ROWS][NUM_COLS] = {{2,3,4,4,4,4,3,2},
						 {3,4,6,6,6,6,4,3},
						 {4,6,8,8,8,8,6,4},
						 {4,6,8,8,8,8,6,4},
						 {4,6,8,8,8,8,6,4},
						 {4,6,8,8,8,8,6,4},
						 {3,4,6,6,6,6,4,3},
						 {2,3,4,4,4,4,3,2}};
	printf("\n");
/*	srand(time(NULL)); */   /* calls the random number generator */
	printf(" Enter in the starting row, col\n");
	scanf("%d %d", &current_row, &current_col); 
	/* current_row =(rand() % 8);
	current_col =(rand() % 8);
	*/
	board[current_row][current_col] = move_number = 1;
	for (move_number = 2; move_number <= 64; move_number++){
		/* calls adjust function and pick move function */
		adjust(accessibility, current_row, current_col,
				horizontal, vertical);
		move = pick_move(board, accessibility, current_row, current_col,
					horizontal,vertical);
		current_row += vertical[move];
		current_col += horizontal[move];
		board[current_row][current_col] = move_number;
		}
  		if (move_number - 1 == 64)
			printf("It's a successfull tour, %d moves\n", 
				move_number - 1 );
		else printf("Not a complete tour, %d moves\n", move_number - 1);
		print_board( board );
		printf("\n");
		printf("Final position is : %d %d\n",
			 current_row, current_col);
	return (0);
	}

/* Funtion for moves */

 int pick_move(int brd[NUM_ROWS][NUM_COLS],
	  int access[NUM_ROWS][NUM_COLS],
	  int c_row, int c_col,
	  int horz[NUM_ROWS],
	  int vert[NUM_COLS])
	{
	  int m, move = -1, highnumber = 320;
	for (m = 0; m < 8; m++){
		if (((c_col + horz[m]) < NUM_COLS) &&
		    ((c_row + vert[m]) < NUM_ROWS) &&
		    ((c_col + horz[m]) >= 0) &&
		    ((c_row + vert[m]) >= 0) &&
		    !brd[c_row + vert[m]][c_col + horz[m]]){
		    /*access[c_row][c_col] < highnumber)*/
			if (highnumber > access[c_row+vert[m]][c_col+horz[m]]){
				/* since this board has a lower accessibility
					then we must */
			    highnumber = access[c_row+vert[m]][c_col+horz[m]];
			    move = m;
			    } /* highnumber update */
			}/* if col */
		} /* for m */
	assert(move != -1);
	return(move);
	} /* pickmove */

/* function for print board */  

int print_board(int brd[NUM_ROWS][NUM_COLS]) 

	{
	int i, j;
	printf("    0  1  2  3  4  5  6  7\n");
	printf("\n");
	for (i = 0; i < NUM_COLS; i++){
		printf("%d ", i);
		for (j = 0; j < NUM_ROWS; j++){
			printf("%3d", brd[i][j]);
			}
		printf("\n");
		}
	return (0);
	}
/* adjust_accessibility function */

int adjust(int access[][NUM_COLS],int row,int col,
		int hor[NUM_ROWS],int ver[NUM_COLS])

	{
	int x,y;
	for(x = 0; x < 8; x++){
		if (((col + hor[x]) < NUM_COLS) &&
		    ((row + ver[x]) < NUM_ROWS) &&
		    ((col + hor[x]) >= 0) &&
		    ((row + ver[x]) >= 0)) {
			access[row+ver[x]][col+hor[x]]--;
			}
		}
	return(0);
	}/* adjust */
