#include <iostream>
#include "Laptime.h"
#include "Car.h"
#include "Race.h"
#include "Championship.h"
#include <cstdlib>
using namespace std;
int main(void) {
    /**********************************************/
    /************** LAPTIME TEST ******************/
    /**********************************************/
    Laptime small(87625);
    Laptime large(188524);

    if(small<large)
        cout<<small<<endl<<endl;
    else
        cout<<"ERROR"<<endl<<endl;

    if(large>small)
        cout<<large<<endl<<endl;
    else
        cout<<"ERROR"<<endl<<endl;
    //cout<<small;
    small = large+small;
    small.addLaptime(new Laptime(3));
    small.addLaptime(new Laptime(14));
    small.addLaptime(new Laptime(10));
    small.addLaptime(new Laptime(10000000));
    small.addLaptime(new Laptime(25));
    Laptime small2(small);
    pair<Laptime, Laptime> minMax = small.getMinMax();
    cout<<"small "<<small<<"--"<<*(small.getNext()->getNext())<<endl;
    cout<<"small2 "<<small2<<"--"<<*(small2.getNext()->getNext())<<endl;
    cout<<"large "<<large<<endl;
    cout<<minMax.first<<"--"<<minMax.second<<endl;
    
    //************** CAR AND RACE TEST *************

    cout<<"CREATING CARS"<<endl<<endl;
    Car alonso("Fernando Alonso");
    Car hamilton("Lewis Hamilton");
    Car vettel("Sebastian Vettel");
    Car leclerc("Charles Leclerc");
    Car bottas("Valtteri Bottas");
    Car verstappen("Max Verstappen");
    Car gasly("Pierre Gasly");
    Car hulkenberg("Nico Hulkenberg");
    Car ricciardo("Daniel Ricciardo");
    Car raikkonen("Kimi Raikkonen");
    Car giovinazzi("Antonio Giovinazzi");
    

    cout<<"CREATING a RACE NAMED BAKU"<<endl<<endl;
    Race baku("baku");
    cout<<"RACE CREATED"<<endl<<endl;
    baku.addCartoRace(alonso);
    baku.addCartoRace(hamilton);
    baku.addCartoRace(vettel);
    baku.addCartoRace(leclerc);
    baku.addCartoRace(bottas);
    baku.addCartoRace(verstappen);
    baku.addCartoRace(gasly);
    baku.addCartoRace(hulkenberg);
    baku.addCartoRace(ricciardo);
    baku.addCartoRace(raikkonen);
    baku.addCartoRace(giovinazzi);
    
    cout<<"NUMBER OF CARS"<<endl<<endl;
    cout<<baku.getNumberOfCarsinRace()<<endl;

    cout<<"PREFIX TEST"<<endl<<endl;
    ++baku;

    cout<<"OSTREAM TEST"<<endl<<endl;;
    cout<<baku<<endl<<endl;

    for(int i = 0;i<55;i++) {
        ++baku;
    }

    cout<<"INDEXING"<<endl;
    cout<<baku[0][0]<<endl<<endl;

    cout<<"AFTER MANY LAPS"<<endl<<endl;
    cout<<baku<<endl<<endl;

    cout<<"GO BACK TEST"<<endl;
    baku.goBacktoLap(0);
    cout<<baku<<endl<<endl;
    cout<<baku["Kimi Raikkonen"]<<endl;

    //************** CHAMPIONSHIP TEST *************
    cout<<"CHAMPIONSHIP"<<endl<<endl;
    Championship champ;

    cout<<"ADD baku"<<endl<<endl;
    //Race tmp(baku);
    champ.addNewRace(baku);
    
    cout<<"OSTREAM TEST"<<endl<<endl;
    cout<<champ<<endl;


    cout<<"ADDING NEW RACE China"<<endl<<endl;
    champ.addNewRace("china");
    for(int i = 0; i<25 ;i++) {
        champ.addLap("china");
    }
    cout<<"China RACE RESULST"<<endl<<endl;
    cout<<champ["china"]<<endl<<endl;


    cout<<"Overall Championship Results"<<endl<<endl;
    cout<<champ<<endl;
    
    cout<<"END OF TEST"<<endl;
    system("PAUSE");

}