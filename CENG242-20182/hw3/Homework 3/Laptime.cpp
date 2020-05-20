#include "Laptime.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

Laptime::Laptime(int laptime)
    {
        this->laptime = laptime;
        next = NULL;
    }

Laptime::Laptime(const Laptime& rhs)
    {
        laptime = rhs.laptime;
        if (rhs.next == NULL)
        {
            next = NULL;
        }
        else
        {
            next = new Laptime(*(rhs.next));
        }
        
        
    }
Laptime::Laptime()
    {
        laptime = 0;
        next = NULL;
    }
Laptime::~Laptime()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }

void Laptime::addLaptime(Laptime *next)
    {
        Laptime *p = this;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = next;
        return;
    }

bool Laptime::operator<(const Laptime& rhs) const
    {
        return laptime < rhs.laptime;
    }

bool Laptime::operator>(const Laptime& rhs) const
    {
        return laptime > rhs.laptime;
    }

Laptime& Laptime::operator+(const Laptime& rhs)
    {
        laptime+=rhs.laptime;
        return *this;
    }

std::ostream& operator<<(std::ostream& os, const Laptime& laptime)
    {
        int time = laptime.laptime;
        int minute = time/(60*1000);
        time %= (60*1000);
        int second = time / 1000;
        time %= 1000;

        os << minute << ":";

        if (second < 10)
        {
            os << "0";
        }
        
        os << second << ".";
        
        if (time < 100)
        {
            os << "0";
            if (time < 10)
            {
                os << "0";
            }
        }
        
        os << time;

        return os;
    }

int Laptime::getTime() const
    {
        return laptime;
    }
Laptime* Laptime::getNext() const
    {
        return next;
    }

std::pair<Laptime, Laptime> Laptime::getMinMax()
    {
        Laptime *mini = this, *maxi = this, *p = next;
        while (p != NULL)
        {
            if (*p < *mini)
            {
                mini = p;
            }
            maxi = p;
            p = p->next;
        }
        return std::pair<Laptime, Laptime>(*mini, *maxi);
    }

void Laptime::setNext(Laptime *tmp)
    {
        next = tmp;
    }