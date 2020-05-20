#include"Game.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
/*
Board board;
  unsigned int turnNumber;
  unsigned int maxTurnNumber;
  std::vector<Player*> players;

*/
#include <algorithm>

typedef std::pair<int, Player*> playerNode;

//Board(unsigned int _size, std::vector<Player*>* _players, Coordinate chest);
Game::Game(unsigned int maxTurnNumber, unsigned int boardSize, Coordinate chest): players(), board(boardSize,&players, chest), maxTurnNumber(maxTurnNumber)
    {
        turnNumber = 0;
    }

Game::~Game()
    {
        size_t n = players.size();
        for (size_t i = n-1; i > 0; i--)
        {
            delete players[i];
        }
        players.clear();
    }
//Player(unsigned int id,int x, int y, Team team);
void Game::addPlayer(int id, int x, int y, Team team, std::string cls)
    {
        if (cls == "ARCHER")
        {
            players.push_back(new Archer(id,x,y,team));
        }
        if (cls == "FIGHTER")
        {
            players.push_back(new Fighter(id,x,y,team));
        }
        if (cls == "PRIEST")
        {
            players.push_back(new Priest(id,x,y,team));
        }
        if (cls == "SCOUT")
        {
            players.push_back(new Scout(id,x,y,team));
        }
        if (cls == "TANK")
        {
            players.push_back(new Tank(id,x,y,team));
        }
        std::vector<playerNode> v;
        for (auto i = players.begin(); i < players.end(); i++)
        {
            v.push_back(playerNode(-((*i)->getID()),*i));
        }
        std::sort(v.begin(), v.end());
        players.resize(0);
        for (auto i = v.begin(); i < v.end(); i++)
        {
            players.push_back(i->second);
        }
    }

bool Game::isGameEnded()   
    {
        if (turnNumber >= maxTurnNumber)
        {
            std::cout<<"Game ended at turn "<<turnNumber<<". Maximum turn number reached. Knight victory."<<std::endl;
            return true;
        }
        std::vector<Player*> barbarPlayers, knightPlayers;
        for (auto i = players.begin(); i < players.end(); i++)
        {
            if ((*i)->getTeam() == BARBARIANS)
            {
                barbarPlayers.push_back(*i);
            }
            else
            {
                knightPlayers.push_back(*i);
            }
        }
        if (knightPlayers.size() <= 0)
        {
            std::cout<<"Game ended at turn "<<turnNumber<<". All knights dead. Barbarian victory."<<std::endl;
            return true;
        }
        if (barbarPlayers.size() <= 0)
        {
            std::cout<<"Game ended at turn "<<turnNumber<<". All barbarians dead. Knight victory."<<std::endl;
            return true;
        }
        for (auto i = barbarPlayers.begin(); i < barbarPlayers.end(); i++)
        {
            if ((*i)->getCoord().x == board.getChestCoordinates().x && (*i)->getCoord().y == board.getChestCoordinates().y)
            {
                std::cout<<"Game ended at turn "<<turnNumber<<". Chest captured. Barbarian victory."<<std::endl;
                return true;
            }
        }
        return false;   
    }

void Game::playTurn()
    {
        std::cout<<"Turn "<<(++turnNumber)<<" has started."<<std::endl;
        for (int i = players.size()-1; i>=0; --i)
        {
            //std::cout<<i<<std::endl;
            playTurnForPlayer(players[i]);
        }
    }

