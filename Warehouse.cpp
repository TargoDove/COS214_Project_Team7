#include "Warehouse.h"

Warehouse::Warehouse(F1Car** _cars, RacingEvent** _raceList, Driver** _drivers)
{
    cars = _cars;
    raceList = _raceList;
    drivers = _drivers;
    string tool[8] = {"Pit-box","Air Gun (Impact Wrench)","Air Compressor","Jack","Piano Bars","Fuel Cans","Duct Tape","BearBond"};
    toolList = tool; 
    cars[0]->setLocation("Factory");
    cars[1]->setLocation("Factory");
}

Warehouse::~Warehouse(){
    for(int i = 0; i<2;i++){
        delete cars[i];
        delete drivers[i];
    }

    delete [] cars;
    delete [] drivers;
    for(int i = 0; i<30 && raceList[i] != nullptr; i++){
        delete raceList[i];
    }

    delete [] raceList;
}
        
Container* Warehouse::createContainer(bool raceType,bool pickContainer, int teamId, RacingEvent* race){
    Container* c;
    if(pickContainer == 0)
        c = new Container(raceType,cars, drivers, teamId, race);
    else c = new Container(raceType,toolList, cars[0]->getStrategy()->getNewTireSets(),cars[1]->getStrategy()->getNewTireSets(),teamId, race);

    return c;
}
    
void Warehouse::reinstateContainer(Container* container){
    if(container->getContainerType() == "car"){
        cars = container->getCars();
        drivers = container->getDrivers();
        cars[0]->setLocation("Factory");
        cars[1]->setLocation("Factory");
    }
    else {
        for(int i = 0; i<8; i++){
            toolList[i] = container->getTools()[i];
        }
    }
}
    
void Warehouse::setRacingEvent(RacingEvent** list){
    raceList = list;
}
    
RacingEvent** Warehouse::getRacingEvent(){
    return raceList;
}
        
void Warehouse::setCars(F1Car** car){
    this->cars = car;
}

void Warehouse::setTools(string* tools){
    for(int i = 0; i<8; i++){
        toolList[i] = tools[i];
    }
}