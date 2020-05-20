/* Explanations *************************************************************************************************************************************
|
| The Tic-Tac-Toe board has 9 cells. We will assume that the cell numbering is as follows:
|
|   c0 | c1 | c2
|   ------------
|   c3 | c4 | c5
|   ------------
|   c6 | c7 | c8
|
****************************************************************************************************************************************************/




/* Includes ****************************************************************************************************************************************/

#include "Utilities.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>   /* For standard input/output functions */

/***************************************************************************************************************************************************/




/* Definitions *************************************************************************************************************************************/

#define AUTHOR  ( "Eren Erisken" )  /* Author's name                                   */

#define EMPTY   ( ' '             )  /* Label for empty cells                           */
#define PLAYER1 ( 'X'             )  /* Label for player 1 and cells marked by player 1 */
#define PLAYER2 ( 'O'             )  /* Label for player 2 and cells marked by player 2 */

/***************************************************************************************************************************************************/




/* Type Definitions ********************************************************************************************************************************/

typedef unsigned char boolean ;

/***************************************************************************************************************************************************/




/* Global Variables ********************************************************************************************************************************/

char c0 , c1 , c2 , c3 , c4 , c5 , c6 , c7 , c8 ;  /* Cells of the Tic-Tac-Toe board */

/***************************************************************************************************************************************************/




/* Functions ***************************************************************************************************************************************/

/* Initializes the global variables. */

void initializeGlobalVariables ( void )
{
  c0 = EMPTY;
  c1 = EMPTY;
  c2 = EMPTY;
  c3 = EMPTY;
  c4 = EMPTY;
  c5 = EMPTY;
  c6 = EMPTY;
  c7 = EMPTY;
  c8 = EMPTY;
}

/*=================================================================================================================================================*/

/* Prints a banner including the author name. */

void printBanner ( void )
{
  printf(                                                                                   "\n"          ) ;
  printf( "*******************************************************************************" "\n"          ) ;
  printf( "* Tic-Tac-Toe                                                                 *" "\n"          ) ;
  printf( "* by %-72s *"                                                                    "\n" , AUTHOR ) ;
  printf( "*******************************************************************************" "\n"          ) ;
}

/*=================================================================================================================================================*/

/* Prints the current board configuration. */

void printBoard ( void )
{
  printf("\n    Cells                  Board\n");
  printf(".-----------.          .-----------.\n");
  printf("| 0 | 1 | 2 |          | %c | %c | %c |\n",c0,c1,c2);
  printf("|-----------|          |-----------|\n");
  printf("| 3 | 4 | 5 |          | %c | %c | %c |\n",c3,c4,c5);
  printf("|-----------|          |-----------|\n");
  printf("| 6 | 7 | 8 |          | %c | %c | %c |\n",c6,c7,c8);
  printf("'-----------'          '-----------'\n\n");
}

/*=================================================================================================================================================*/

/* Gets the next move of "player", and marks it on the board.                     */
/* Loops (and asks again) if the input is not valid, or if the cell is not empty. */

void getNextMove ( char player )
{
	extern char c0,c1,c2,c3,c4,c5,c6,c7,c8;
  	char s;
  	printf("Player %c, enter your next move (0-8) : ",player);
  	scanf(" %c",&s);
  	if(s-'0'<0 || s-'0'>8)
  		{
  			printf("Incorrect input! Please try again.\n");
  			clearInputBuffer();
			getNextMove(player);
	  		return;
		}
	switch(s-'0')
		{
			case 0:
				if(c0 != EMPTY)
					{
						printf("Cell is not empty! Please try again.\n");
						getNextMove(player);
						return;
					}
				c0 = player;
				return;
			case 1:
				if(c1 != EMPTY)
					{
						printf("Cell is not empty! Please try again.\n");
						getNextMove(player);
						return;
					}
				c1 = player;
				return;
			case 2:
				if(c2 != EMPTY)
					{
						printf("Cell is not empty! Please try again.\n");
						getNextMove(player);
						return;
					}
				c2 = player;
				return;
			case 3:
				if(c3 != EMPTY)
					{
						printf("Cell is not empty! Please try again.\n");
						getNextMove(player);
						return;
					}
				c3 = player;
				return;
			case 4:
				if(c4 != EMPTY)
					{
						printf("Cell is not empty! Please try again.\n");
						getNextMove(player);
						return;
					}
				c4 = player;
				return;
			case 5:
				if(c5 != EMPTY)
					{
						printf("Cell is not empty! Please try again.\n");
						getNextMove(player);
						return;
					}
				c5 = player;
				return;
			case 6:
				if(c6 != EMPTY)
					{
						printf("Cell is not empty! Please try again.\n");
						getNextMove(player);
						return;
					}
				c6 = player;
				return;
			case 7:
				if(c7 != EMPTY)
					{
						printf("Cell is not empty! Please try again.\n");
						getNextMove(player);
						return;
					}
				c7 = player;
				return;
			case 8:
				if(c8 != EMPTY)
					{
						printf("Cell is not empty! Please try again.\n");
						getNextMove(player);
						return;
					}
				c8 = player;
				return;
		}
}