/**
   * Play a turn for the given player.
   * If the player is dead announce its death by printing the boardID of the player
   * as in "Player 07 died.". Remove that player from the board and release its resources.
   *
   * Each player has a goal list sorted by its priority for that player.
   * When a player plays a turn it iterates over its goal list and tries to take
   * an action. Valid actions are attack, move and heal. A player can take only
   * one action in a turn, and if there is no action it can take it stops and does nothing.
   * Before moving a player you must check if the coordinate to move is valid.
   * Meaning that, the coordinate is in the bounds of the board and there are no
   * players there.
   *
   * IMPORTANT NOTE: every usage of the word nearest is referencing smallest the manhattan
   * distance, which is formulated as (abs(x_1-x_2) + abs(y_1-y_2)). operator-
   * overloaded in Coordinate.h computes exactly that, so you can use that method to
   * calculate the distance between two coordinates.
   *
   * Below are the explanations for goals:
   *
   * ATTACK:
   *   - If there are any enemies in the attack range of the player attack to it.
   *     If there are more than 1 enemy in the range attack to the one with
   *     lowest ID. If there is no one to attack try the next goal.
   *
   * CHEST:
   *   - Move to the direction of the chest, if both vertical and horizontal moves
   *     are available, pick the horizontal one. If the horizontal move is blocked
   *     but the vertical move is not, move vertically. If all directions towards
   *     the chest is blocked try the next goal.
   *
   * TO_ENEMY:
   *   - Move towards the nearest enemy. If there are more than one enemies with the same distance
   *     move towards the one with the smallest ID. If both vertical and horizontal moves
   *     are available, pick the horizontal one. If an enemy is in the squares
   *     that the player can move or every move that brings the player closer to
   *     the selected enemy is blocked, try the next goal.
   *
   * TO_ALLY:
   *   - Move towards the nearest ally. If there are more than one allies with the same distance
   *     move towards the one with the smallest ID.  If both vertical and horizontal moves
   *     are available, pick the horizontal one. If an ally is in the squares
   *     that the player can move or every move that brings the player closer to
   *     the selected ally is blocked, try the next goal.
   *
   * HEAL:
   *   - If there are any allies in the healing range heal all of them. if there
   *     is no one to heal try the next goal.
   *
   *
   * @return the goal that the action was taken upon. NO_GOAL if no action was taken.
   */

bool Game::getCloser(Player *player, Coordinate coord)
    {
        std::vector<Coordinate> moveableCoord = player->getMoveableCoordinates();
        std::vector<Coordinate> coords;
        for (auto i = moveableCoord.begin(); i < moveableCoord.end(); i++)
        {
            if (board.isCoordinateInBoard(*i)==true && board.isPlayerOnCoordinate(*i)==false)
            {
                if((*i)-coord < player->getCoord() - coord)
                    coords.push_back(*i);
            }
        }
        if (coords.size() <= 0)
        {
            return false;
        }
        Coordinate nearest = coords[0];
        for (size_t i = 1; i < coords.size(); i++)
        {
            if (coord - coords[i] < coord - nearest)
            {
                nearest = coords[i];
            }
            else if (coord - coords[i] == coord - nearest && coords[i].x != player->getCoord().x)
            {
                nearest = coords[i];
            }
        }
        player->movePlayerToCoordinate(nearest);
        return true;
    }

