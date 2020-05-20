#include "Race.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

typedef std::pair<int, Car*> CarNode;

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
#include "Utilizer.h"
Race::Race(std::string race_name)
    {
        this->race_name = race_name;
        average_laptime = Laptime(Utilizer::generateAverageLaptime());
        head = NULL;
        totalLap = 0;
        totalCar = 0;
    }

Race::Race(const Race& rhs)
    {
        race_name = rhs.race_name;
        average_laptime = rhs.average_laptime;
        totalLap = 0;
        totalCar = rhs.totalCar;
        if (rhs.head == NULL)
        {
            head = NULL;
        }
        else
        {
            head = new Car(rhs.head->getDriverName(), rhs.head->getPerformance());
            Car *p = rhs.head->getNext();
            while (p != NULL)
            {
                head->addCar(new Car(p->getDriverName(), p->getPerformance()));
                p = p->getNext();
            }
            
        }
        
    }
Race::~Race()
    {
        /*if(head != NULL)
        {
            delete head;
        }
        head = NULL;*/
    }

std::string Race::getRaceName() const
    {
        return race_name;
    }

void Race::addCartoRace()
    {
        ++totalCar;
        static int index = 100;
        if (head == NULL)
        {
            head = new Car("Random Driver " + std::to_string(index++));
        }
        else
        {
            head->addCar(new Car("Random Driver " + std::to_string(index++)));
        }
        return;
    }

void Race::addCartoRace(Car& car)
    {
        ++totalCar;
        if (head == NULL)
        {
            head = &car;
        }
        else
        {
            head->addCar(&car);
        }
    }

int Race::getNumberOfCarsinRace()
    {
        return totalCar;
    }

void Race::goBacktoLap(int lap)
    {
        for (; totalLap > lap+1; totalLap--)
        {
            head->deLap();
        }
        arrangeCars();
    }

void Race::operator++()
    {
        Car *p = head;
        while (p != NULL)
        {
            p->Lap(average_laptime);
            p = p->getNext();
        }
        totalLap++;
        arrangeCars();
    }

void Race::operator--()
    {
        head->deLap();
        if (totalLap > 0)
        {
            totalLap--;
        }
        arrangeCars();
    }

Car Race::operator[](const int car_in_position)
    {
        Car *p = head;
        for (int i = 0; i < car_in_position; i++)
        {
            p = p->getNext();
        }
        return *p;
    }

Car Race::operator[](std::string driver_name)
    {
        Car *p = head;
        while (p->getDriverName() != driver_name)
        {
            p = p->getNext();
        }
        return *p;
    }

Race& Race::operator=(const Race& rhs)
    {
        totalLap = 0;
        race_name = "";
        average_laptime = Laptime(0);
        head = NULL;
        return *this;
    }

void Race::arrangeCars()
    {
        if (head == NULL)
        {
            return;
        }
        Car *p = head;
        std::vector<CarNode> v;
        while (p != NULL)
        {
            v.push_back(CarNode(p->getTotalTime(), p));
            p = p->getNext();
        }
        std::sort(v.begin(), v.end());
        head = v[0].second;
        p = head;
        for (size_t i = 1; i < v.size(); i++)
        {
            p->setNext(v[i].second);
            p = p->getNext();
        }
        p->setNext(NULL);
        
    }

int Race::numLength(int x) const
    {
        return (int)ceil(0.00000001 + log10((double)x));
    }
/*
     * Example:
     * 001--TUF--1:19.461--1:18.935--60:35.193--25
     * 002--UTA--1:19.335--1:18.335--60:37.321--18--1
     * 003--GRT--1:20.223--1:19.932--60:45.184--15
     * ...
     * 099--CEI--1:21.005--1:19.867--63:47.293
     * 100--ECH--1:23.213--1:21.331--64:00.123
*/
std::ostream& operator<<(std::ostream& os, const Race& race)
    {
        const static int pointTable[] = {0,25,18,15,12,10,8,6,4,2,1};
        Car *p = race.head, *fastestLap = race.head;
        int n = race.totalCar, carIndex = 1;
        int maxLen = race.numLength(n);
        while (p != NULL)
        {
            if (p->getFastest() < fastestLap->getFastest())
            {
                fastestLap = p;
            }
            p = p->getNext();
        }
        p = race.head;
        while (p != NULL)
        {
            for (int i = 0; i < (maxLen - race.numLength(carIndex)); i++)
            {
                os<<"0";
            }
            os<<carIndex<<"--";
            os<<*p;
            if (carIndex <= 10)
            {
                os<<"--"<<pointTable[carIndex];
                if (fastestLap == p)
                {
                    os<<"--1";
                }
            }
            else
            {
                os<<"--0";
            }
            
            
            os<<std::endl;
            p = p->getNext();
            carIndex++;
        }
        
        return os;
    }

void Race::setAvgLaptime(Laptime avg)
    {
        average_laptime = avg;
    }
void Race::setName(std::string newName)
    {
        race_name = newName;
    }

int Race::getTotalCar() const
    {
        return totalCar;
    }

Race::Race()
    {

    }

std::string Race::getBonus() const
    {
        Car *p = head, *fastest = head;
        while (p != NULL)
        {
            if (p->getFastest() < fastest->getFastest())
            {
                std::cout<<"new fastest "<<p->getDriverName()<<std::endl;
                fastest = p;
            }
            p = p->getNext();
        }
        return fastest->getDriverName();
    }