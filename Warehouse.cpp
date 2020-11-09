#include "Warehouse.h"

Warehouse::Warehouse(F1Car** _cars, RacingEvent** _raceList, Driver** _drivers) :
    cars(_cars), raceList(_raceList), drivers(_drivers){
        toolList = {"Pit-box","Air Gun (Impact Wrench)","Air Compressor","Jack","Piano Bars","Fuel Cans","Duct Tape","BearBond"}
    cars[0]->setLocation("Factory");
    cars[1]->setLocation("Factory");
}

Warehouse::~Warehouse(){
    delete F1Car;
    for(int i = 0; i<30 && raceList[i] != nullptr; i++){
        delete raceList[i];
    }

    delete [] raceList;
}
        
Container* Warehouse::createContainer(bool raceType,bool pickContainer, int teamId, RacingEvent* race){
    Container* c;
    if(pickContainer == 0)
        c = new Container(raceType,cars, drivers, teamId, race);
    else c = new Container(raceType,toolList, cars->getStrategy()->getNewTires(),teamId, race);

    return c;
}
    
void Warehouse::reinstateContainer(Container* container){
    if(container->getContainerType() == "car"){
        cars = container->getCar();
        drivers = container->getDrivers();
        cars[0]->setLocation("Factory");
        cars[1]->setLocation("Factory");
    }
    else {
        for(int i = 0; i<container->getTools().size(); i++){
            toolList[i] = container->getTools()[i];
        }
    }
}
    
void Warehouse::setRacingEvent(RacingEvent* list){
    raceList = list;
}
    
RacingEvent* Warehouse::getRacingEvent(){
    return list;
}
    
void Warehouse::setDate(Date date){
    currDate = date;
}
        
void Warehouse::setCar(F1Car* car){
    this.car = car;
}

void Warehouse::setTools(string[] tools){
    for(int i = 0; i<tools.size(); i++){
        toolList[i] = tools[i];
    }
}