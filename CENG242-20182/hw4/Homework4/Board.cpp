#include"Board.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Board::Board(unsigned int _size, std::vector<Player*>* _players, Coordinate chest):size(_size), players(_players), chest(chest) {};

Board::~Board()
    {

    }

bool Board::isCoordinateInBoard(const Coordinate& c)
    {
        return (c.x>=0 && c.x<size) && (c.y>=0 && c.y<size);
    }

bool Board::isPlayerOnCoordinate(const Coordinate& c)
    {
        for (auto i = players->begin(); i < players->end(); i++)
        {
            Coordinate tmp = (*i)->getCoord();
            if (tmp.x == c.x && tmp.y == c.y)
            {
                return true;
            }
        }
        return false;
    }

Player* Board::operator [](const Coordinate& c)
    {
        for (auto i = players->begin(); i < players->end(); i++)
        {
            Coordinate tmp = (*i)->getCoord();
            if (tmp.x == c.x && tmp.y == c.y)
            {
                return *i;
            }
        }
        return NULL;
    }

Coordinate Board::getChestCoordinates()
    {
        return chest;
    }

/**
	  * Print the board with character ID's.
	  * For each empty square print two underscore characters.
		* For the squares with a player on it, print the board id of the player.
		* For the square with the chest, print the string "Ch".
		* If a character is on the square with the chest, only print the ID of the
		* character.
		* For each row print a new line, for each column print a space character.
		* Example:
		* __ __ 01 __
		* __ 02 __ 05
		*	Ch __ __ 03
		*	__ __ __ __
	  */
void Board::printBoardwithID() 
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                Coordinate c(j,i);
                Player* tmp = (*this)[c];
                if (tmp == NULL)
                {
                    if (chest.x == j && chest.y == i)
                    {
                        std::cout<<"Ch";
                    }
                    else                    
                        std::cout<<"__";
                }
                else
                {
                    std::cout<<tmp->getBoardID();
                }
                std::cout<<" ";
            }
            std::cout<<std::endl;
        }
    }

void Board::printBoardwithClass() 
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                Coordinate c(j,i);
                Player* tmp = (*this)[c];
                if (tmp == NULL)
                {
                    if (chest.x == j && chest.y == i)
                    {
                        std::cout<<"Ch";
                    }
                    else                    
                        std::cout<<"__";
                }
                else
                {
                    std::cout<<tmp->getClassAbbreviation();
                }
                std::cout<<" ";
            }
            std::cout<<std::endl;
        }
    }