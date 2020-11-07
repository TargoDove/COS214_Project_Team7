#include "Warehouse.h"

Warehouse::Warehouse(F1Car* _car, RacingEvent** _raceList) :
    car(_car), raceList(_raceList){
        toolList = {"Pit-box","Air Gun (Impact Wrench)","Air Compressor","Jack","Piano Bars","Fuel Cans","Duct Tape","BearBond"}
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
        c = new Container(raceType,car, teamId, race);
    else c = new Container(raceType,toolList, teamId, race);

    return c;
}
    
void Warehouse::reinstateContainer(Container* container){
    if(container->getContainerType() == "car")
        car = container->getCar();
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