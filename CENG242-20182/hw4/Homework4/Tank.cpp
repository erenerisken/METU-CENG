#include"Tank.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
/**
   * Attack damage 25
   * Heal power 0
   * Max HP 1000
   * Goal Priorities -> {TO_ENEMY,ATTACK,CHEST} in decreasing order
   * Class abbreviation -> "ta" or "TA"
   * Can move to adjacent up, down, left or right square
   * Can attack to adjacent up, down, left or right square
   *
   */
#include <algorithm>

int Tank::getAttackDamage() const
    {
        return 25;
    }

int Tank::getHealPower() const
    {
        return 0;
    }

int Tank::getMaxHP() const
    {
        return 1000;
    }

std::vector<Goal> Tank::getGoalPriorityList()
    {
        std::vector<Goal> ret;
        ret.push_back(TO_ENEMY);
        ret.push_back(ATTACK);
        ret.push_back(CHEST);
        return ret;
    }

const std::string Tank::getClassAbbreviation() const
    {
        return team == BARBARIANS ? "TA" : "ta";
    }

std::vector<Coordinate> Tank::getAttackableCoordinates()
    {
        std::vector<Coordinate> ret;
        ret.push_back(Coordinate(coordinate.x,coordinate.y+1));
        ret.push_back(Coordinate(coordinate.x,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y));
        std::sort(ret.begin(), ret.end());
        return ret;
    }

std::vector<Coordinate> Tank::getMoveableCoordinates()
    {
        std::vector<Coordinate> ret;
        ret.push_back(Coordinate(coordinate.x,coordinate.y+1));
        ret.push_back(Coordinate(coordinate.x,coordinate.y-1));
        ret.push_back(Coordinate(coordinate.x+1,coordinate.y));
        ret.push_back(Coordinate(coordinate.x-1,coordinate.y));
        std::sort(ret.begin(), ret.end());
        return ret;
    }

std::vector<Coordinate> Tank::getHealableCoordinates()
    {
        return std::vector<Coordinate>();
    }