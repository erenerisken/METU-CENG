/* Explanations *************************************************************************************************************************************
|
| - The dungeon consists of a "start" room, an "exit" room, one room with "gold", one or more rooms with "wumpuses", and zero or more empty rooms.
| - "Start" and "exit" rooms are empty.
| - Other rooms can be empty, or can contain only a single entity (either gold, or wumpus). A room cannot contain more than one entities.
| - At the beginning of the game, the player sets the total number of rooms, and also the number of wumpuses.
| - Player starts in room "start".
| - All rooms are magical, and they all have 2 doors.
| - Doors might appear randomly in North, East, South or West directions.
| - Doors lead to randomly selected other rooms.
| - If the player visits the room with the gold, the player grabs the gold.
| - If the player visits a room with a wumpus in it, the wumpus eats the player, and the game finishes.
| - If the player visits the "exit" room, the game finishes. If the player has the gold with her, this is a successful finish.
|
****************************************************************************************************************************************************/




/* Includes ****************************************************************************************************************************************/

#include "Utilities.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>   /* For standard input/output functions */

/***************************************************************************************************************************************************/




/* Definitions *************************************************************************************************************************************/

#define AUTHOR       ( "Eren Erisken" )  /* Author's name                                                                   */

#define MIN_ROOMS    (  2              )  /* Minimum number of magical rooms in the dungeon (excluding start and exit rooms) */
#define MAX_ROOMS    (  8              )  /* Maximum number of magical rooms in the dungeon (excluding start and exit rooms) */
#define MIN_WUMPUSES (  1              )  /* Minimum number of wumpuses in the dungeon                                       */
#define MAX_WUMPUSES (  4              )  /* Maximum number of wumpuses in the dungeon                                       */

#define START        ( 'S'             )  /* Label for the start room                                                        */
#define EXIT         ( 'X'             )  /* Label for the exit room                                                         */
#define GOLD         ( 'G'             )  /* Label for the single room containing the gold                                   */
#define WUMPUS       ( 'W'             )  /* Label for room(s) containing a wumpus                                           */
#define EMPTY        ( 'E'             )  /* Label for empty room(s)                                                         */

/***************************************************************************************************************************************************/




/* Type Definitions ********************************************************************************************************************************/

typedef unsigned char boolean ;

/***************************************************************************************************************************************************/




/* Global Variables ********************************************************************************************************************************/

int     numberOfMagicalRooms                            ;
int     numberOfWumpuses                                ;
int     currentRoomNo                                   ;
boolean playerFoundGold                                 ;
char    r0 , r1 , r2 , r3 , r4 , r5 , r6 , r7 , r8 , r9 ; /* r0 is start room, r1 is exit room, others are magical rooms (at most 8 magical rooms) */

/***************************************************************************************************************************************************/




/* Helper (Minor) Functions ************************************************************************************************************************/

int max(int a, int b)
	{
		return a>b ? a : b;
	}

int min(int a, int b)
	{
		return a<b ? a : b;
	}

/* The input is the room number, and the return value is the label for the room. */

char getRoomInformation ( int roomNo )
{
  switch ( roomNo )
  {
    default :
    case 0  : return r0 ;
    case 1  : return r1 ;
    case 2  : return r2 ;
    case 3  : return r3 ;
    case 4  : return r4 ;
    case 5  : return r5 ;
    case 6  : return r6 ;
    case 7  : return r7 ;
    case 8  : return r8 ;
    case 9  : return r9 ;
  }
}

/*=================================================================================================================================================*/

/* The input is the room label. The function prints out the information associated with the label. */

void printRoomInformation1 ( char room )
{
  switch ( room )
  {
    case START  : printf( "START"  ) ;  break ;
    case EXIT   : printf( "EXIT"   ) ;  break ;
    case GOLD   : printf( "GOLD"   ) ;  break ;
    case WUMPUS : printf( "WUMPUS" ) ;  break ;
    case EMPTY  : printf( "EMPTY"  ) ;  break ;
  }
}

