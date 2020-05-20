#include"Fighter.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
  /**
   * Attack damage 100
   * Heal power 0
   * Max HP 400
   * Goal Priorities -> {ATTACK,TO_ENEMY,CHEST} in decreasing order
   * Class abbreviation -> "fi" or "FI"
   * Can move to adjacent up, down, left or right square
   * Can attack to adjacent up, down, left or right square
   *
   */
#include <algorithm>


int Fighter::getAttackDamage() const
    {
        return 100;
    }

int Fighter::getHealPower() const
    {
        return 0;
    }

int Fighter::getMaxHP() const
    {
        return 400;
    }

std::vector<Goal> Fighter::getGoalPriorityList()
    {
        std::vector<Goal> ret;
        ret.push_back(ATTACK);
        ret.push_back(TO_ENEMY);
        ret.push_back(CHEST);
        return ret;
    }

const std::string Fighter::getClassAbbreviation() const
    {
        return team == BARBARIANS ? "FI" : "fi";
    }

std::vector<Coordinate> Fighter::getAttackableCoordinates()
    {
        std::vector<Coordinate> ret;
        ret.push_back(Coordinate(coordinate.x,coordinate.y+1));
        ret.push_back(Coordinate(coordinate.x,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y));
        std::sort(ret.begin(), ret.end());
        return ret;
    }

std::vector<Coordinate> Fighter::getMoveableCoordinates()
    {
        std::vector<Coordinate> ret;
        ret.push_back(Coordinate(coordinate.x,coordinate.y+1));
        ret.push_back(Coordinate(coordinate.x,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y));
        std::sort(ret.begin(), ret.end());
        return ret;
    }

std::vector<Coordinate> Fighter::getHealableCoordinates()
    {
        return std::vector<Coordinate>();
    }