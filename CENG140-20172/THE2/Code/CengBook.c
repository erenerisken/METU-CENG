/* Explanations *************************************************************************************************************************************
|
| This file implements CengBook, which is a realistic simulation of a mini social-media application.
|
****************************************************************************************************************************************************/




/* Includes ****************************************************************************************************************************************/

#include "Utilities.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************************************************************************************************/




/* Macro Definitions *******************************************************************************************************************************/

#define AUTHOR ( "Eren Erisken" )  /* Author's name */  /* TODO: Replace with your name */

/***************************************************************************************************************************************************/




/* Global Variable Definitions *********************************************************************************************************************/

BookPtr bookPtr ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#if   defined(_WIN16) || defined(_WIN32) || defined(_WIN64)

  char operatingSystem[] = "Windows" ;  /* This is a Windows environment.                            */

#elif defined(__linux__)

  char operatingSystem[] = "Linux"   ;  /* This is a Linux environment (any GNU/Linux distribution). */

#elif defined(__APPLE__)

  char operatingSystem[] = "MacOSX"  ;  /* This is a Mac OS X environment.                           */

#endif

/***************************************************************************************************************************************************/




/* Functions ***************************************************************************************************************************************/

void printUsage ( String applicationName )
{
  NL ;

  printf( "Usage: %s <MaxNumberOfUsers> <MaxUserNameLength> <MaxNumberOfFriendsPerUser>\n\n" , applicationName ) ;
}

/*=================================================================================================================================================*/

void printBanner ( void )
{
  NL ;

  printf( "*******************************************************************************" "\n"          ) ;
  printf( "* CengBook                                                                    *" "\n"          ) ;
  printf( "* by %-72s *"                                                                    "\n" , AUTHOR ) ;
  printf( "*******************************************************************************" "\n"          ) ;
}

/*=================================================================================================================================================*/

void printMenu ( void )
{
  NL ;

  printf( "*******************************************************************************" "\n" ) ;
  printf( "Help                       : Print this menu"                                    "\n" ) ;
  printf( "List                       : List all users"                                     "\n" ) ;
  printf( "Plot                       : Create a plot of CengBook (requires GraphViz)"      "\n" ) ;
  printf( "Quit                       : Exit application"                                   "\n" ) ;
  printf( "-------------------------------------------------------------------------------" "\n" ) ;
  printf( "Register   <user>          : Create a new user and add it to CengBook"           "\n" ) ;
  printf( "Delete     <user>          : Delete user from CengBook"                          "\n" ) ;
  printf( "Find       <user>          : Search CengBook for user, display user information" "\n" ) ;
  printf( "Connect    <user1> <user2> : Add a connection from user1 to user2"               "\n" ) ;
  printf( "Disconnect <user1> <user2> : Remove connection from user1 to user2"              "\n" ) ;
  printf( "Path       <user1> <user2> : Find shortest path from user1 to user2"             "\n" ) ;
  printf( "-------------------------------------------------------------------------------" "\n" ) ;
  printf( "Sort <abc|pop> <asc|desc>  : Sort all users (alphabetically or by popularity)"   "\n" ) ;
  printf( "*******************************************************************************" "\n" ) ;
}

/*=================================================================================================================================================*/

void commandHelp ( void )
{
	printMenu();
	return;
}

/*=================================================================================================================================================*/

void commandList ( void )
{
	int i;
	NL;I2;
	if(bookPtr->numberOfUsers <= 0)
		{
			printf("CengBook is empty\n");
			return;
		}
	for(i = 0; i<bookPtr->numberOfUsers; ++i)
		{
			printf("%-16s: %d Follower(s) , %d Friend(s)",bookPtr->userPointers[i]->name, bookPtr->userPointers[i]->numberOfFollowers, bookPtr->userPointers[i]->numberOfFriends);
			NL;I2;
		}
	return;
}

/*=================================================================================================================================================*/

