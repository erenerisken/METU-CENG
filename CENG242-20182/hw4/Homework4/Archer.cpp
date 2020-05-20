#include"Archer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

#include <algorithm>

int Archer::getAttackDamage() const
    {
        return 50;
    }

int Archer::getHealPower() const
    {
        return 0;
    }

int Archer::getMaxHP() const
    {
        return 200;
    }

std::vector<Goal> Archer::getGoalPriorityList()
    {
        std::vector<Goal> ret;
        ret.push_back(ATTACK);
        return ret;
    }

const std::string Archer::getClassAbbreviation() const
    {
        return team == BARBARIANS ? "AR" : "ar";
    }

std::vector<Coordinate> Archer::getAttackableCoordinates()
    {
        std::vector<Coordinate> ret;
        ret.push_back(Coordinate(coordinate.x,coordinate.y+1));
        ret.push_back(Coordinate(coordinate.x,coordinate.y+2));
        ret.push_back(Coordinate(coordinate.x,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x,coordinate.y-2));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y));
        ret.push_back(Coordinate(coordinate.x+2,coordinate.y));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y));
        ret.push_back(Coordinate(coordinate.x-2,coordinate.y));
        std::sort(ret.begin(), ret.end());
        return ret;
    }

std::vector<Coordinate> Archer::getMoveableCoordinates()
    {
        return std::vector<Coordinate>();
    }

std::vector<Coordinate> Archer::getHealableCoordinates()
    {
        return std::vector<Coordinate>();
    }