/*=================================================================================================================================================*/

/* The input is the room number. The function prints out the information associated with the room. */

void printRoomInformation2 ( int roomNo )
{
  switch ( roomNo )
  {
    case 0 : printRoomInformation1( r0 ) ;  break ;
    case 1 : printRoomInformation1( r1 ) ;  break ;
    case 2 : printRoomInformation1( r2 ) ;  break ;
    case 3 : printRoomInformation1( r3 ) ;  break ;
    case 4 : printRoomInformation1( r4 ) ;  break ;
    case 5 : printRoomInformation1( r5 ) ;  break ;
    case 6 : printRoomInformation1( r6 ) ;  break ;
    case 7 : printRoomInformation1( r7 ) ;  break ;
    case 8 : printRoomInformation1( r8 ) ;  break ;
    case 9 : printRoomInformation1( r9 ) ;  break ;
  }
}

/*=================================================================================================================================================*/

/* The input is the direction. The function prints out the direction as a word, as an acronym and also displays an arrowhead. */

void printDirection ( int direction )
{
  switch ( direction )
  {
    case 0 : printf( "NORTH (N) ^" ) ;  break ;
    case 1 : printf( "EAST (E) >"  ) ;  break ;
    case 2 : printf( "SOUTH (S) v" ) ;  break ;
    case 3 : printf( "WEST (W) <"  ) ;  break ;
  }
}

/***************************************************************************************************************************************************/




/* Functions ***************************************************************************************************************************************/

/* Prints a banner including the author name. */

void printBanner ( void )
{
  printf("\n*******************************************************************************\n");
  printf("* Dungeons and Dragons with Wumpuses                                          *\n");
  printf("* by %-72s *\n",AUTHOR);
  printf("*******************************************************************************\n\n");
  return;
}

/*=================================================================================================================================================*/

/* Initializes all global variables.                                                                                    */
/* The number of magical rooms and the number of wumpuses are set by the player as part of the configuration process.   */
/* All possible errors in input should be handled by clearing the input buffer and asking the user again for the input. */