void commandPlot ( void )
{
  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  UserPtr   userPtr             , friendPtr              ;
  int       userIndex           , friendIndex            ;
  String    runDotSystemCommand , openImageSystemCommand ;

  FILE    * file = fopen( "CengBook.dot" , "w" )         ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  fprintf( file , "digraph CengBook"                                                       "\n"                            ) ;
  fprintf( file , "{"                                                                      "\n"                            ) ;
  fprintf( file , "  graph [label=\"CengBook\\nNumber of users = %d\" , labelloc=t] ;"     "\n\n" , bookPtr->numberOfUsers ) ;
  fprintf( file , "  node  [shape=ellipse , fontcolor=black , color=red , penwidth=2.0] ;" "\n\n"                          ) ;
  fprintf( file , "  edge  [color=blue , penwidth=2.0] ;"                                  "\n\n"                          ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  for ( userIndex = 0 ; userIndex < bookPtr->numberOfUsers ; userIndex++ )
  {
    userPtr = bookPtr->userPointers[ userIndex ] ;

    fprintf( file , "  %s [label=\"%s\\n%d Friend(s)\\n%d Follower(s)\"] ;\n" ,
             userPtr->name                                                    ,
             userPtr->name                                                    ,
             userPtr->numberOfFriends                                         ,
             userPtr->numberOfFollowers                                       ) ;
  }

  if ( bookPtr->numberOfUsers > 0 )  { fprintf( file , "\n" ) ; }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  for ( userIndex = 0 ; userIndex < bookPtr->numberOfUsers ; userIndex++ )
  {
    userPtr = bookPtr->userPointers[ userIndex ] ;

    for ( friendIndex = 0 ; friendIndex < userPtr->numberOfFriends ; friendIndex++ )
    {
      friendPtr = userPtr->friendPointers[ friendIndex ] ;

      fprintf( file , "  %s -> %s ;\n" , userPtr->name , friendPtr->name ) ;
    }
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  fprintf( file , "}\n" ) ;
  fclose ( file         ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  if ( strcmp( operatingSystem , "Windows" ) == 0 )
  {
    runDotSystemCommand    = "CMD /C dot -Tgif CengBook.dot -o CengBook.gif" ;
    openImageSystemCommand = "CMD /C START CengBook.gif"                     ;
  }
  else  /* Assumption: Linux */
  {
    runDotSystemCommand    = "dot -Tgif CengBook.dot -o CengBook.gif"        ;
    openImageSystemCommand = "xdg-open CengBook.gif &"                       ;
  }

  if ( system( runDotSystemCommand    ) ) ;  /* "if" statement is used to eliminate warning about unused return value of "system" call */
  if ( system( openImageSystemCommand ) ) ;  /* "if" statement is used to eliminate warning about unused return value of "system" call */

  NL ;  I2 ;  printf( "Plot prepared\n" ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/
}

/*=================================================================================================================================================*/

void commandQuit ( void )
{
	deallocateBook(bookPtr);
	NL;
	I2;
	printf("Have a nice day\n");
	NL;
	exit(0);
}

/*=================================================================================================================================================*/

void commandRegister ( String userName )
{
	NL;I2;
	if(strlen(userName)>getMaxUserNameLength())
		{
			printf("User name is longer than %d characters!\n",getMaxUserNameLength());
			return;
		}
	if(getUserPtrByName(bookPtr,userName) != NULL)
		{
			printf("User '%s' already registered!\n",userName);
			return;
		}
	if(getMaxNumberOfUsers()<=bookPtr->numberOfUsers)
		{
			printf("CengBook is full, cannot register any new users!\n");
			return;
		}
  	bookPtr->userPointers[bookPtr->numberOfUsers++]=allocateUser(userName);
  	printf("User '%s' registered successfully\n",userName);
  	return;
}

/*=================================================================================================================================================*/
void deleteHelperToDisconnect ( UserPtr u1 , UserPtr u2 )/*Helps to disconnect u1 from u2 while deleting user*/
{
	removeConnection(u1,u2);
	return;
}


void commandDelete ( String userName )
{
	UserPtr u;
	int i;
	u = getUserPtrByName(bookPtr,userName);
	NL;I2;
	if(u == NULL)
		{
			printf("User '%s' not found in CengBook!\n",userName);
			return;
		}
	for(i = 0; i<bookPtr->numberOfUsers; ++i)
		{
			if(isConnected(u,bookPtr->userPointers[i]) == TRUE)
				deleteHelperToDisconnect(u,bookPtr->userPointers[i]);
			if(isConnected(bookPtr->userPointers[i],u) == TRUE)
				deleteHelperToDisconnect(bookPtr->userPointers[i],u);
		}
	for(i = 0; bookPtr->userPointers[i]!=u; ++i);
	for(; i<bookPtr->numberOfUsers - 1; ++i)
		bookPtr->userPointers[i] = bookPtr->userPointers[i+1];
	deallocateUser(u);
	bookPtr->userPointers[bookPtr->numberOfUsers-1] = NULL;
	bookPtr->numberOfUsers--;
	printf("User '%s' is deleted from CengBook\n",userName);
	return;
}

/*=================================================================================================================================================*/

void commandFind ( String userName )
{
	int i;
	UserPtr tmp;
	NL;
	I2;
	tmp = getUserPtrByName(bookPtr,userName);
	if(tmp == NULL)
		{
			printf("User '%s' not found in CengBook!\n",userName);
			return;
		}
	printf("%s : %d Follower(s) , %d Friend(s)\n",tmp->name, tmp->numberOfFollowers, tmp->numberOfFriends);
	if(tmp->numberOfFriends<=0)
		{
			return;
		}
	for(i = 0; i<tmp->numberOfFriends; ++i)
		{
			NL;
			I2;
			printf("%d - %s",i+1,tmp->friendPointers[i]->name);
		}
	NL;
	return;
}

/*=================================================================================================================================================*/

void commandConnect ( String userName1 , String userName2 )
{
	UserPtr u1, u2;
	u1 = getUserPtrByName(bookPtr,userName1);
	u2 = getUserPtrByName(bookPtr,userName2);
	NL;I2;
	if(u1 == NULL)
		{
			printf("User '%s' not found in CengBook!\n",userName1);
			I2;
		}
	if(u2 == NULL)
		{
			printf("User '%s' not found in CengBook!\n",userName2);
		}
	if(u1 == NULL || u2 == NULL)
		return;
	if(u1 == u2)
		{
			printf("Connection to self is not allowed!\n");
			return;
		}
	if(u1->numberOfFriends>=getMaxNumberOfFriendsPerUser())
		{
			printf("Friend capacity of user '%s' is full!\n",userName1);
			return;
		}
	if(isConnected(u1,u2) == TRUE)
		{
			printf("User '%s' is already connected to user '%s'!\n",userName1,userName2);
			return;
		}
	u2->numberOfFollowers++;
	u1->friendPointers[u1->numberOfFriends++]=u2;
	printf("User '%s' successfully connected to user '%s'\n",userName1,userName2);
}

/*=================================================================================================================================================*/

void commandDisconnect ( String userName1 , String userName2 )
{
	UserPtr u1, u2;
	int i;
	u1 = getUserPtrByName(bookPtr,userName1);
	u2 = getUserPtrByName(bookPtr,userName2);
	NL;I2;
	if(u1 == NULL)
		{
			printf("User '%s' not found in CengBook!\n",userName1);
			I2;
		}
	if(u2 == NULL)
		{
			printf("User '%s' not found in CengBook!\n",userName2);
		}
	if(u1 == NULL || u2 == NULL)
		return;
	if(u1 == u2)
		{
			printf("Disconnecting from self is not allowed!\n");
			return;
		}
	if(isConnected(u1,u2)==FALSE)
		{
			printf("User '%s' and user '%s' are not connected!\n",userName1,userName2);
			return;
		}
	removeConnection(u1,u2);
	printf("User '%s' successfully disconnected from user '%s'\n",userName1,userName2);
	return;
}

/*=================================================================================================================================================*/

void commandPath ( String userName1 , String userName2 )
{
  	int i;
  	UserPtrArray d;
  	UserPtr u1, u2;
	u1 = getUserPtrByName(bookPtr,userName1);
	u2 = getUserPtrByName(bookPtr,userName2);
	NL;I2;
	if(u1 == NULL)
		{
			printf("User '%s' not found in CengBook!\n",userName1);
			I2;
		}
	if(u2 == NULL)
		{
			printf("User '%s' not found in CengBook!\n",userName2);
		}
	if(u1 == NULL || u2 == NULL)
		return;
	if(u1 == u2)
		{
			printf("Path to self queried!\n");
			return;
		}
	d = shortestPath(bookPtr,u1,u2);
	if(d == NULL)
		{
			printf("There is no path from user '%s' to user '%s'\n",userName1,userName2);
			return;
		}
	i = 1;
	printf("'%s' ",userName1);
	while(d[i]!=NULL)
		printf("-> '%s' ",d[i++]->name);
	NL;
	return;
}

/*=================================================================================================================================================*/
boolean toBeChanged(UserPtr u1, UserPtr u2, int criterion, int order)/*helper function for sorting*/
	{
		/*
		0 0 -> pop desc
		0 1 -> pop asc
		1 0 -> abc desc
		1 1 -> abc asc
		*/
		int comp;
		comp = criterion == 0 ? compareByPopularity(u1,u2) : compareByName(u1,u2);
		return order == 0 ? comp<0 : comp>=0;
	}

void commandSort ( String criterion , String order )
{
	int i, cr, ord;
	boolean flag;
	NL;I2;
	if(!(strcmp(criterion,"pop")==0 || strcmp(criterion,"abc") == 0))
		{
			printf("Invalid sort criterion '%s'!\n",criterion);
			return;
		}
	if(!(strcmp(order,"asc")==0 || strcmp(order,"desc") == 0))
		{
			printf("Invalid sort order '%s'!\n",order);
			return;
		}
	cr = !strcmp(criterion,"abc");
	ord = !strcmp(order,"asc");
	flag = TRUE;
	while(flag == TRUE)
		{
			flag = FALSE;
			for(i = 0; i<bookPtr->numberOfUsers-1; ++i)
				{
					UserPtr u1, u2;
					u1 = getUserPtrByIndex(bookPtr,i);
					u2 = getUserPtrByIndex(bookPtr,i+1);
					if(toBeChanged(u1,u2,cr,ord) == TRUE)
						{
							bookPtr->userPointers[i] = u2;
							bookPtr->userPointers[i+1] = u1;
							flag = TRUE;
						}
				}
		}
	printf("CengBook sorted 'by %s' in '%s' order\n",cr == 1 ? "albhabetically" : "popularity", ord == 1 ? "ascending" : "descending");
	return;
}

/*=================================================================================================================================================*/

void processInput ( String input )
{
  int         i                                                    ;
  int         numberOfTokens = 0                                   ;
  StringArray tokens         = tokenize( input , &numberOfTokens ) ;
  String      command                                              ;

  if ( numberOfTokens < 1 )  { return ; }

  command = tokens[0] ;

  for ( i = 0 ; i < strlen( command ) ; i++ )  { if ( ( command[i] >= 'A' ) && ( command[i] <= 'Z' ) )  { command[i] += 'a' - 'A' ; } }

  if      ( strcmp( command , "help"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandHelp      (                       ) ;  return ; } }
  else if ( strcmp( command , "list"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandList      (                       ) ;  return ; } }
  else if ( strcmp( command , "plot"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandPlot      (                       ) ;  return ; } }
  else if ( strcmp( command , "quit"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandQuit      (                       ) ;  return ; } }
  else if ( strcmp( command , "register"   ) == 0 )  { if ( numberOfTokens == 2 ) { commandRegister  ( tokens[1]             ) ;  return ; } }
  else if ( strcmp( command , "delete"     ) == 0 )  { if ( numberOfTokens == 2 ) { commandDelete    ( tokens[1]             ) ;  return ; } }
  else if ( strcmp( command , "find"       ) == 0 )  { if ( numberOfTokens == 2 ) { commandFind      ( tokens[1]             ) ;  return ; } }
  else if ( strcmp( command , "connect"    ) == 0 )  { if ( numberOfTokens == 3 ) { commandConnect   ( tokens[1] , tokens[2] ) ;  return ; } }
  else if ( strcmp( command , "disconnect" ) == 0 )  { if ( numberOfTokens == 3 ) { commandDisconnect( tokens[1] , tokens[2] ) ;  return ; } }
  else if ( strcmp( command , "path"       ) == 0 )  { if ( numberOfTokens == 3 ) { commandPath      ( tokens[1] , tokens[2] ) ;  return ; } }
  else if ( strcmp( command , "sort"       ) == 0 )  { if ( numberOfTokens == 3 ) { commandSort      ( tokens[1] , tokens[2] ) ;  return ; } }
  else                                               { NL ;  I2 ;  printf( "Invalid command!\n" ) ;                               return ;   }

  /* If we reach here, the user must have provided incorrect number of arguments to a valid command */

  command[0] += 'A' - 'a' ;

  NL ;  I2 ;  printf( "Incorrect number of arguments provided for the command '%s'!\n" , command ) ;
}

/***************************************************************************************************************************************************/




/* Main Function ***********************************************************************************************************************************/

int main ( int argc , char * argv[] )
{
  char input [ MAX_INPUT_LENGTH ] ;

  if ( argc < 4 )  { printUsage( argv[0] ) ;  return 0 ; }

  configureCengBook( /* maxNumberOfUsers          */ atoi( argv[1] ) ,
                     /* maxUserNameLength         */ atoi( argv[2] ) ,
                     /* maxNumberOfFriendsPerUser */ atoi( argv[3] ) ) ;

  bookPtr = allocateBook() ;

  if ( bookPtr == NULL )  { NL ;  printf( "Error: Cannot allocate memory to store CengBook! Exiting!\n\n" ) ;  exit( 0 ) ; }

  printBanner() ;
  printMenu  () ;

  while ( TRUE )
  {
    NL                        ;  /* New line     */
    printf( "[CENGBOOK] > " ) ;  /* Print prompt */

    if ( fgets( input , MAX_INPUT_LENGTH , stdin ) == NULL )  /* Read input line, 'fgets' is safer than 'gets'. */
    {
      /* In the following two lines, the "if" statements surrounding the "freopen" function calls are used to eliminate warnings. */

      if   ( strcmp( operatingSystem , "Windows" ) == 0 )  { if ( freopen( "CON"      , "r" , stdin ) == NULL ) ; }
      else /* Assumption:               Linux          */  { if ( freopen( "/dev/tty" , "r" , stdin ) == NULL ) ; }

      continue ;
    }

    processInput( input ) ;  /* Tokenize and process the input command */
  }

  return 0 ;
}

/***************************************************************************************************************************************************/