/*=================================================================================================================================================*/

/* Checks if one of the players wins the game, or if the board is full and the game ended with a draw. Prints how the game ended. */
/* Returns TRUE if the game ended, otherwise, does not print anything and just returns FALSE.                                     */

boolean checkAndPrintGameResult ( void )
{
  	/* First row */
  	if(c0 == c1 && c1 == c2 && c0 != EMPTY)
  		{
	  		printf("Player %c WINS (top row)!\n",c1);
			return TRUE;
		}
  	/* Second row */
  	if(c3 == c4 && c4 == c5 && c5 != EMPTY)
  		{
	  		printf("Player %c WINS (middle row)!\n",c4);
			return TRUE;
		}
  	/* Third row */
  	if(c6 == c7 && c7 == c8 && c8 != EMPTY)
  		{
	  		printf("Player %c WINS (bottom row)!\n",c7);
			return TRUE;
		}
	/* First column */
  	if(c0 == c3 && c3 == c6 && c6 != EMPTY)
  		{
	  		printf("Player %c WINS (left column)!\n",c3);
			return TRUE;
		}
  	/* Second column */
  	if(c1 == c4 && c4 == c7 && c7 != EMPTY)
  		{
	  		printf("Player %c WINS (middle column)!\n",c4);
			return TRUE;
		}
  	/* Third row */
  	if(c2 == c5 && c5 == c8 && c8 != EMPTY)
  		{
	  		printf("Player %c WINS (right column)!\n",c5);
			return TRUE;
		}
	/* Primary Diagonal */
  	if(c0 == c4 && c4 == c8 && c8 != EMPTY)
  		{
	  		printf("Player %c WINS (primary diagonal)!\n",c4);
			return TRUE;
		}
	/* Secondary Diagonal */
  	if(c2 == c4 && c4 == c6 && c6 != EMPTY)
  		{
	  		printf("Player %c WINS (secondary diagonal)!\n",c4);
			return TRUE;
		}
	if(c1 != EMPTY && c2 != EMPTY && c3!=EMPTY && c4!=EMPTY && c5!=EMPTY && c6!=EMPTY && c7!=EMPTY && c8!=EMPTY && c0!=EMPTY)
		{
			printf("It's a draw!\n");
			return TRUE;
		}
	return FALSE;
}

/***************************************************************************************************************************************************/




/* Main Function ***********************************************************************************************************************************/

/* Initializes the global variables.                                                                                                          */
/* Prints banner.                                                                                                                             */
/* Randomly chooses one of the players to start first.                                                                                        */
/* Asks each player to make a move in turn until the game finishes (prints the board configuration each time before a player makes her move). */
/* Prints the game result.                                                                                                                    */
/* Prints a goodbye message.                                                                                                                  */
/* Prints the number of random numbers that were generated during the game play.                                                              */

int main ( void )
{
  char currentPlayer = ( ( randomIntegerMinMaxUnBiased( 0 , 1 ) == 0 ) ? PLAYER1 : PLAYER2 ) ;

  initializeGlobalVariables() ;
  printBanner              () ;
  printBoard               () ;

  do
  {
    getNextMove( currentPlayer ) ;
    printBoard (               ) ;

    if   ( currentPlayer == PLAYER1 )  { currentPlayer = PLAYER2 ; }
    else                               { currentPlayer = PLAYER1 ; }
  }
  while ( checkAndPrintGameResult() == FALSE ) ;

  printf( "\nGood game. Have a nice day!\n" ) ;

  printf( "\n%d random numbers were generated during the game play.\n\n" , numberOfRandomNumbersGenerated ) ;

  return 0 ;
}

/***************************************************************************************************************************************************/