void configureWorld ( void )
{
	extern char r0,r1,r2,r3,r4,r5,r6,r7,r8;
	extern int currentRoomNo, numberOfMagicRooms, numberOfWumpuses;
	extern boolean playerFoundGold;
	char s;
	int i,x;
  	printf("Let's configure the DnDW World first!\n");
	while(1)
		{
			printf("Enter number of magical rooms [%d,%d] :",MIN_ROOMS,MAX_ROOMS);
			scanf(" %c",&s);
			numberOfMagicalRooms = s-'0';
			if(numberOfMagicalRooms >= MIN_ROOMS && numberOfMagicalRooms <= MAX_ROOMS)
				break;
			printf("Incorrect input! Please try again.\n");
			clearInputBuffer();
		}
	if(numberOfMagicalRooms == 1+MIN_WUMPUSES)
		{
			numberOfWumpuses = MIN_WUMPUSES;
		}
	else
		{
			while(1)
				{
					printf("Enter number of wumpuses [%d,%d]      :",MIN_WUMPUSES,min(MAX_WUMPUSES,numberOfMagicalRooms-1));
					scanf(" %c",&s);
					numberOfWumpuses = s-'0';
					if(numberOfWumpuses >= MIN_WUMPUSES && numberOfWumpuses <= min(MAX_WUMPUSES,numberOfMagicalRooms-1))
						break;
					printf("Incorrect input! Please try again.\n");
					clearInputBuffer();
				}
		}
	r0 = START;
	r1 = EMPTY;
	r2 = EMPTY;
	r3 = EMPTY;
	r4 = EMPTY;
	r5 = EMPTY;
	r6 = EMPTY;
	r7 = EMPTY;
	r8 = EMPTY;
	r9 = EMPTY;
	currentRoomNo = 0;
	playerFoundGold = FALSE;
	x = randomIntegerMaxUnBiased(numberOfMagicalRooms)+1;
	switch(x)
		{
			case 1:
				r1 = GOLD;
				break;
			case 2:
				r2 = GOLD;
				break;
			case 3:
				r3 = GOLD;
				break;
			case 4:
				r4 = GOLD;
				break;
			case 5:
				r5 = GOLD;
				break;
			case 6:
				r6 = GOLD;
				break;
			case 7:
				r7 = GOLD;
				break;
			case 8:
				r8 = GOLD;
				break;
			case 9:
				r9 = GOLD;
				break;
		}
	i = 0;
	while(i<numberOfWumpuses)
		{
			x = randomIntegerMaxUnBiased(numberOfMagicalRooms)+1;
			switch(x)
				{
					case 1:
						if(r1!=EMPTY)
							continue;
						r1 = WUMPUS;
						i++;
						break;
					case 2:
						if(r2!=EMPTY)
							continue;
						r2 = WUMPUS;
						i++;
						break;
					case 3:
						if(r3!=EMPTY)
							continue;
						r3 = WUMPUS;
						i++;
						break;
					case 4:
						if(r4!=EMPTY)
							continue;
						r4 = WUMPUS;
						i++;
						break;
					case 5:
						if(r5!=EMPTY)
							continue;
						r5 = WUMPUS;
						i++;
						break;
					case 6:
						if(r6!=EMPTY)
							continue;
						r6 = WUMPUS;
						i++;
						break;
					case 7:
						if(r7!=EMPTY)
							continue;
						r7 = WUMPUS;
						i++;
						break;
					case 8:
						if(r8!=EMPTY)
							continue;
						r8 = WUMPUS;
						i++;
						break;
					case 9:
						if(r9!=EMPTY)
							continue;
						r9 = WUMPUS;
						i++;
						break;
				}
		}
	i = 0;
	while(!i)
		{
			x = randomIntegerMaxUnBiased(numberOfMagicalRooms)+1;
			switch(x)
				{
					case 1:
						if(r1!=EMPTY)
							continue;
						r1 = EXIT;
						i++;
						break;
					case 2:
						if(r2!=EMPTY)
							continue;
						r2 = EXIT;
						i++;
						break;
					case 3:
						if(r3!=EMPTY)
							continue;
						r3 = EXIT;
						i++;
						break;
					case 4:
						if(r4!=EMPTY)
							continue;
						r4 = EXIT;
						i++;
						break;
					case 5:
						if(r5!=EMPTY)
							continue;
						r5 = EXIT;
						i++;
						break;
					case 6:
						if(r6!=EMPTY)
							continue;
						r6 = EXIT;
						i++;
						break;
					case 7:
						if(r7!=EMPTY)
							continue;
						r7 = EXIT;
						i++;
						break;
					case 8:
						if(r8!=EMPTY)
							continue;
						r8 = EXIT;
						i++;
						break;
					case 9:
						if(r9!=EMPTY)
							continue;
						r9 = EXIT;
						i++;
						break;
				}
		}
	printf("Configuration is finished. Good luck with the game play!\n\n");
}

/*=================================================================================================================================================*/

/* Prints the configured world. */

void printWorld ( void )
{
	int i;
	printf("DnD World:\n----------\n");
	for(i = 0; i<=numberOfMagicalRooms+1; i++)
		{
			printf("Room %d : ",i);
			printRoomInformation2(i);
			printf("\n");
		}
}

/*=================================================================================================================================================*/

/* Prints the current room information and the doors of the current room.                                               */
/* Gets player's door choice as one of 'N', 'E', 'S', 'W' (small letters should also be accepted).                      */
/* All possible errors in input should be handled by clearing the input buffer and asking the user again for the input. */
/* Prints where the doors were actually opening to.                                                                     */
/* Updates current room number.                                                                                         */
/* If the current room contains gold, lets the player know that she now has gold in her posession.                      */

