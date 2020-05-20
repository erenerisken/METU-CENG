#include "Car.h"
#include <iostream>

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

#include "Utilizer.h"


Car::Car(std::string driver_name)
    {
        this->driver_name = driver_name;
        performance = Utilizer::generatePerformance();
        totalTime = 0;
        next = NULL;
        head = NULL;
        mini = 0;
        maxi = 0;
    }

Car::Car(std::string driver_name, double performance)
    {
        this->driver_name = driver_name;
        this->performance = performance;
        totalTime = 0;
        next = NULL;
        head = NULL;
        mini = 0;
        maxi = 0;
    }

Car::Car(const Car& rhs)
    {
        driver_name = rhs.driver_name;
        performance = rhs.performance;
        totalTime = rhs.totalTime;
        maxi = rhs.maxi;
        mini = rhs.mini;
        if (rhs.next == NULL)
        {
            next = NULL;
        }
        else
        {
            next = new Car(*(rhs.next));
        }
        if (rhs.head == NULL)
        {
            head = NULL;
        }
        else
        {
            head = new Laptime(*(rhs.head));
        }
   }

Car::~Car()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
        /*if (next != NULL)
        {
            delete next;
            next = NULL;
        } */  
    }

std::string Car::getDriverName() const
    {
        return driver_name;
    }

double Car::getPerformance() const 
    {
        return performance;
    }

Car* Car::getNext()
    {
        return next;
    }

void Car::addCar(Car *next)
    {
        Car *p = this;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = next;        
    }

bool Car::operator<(const Car& rhs) const
    {
        return totalTime < rhs.totalTime;
    }
bool Car::operator>(const Car& rhs) const
    {
        return totalTime > rhs.totalTime;
    }

Laptime Car::operator[](const int lap) const
    {
        Laptime *p = head;
        for (int i = 0; i < lap; i++)
        {
            if (p == NULL)
            {
                return Laptime(0);
            }
            p = p->getNext();
        }
        return p == NULL ? Laptime(0) : *p;
    }

void Car::Lap(const Laptime& average_laptime)
    {
        Laptime toAdd(Laptime(Utilizer::generateLaptimeVariance(performance)) + average_laptime);
        int x = toAdd.getTime();
        totalTime += x;
        if (mini == 0 || x < mini)
        {
            mini = x;
        }
        
        //std::cout<<"lap:"<<x<<std::endl;
        if (head == NULL)
        {
            head = new Laptime(x);
        }
        else
        {
            head->addLaptime(new Laptime(x));
        }
    }
//HAM--1:19.235--1:18.832--90:03.312
std::ostream& operator<<(std::ostream& os, const Car& car)
    {
        size_t surnameBegin = car.driver_name.find_last_of(" ") + 1;
        std::string firstThree = car.driver_name.substr(surnameBegin, 3);
        std::pair<Laptime, Laptime> minMax = car.head->getMinMax();
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
        os<<"--"<<minMax.second<<"--"<<minMax.first<<"--"<<Laptime(car.totalTime);
        return os;
    }

void Car::deLap()
    {
        if (head == NULL)
        {
            return;
        }
        
        if(head->getNext() == NULL)
        {
            delete head;
            head = NULL;
            totalTime = 0;
            if (next != NULL)
            {
                next->deLap();
            }
            return;
        }
        Laptime *p = head;
        while (p->getNext()->getNext() != NULL)
        {
            p = p->getNext();
        }
        Laptime *toBeDeleted = p->getNext();
        totalTime -= toBeDeleted->getTime();
        delete toBeDeleted;
        p->setNext(NULL);
        if (next != NULL)
        {
            next->deLap();
        }
        return;
    }

int Car::getFastest()
    {
        if (head == NULL)
        {
            return 0;
        }
        //std::cout<<driver_name<<" fastest "<<mini<<std::endl;
        return head->getMinMax().first.getTime();
    }

void Car::setNext(Car *tmp)
    {
        next = tmp;
    }

int Car::getTotalTime()
    {
        return totalTime;
    }