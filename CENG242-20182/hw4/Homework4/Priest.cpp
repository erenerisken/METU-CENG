#include"Priest.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

/**
   * Attack damage 0
   * Heal power 50
   * Max HP 150
   * Goal Priorities -> {HEAL,TO_ALLY,CHEST} in decreasing order
   * Class abbreviation -> "pr" or "PR"
   * Can move to all adjacent squares, including diagonals.
   * Can heal all adjacent squares, including diagonals.
   *
   */
#include <algorithm>

int Priest::getAttackDamage() const
    {
        return 0;
    }

int Priest::getHealPower() const
    {
        return 50;
    }

int Priest::getMaxHP() const
    {
        return 150;
    }

std::vector<Goal> Priest::getGoalPriorityList()
    {
        std::vector<Goal> ret;
        ret.push_back(HEAL);
        ret.push_back(TO_ALLY);
        ret.push_back(CHEST);
        return ret;
    }

const std::string Priest::getClassAbbreviation() const
    {
        return team == BARBARIANS ? "PR" : "pr";
    }

std::vector<Coordinate> Priest::getAttackableCoordinates()
    {
        return std::vector<Coordinate>();
    }

std::vector<Coordinate> Priest::getMoveableCoordinates()
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

std::vector<Coordinate> Priest::getHealableCoordinates()
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