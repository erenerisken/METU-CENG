#include"Player.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Player::Player(unsigned int id,int x, int y, Team team) : id(id), coordinate(x,y), team(team){}

unsigned int Player::getID() const
    {
        return id;
    }

const Coordinate& Player::getCoord() const
    {
        return coordinate;
    }

int Player::getHP() const
    {
        return HP;
    }

Team Player::getTeam() const
    {
        return team;
    }

std::string Player::getBoardID()
    {
        return id<10 ? "0" + std::to_string(id) : std::to_string(id);
    }

bool Player::attack(Player *enemy)
    {
        std::cout<<"Player "<<getBoardID()<<" attacked Player "<<enemy->getBoardID()<<" ("<<getAttackDamage()<<")"<<std::endl;
        enemy->HP-=getAttackDamage();
        return enemy->isDead();
    }

void Player::heal(Player *ally)
    {
        std::cout<<"Player "<<getBoardID()<<" healed Player "<<ally->getBoardID()<<std::endl;
        ally->HP+=getHealPower();
        if (ally->HP > ally->getMaxHP())
        {
            ally->HP = ally->getMaxHP();
        }        
    }

void Player::movePlayerToCoordinate(Coordinate c)
    {
        std::cout<<"Player "<<getBoardID()<<" moved from "<<coordinate<<" to "<<c<<std::endl;
        coordinate = c;
        return;
    }

bool Player::isDead() const
    {
        return HP <= 0;
    }