Goal Game::playTurnForPlayer(Player* player)
    {
        //std::cout<<"Playing "<<player->getBoardID()<<std::endl;
        if (player->getHP() <= 0)
        {
            std::cout<<"Player "<<player->getBoardID()<<" has died."<<std::endl;
            for (size_t i = 0; i < players.size(); i++)
            {
                if (players[i]->getID() == player->getID())
                {
                    players.erase(players.begin()+i);
                    delete player;
                    return NO_GOAL;
                }
            }
        }
        std::vector<Goal> goals = player->getGoalPriorityList();
        goals.push_back(NO_GOAL);
        for (auto goal = goals.begin(); goal < goals.end(); goal++)
        {
            if (*goal == NO_GOAL)
            {
                return NO_GOAL;
            }
            if (*goal == ATTACK)
            {
                std::vector<Coordinate> attackableCoordinates = player->getAttackableCoordinates();
                Player *toBeAttacked = NULL;
                for (auto c = attackableCoordinates.begin(); c < attackableCoordinates.end(); c++)
                {
                    Player *tmp = board[*c];
                    if (tmp == NULL)
                    {
                        continue;
                    }
                    if (tmp->getTeam() == player->getTeam())
                    {
                        continue;
                    }
                    if (toBeAttacked == NULL || tmp->getID()<toBeAttacked->getID())
                    {
                        toBeAttacked = tmp;
                    }
                }
                if (toBeAttacked == NULL)
                {
                    continue;
                }
                player->attack(toBeAttacked);
                return ATTACK;                
            }
            if (*goal == CHEST)
            {
                if (getCloser(player, board.getChestCoordinates()) == true)
                {
                    return CHEST;
                }
            }
            if (*goal == HEAL)
            {
                std::vector<Coordinate> healableCoordinates = player->getHealableCoordinates();
                std::vector<Player*> playersToBeHealed;
                for (auto c = healableCoordinates.begin(); c < healableCoordinates.end(); c++)
                {
                    Player *tmp = board[*c];
                    if (tmp == NULL || tmp->getTeam() != player->getTeam())
                    {
                        continue;
                    }
                    playersToBeHealed.push_back(tmp);
                }
                if (playersToBeHealed.size() <= 0)
                {
                    continue;
                }
                for (auto i = playersToBeHealed.begin(); i < playersToBeHealed.end(); i++)
                {
                    player->heal(*i);
                }
                return HEAL;
            }
            if (*goal == TO_ALLY)
            {
                std::vector<Coordinate> moveableCoords = player->getMoveableCoordinates();
                bool flag = false;
                for (auto c = moveableCoords.begin(); c < moveableCoords.end(); c++)
                {
                    Player *tmp = board[*c];
                    if (tmp == NULL || tmp->getTeam() != player->getTeam())
                    {
                        continue;
                    }
                    else
                    {
                        flag = true;
                        break;
                    }
                    
                }
                if (flag == true)
                {
                    continue;
                }
                Player *nearest = NULL;
                for (auto i = players.begin(); i < players.end(); i++)
                {
                    if (*i == player || player->getTeam() != (*i)->getTeam())
                    {
                        continue;
                    }
                    int curDist = player->getCoord() - (*i)->getCoord();
                    int minDist = nearest == NULL ? -1 : player->getCoord() - nearest->getCoord();
                    if (nearest == NULL || curDist<minDist || (curDist == minDist && (*i)->getID()<nearest->getID()))
                    {
                        nearest = *i;
                    }
                }
                if (getCloser(player, nearest->getCoord()) == true)
                {
                    return TO_ALLY;
                }
                                                
            }
            if (*goal == TO_ENEMY)
            {
                std::vector<Coordinate> moveableCoords = player->getMoveableCoordinates();
                bool flag = false;
                for (auto c = moveableCoords.begin(); c < moveableCoords.end(); c++)
                {
                    Player *tmp = board[*c];
                    if (tmp == NULL || tmp->getTeam() == player->getTeam())
                    {
                        continue;
                    }
                    else
                    {
                        flag = true;
                        break;
                    }
                    
                }
                if (flag == true)
                {
                    continue;
                }
                Player *nearest = NULL;
                for (auto i = players.begin(); i < players.end(); i++)
                {
                    if (*i == player || player->getTeam() == (*i)->getTeam())
                    {
                        continue;
                    }
                    int curDist = player->getCoord() - (*i)->getCoord();
                    int minDist = nearest == NULL ? -1 : player->getCoord() - nearest->getCoord();
                    if (nearest == NULL || curDist<minDist || (curDist == minDist && (*i)->getID()<nearest->getID()))
                    {
                        nearest = *i;
                    }
                }
                if (getCloser(player, nearest->getCoord()) == true)
                {
                    return TO_ENEMY;
                }             
            }
        }
        //std::cout<<"Played "<<player->getBoardID()<<std::endl;
    }