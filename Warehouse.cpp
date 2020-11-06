#include "Warehouse.h"

Warehouse::Warehouse(F1Car* _car, RacingEvent* _raceList, Date _date, int _teamId) :
    car(_car), raceList(_raceList), date(_date), teamId(_teamId){}
        
void Warehouse::checkDate(){

}
    
Container* Warehouse::createContainer(bool raceType,bool pickContainer){
    Container* c;
    if(pickContainer == 0)
        c = new Container(raceType,car, teamId);
    else c = new Container(raceType,toolList, teamId);

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