void getNextMove ( void )
{
	int d1,d2,n1,n2,c;
	char s;
	d1 = randomIntegerMaxUnBiased(3);
	d2 = randomIntegerMinMaxUnBiasedExcept1(0,3,d1);
	n1 = randomIntegerMinMaxUnBiasedExcept1(0,numberOfMagicalRooms,currentRoomNo);
	n2 = randomIntegerMinMaxUnBiasedExcept2(0,numberOfMagicalRooms,currentRoomNo,n1);
	printf("\nYou are in room : %d\n",currentRoomNo);
	printf("Room information : ");
	printRoomInformation2(currentRoomNo);
	printf("\nThere is a door to your ");
	printDirection(d1);
	printf("\nAnd, there is another door to your ");
	printDirection(d2);
	printf("\nWhich one will you choose? : ");
	c = -1;
	while(c != d1 && c != d2)
		{
			scanf(" %c",&s);
			clearInputBuffer();
			if(s == 'N' || s == 'n')
				{
					c = 0;
				}
			else if(s == 'E' || s == 'e')
				{
					c = 1;
				}
			else if(s == 'S' || s == 's')
				{
					c = 2;
				}
			else if(s == 'W' || s == 'w')
				{
					c = 3;
				}
			else
				{
					printf("Incorrect input! Please try again : ");
				}
		}
	printf("Room to your ");
	printDirection(d1);
	printf(" was Room %d\n",n1);
	printf("Room to your ");
	printDirection(d2);
	printf(" was Room %d\n",n2);
	if(c == d1)
		currentRoomNo = n1;
	if(c == d2)
		currentRoomNo = n2;
	return;
}

/*=================================================================================================================================================*/

/* Checks if the current room that the player is in is the exit room.                                           */
/* If so, checks if the player already has the gold or not, and prints out an appropriate message in each case. */
/* Also checks if the player is in a room with a wumpus.                                                        */
/* If so, informs the player about the unhappy ending of the game.                                              */
/* Returns TRUE if the game ended, otherwise, does not print anything and just returns FALSE.                   */

boolean checkAndPrintGameResult ( void )
{
  	char cur;
  	switch(currentRoomNo)
  		{
  			case 0:
  				cur = r0;
  				break;
  			case 1:
  				cur = r1;
  				break;
  			case 2:
  				cur = r2;
  				break;
  			case 3:
  				cur = r3;
  				break;
  			case 4:
  				cur = r4;
  				break;
  			case 5:
  				cur = r5;
  				break;
  			case 6:
  				cur = r6;
  				break;
  			case 7:
  				cur = r7;
  				break;
  			case 8:
  				cur = r8;
  				break;
  			case 9:
  				cur = r9;
  				break;
	  	}
	if(cur == GOLD)
		{
			printf("You have GOLD now!\n");
			playerFoundGold = TRUE ;
		}
	if(cur == EXIT && playerFoundGold == FALSE)
		{
			printf("You are safely out of the dungeon, but you did not find the GOLD! Better luck next time!\n");
			return TRUE;
		}
	if(cur == EXIT && playerFoundGold == TRUE)
		{
			printf("You are safely out of the dungeon with the GOLD! Congratulations!\n");
			return TRUE;
		}
	if(cur == WUMPUS)
		{
			printf("Wumpus is full, and you are in heaven! What a pity!\n");
			return TRUE;
		}
	return FALSE;
}

/***************************************************************************************************************************************************/




/* Main Function ***********************************************************************************************************************************/

/* Prints banner.                                                                */
/* Configures the dungeon world.                                                 */
/* Prints the configured world.                                                  */
/* Asks the player to make a move until the game finishes .                      */
/* Prints the game result.                                                       */
/* Prints a goodbye message.                                                     */
/* Prints the number of random numbers that were generated during the game play. */

int main ( void )
{
	extern unsigned int numberOfRandomNumbersGenerated;
  	printBanner();
  	configureWorld();
  	printWorld();
  	do
  		{
  			getNextMove();
		}while(checkAndPrintGameResult() == FALSE);
	printf("\nGood game. Have a nice day!\n\n%d random numbers were generated during the game play.\n",numberOfRandomNumbersGenerated);
	return 0;
}

/***************************************************************************************************************************************************/
