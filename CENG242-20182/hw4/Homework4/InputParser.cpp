#include"InputParser.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
/**
   * Parse the initial parameters of the game from stdin.
   * The input will be as follows.
   * First line contains the size of the board.
   * Second line contains the coordinates of the chest.
   * Third line contains the maximum turn number for the game.
   * Fourth line contains the number of players, P.
   * Each of the next P lines contains a description for a player as follows.
   * ID of the player, class of the player, team of the player, x coordinate, y coordinate, .
   * Call the addPlayer method of the Game class to add the players.
   * Example input:
   * 6
   * 3 3
   * 100
   * 2
   * 12 ARCHER BARBARIAN 3 5
   * 11 FIGHTER KNIGHT 1 1
   *
   * @returns Pointer to the Dynamically allocated Game object
   */

//Game(unsigned int maxTurnNumber, unsigned int boardSize, Coordinate chest);
//void addPlayer(int id, int x, int y, Team team, std::string cls);
Game* InputParser::parseGame()
    {
        static Game *ret = NULL;
        if(ret != NULL)
            return ret;
        unsigned int boardSize, maxTurnNumber, playerNumber;
        int x,y;
        std::cin>>boardSize>>x>>y>>maxTurnNumber>>playerNumber;
        ret = new Game(maxTurnNumber, boardSize, Coordinate(x,y));
        for (int i = 0; i < playerNumber; i++)
        {
            std::string teamName, cls;
            int id;
            std::cin>>id>>cls>>teamName>>x>>y;
            ret->addPlayer(id,x,y, teamName == "BARBARIAN" ? BARBARIANS : KNIGHTS, cls);
        }
        return ret;
    }