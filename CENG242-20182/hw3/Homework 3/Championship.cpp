#include "Championship.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

#include <vector>
#include <algorithm>
#include "Utilizer.h"

typedef std::pair<int, std::string> driverNode;

Championship::Championship()
    {
        races.resize(0);
    }

Championship::~Championship()
    {
        races.clear();
    }

Championship::Championship(const Championship& rhs)
    {
        races = rhs.races;
    }

void Championship::addNewRace(Race& race)
    {
        races.push_back(race);
    }

void Championship::addNewRace(std::string race_name)
    {
        races.push_back(Race(races[0]));
        races[races.size() - 1].setAvgLaptime(Laptime(Utilizer::generateAverageLaptime()));
        races[races.size() - 1].setName(race_name);
    }

void Championship::removeRace(std::string race_name)
    {
        for (auto i = races.begin(); i < races.end(); i++)
        {
            if (i->getRaceName() == race_name)
            {
                races.erase(i);
                return;
            }
        }
    }

void Championship::addLap(std::string race_name)
    {
        for (auto i = races.begin(); i < races.end(); i++)
        {
            if (i->getRaceName() == race_name)
            {
                ++(*i);
                return;
            }
        }
    }

Race& Championship::operator[](std::string race_name)
    {
        for (auto i = races.begin(); i < races.end(); i++)
        {
            if (i->getRaceName() == race_name)
            {
                return *i;
            }
        }
        return races[0];
    }

std::ostream& operator<<(std::ostream& os, const Championship& championship)
    {
        const static int pointTable[] = {25,18,15,12,10,8,6,4,2,1};
        int n = championship.races[0].getTotalCar();
        std::vector<driverNode> v;
        Race race = championship.races[0];
        std::string bonus = championship.races[0].getBonus();
        for (int i = 0; i < n; i++)
        {
            if (i < 10)
            {
                v.push_back(driverNode(pointTable[i], race[i].getDriverName()));
                if (race[i].getDriverName() == bonus)
                {
                    v[v.size()-1].first++;
                    //os<<"bonus alan "<<bonus<<" "<<i<<std::endl;
                }
                
            }
            else
            {
                v.push_back(driverNode(0, race[i].getDriverName()));
            }
        }
        int m = championship.races.size();
        for (int i = 1; i < m; i++)
        {
            Race race = championship.races[i];
            std::string bonus = championship.races[i].getBonus();
            for (int j = 0; j < n; j++)
            {
                if (j < 10)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (v[k].second == race[j].getDriverName())
                        {
                            v[k].first+=pointTable[j];
                            if (v[k].second == bonus)
                            {
                                v[k].first++;
                                //os<<"bonus alan "<<bonus<<" "<<j<<std::endl;
                            }
                            
                        }
                    }
                    
                }
                
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            v[i].first = -v[i].first;
        }
        
        std::sort(v.begin(), v.end());
        int maxLen = race.numLength(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (maxLen - race.numLength(i+1)); j++)
            {
                os<<"0";
            }
            os<<(i+1)<<"--";
            size_t surnameBegin = v[i].second.find_last_of(" ") + 1;
            std::string firstThree = v[i].second.substr(surnameBegin, 3);
            for (int i = 0; i < 3; i++)
            {
                if (firstThree[i] <= 'Z' && firstThree[i] >= 'A')
                {
                    os<<firstThree[i];
                }
                else
                {
                    os<<(char)(firstThree[i] + ('A' - 'a'));
                }            
            }
            os<<"--"<<-v[i].first<<std::endl;
        }
        
        return os;
    }