#include"Scout.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
/**
   * Attack damage 25
   * Heal power 0
   * Max HP 125
   * Goal Priorities -> {CHEST,TO_ALLY,ATTACK} in decreasing order
   * Class abbreviation -> "sc" or "SC"
   * Can move to all adjacent squares, including diagonals.
   * Can attack all adjacent squares, including diagonals.
   *
   */
#include <algorithm>

int Scout::getAttackDamage() const
    {
        return 25;
    }

int Scout::getHealPower() const
    {
        return 0;
    }

int Scout::getMaxHP() const
    {
        return 125;
    }

std::vector<Goal> Scout::getGoalPriorityList()
    {
        std::vector<Goal> ret;
        ret.push_back(CHEST);
        ret.push_back(TO_ALLY);
        ret.push_back(ATTACK);
        return ret;
    }

const std::string Scout::getClassAbbreviation() const
    {
        return team == BARBARIANS ? "SC" : "sc";
    }

std::vector<Coordinate> Scout::getAttackableCoordinates()
    {
        std::vector<Coordinate> ret;
        ret.push_back(Coordinate(coordinate.x,coordinate.y+1));
        ret.push_back(Coordinate(coordinate.x,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y+1));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y+1));
        std::sort(ret.begin(), ret.end());
        return ret;
    }

std::vector<Coordinate> Scout::getMoveableCoordinates()
    {
        std::vector<Coordinate> ret;
        ret.push_back(Coordinate(coordinate.x,coordinate.y+1));
        ret.push_back(Coordinate(coordinate.x,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y+1));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y+1));
        std::sort(ret.begin(), ret.end());
        return ret;
    }

std::vector<Coordinate> Scout::getHealableCoordinates()
    {
        return std::vector<Coordinate>();
    }