#include "Warehouse.h"

Warehouse::Warehouse(){}
        
void Warehouse::checkDate(){

}
    
Container* Warehouse::createContainer(bool pickContainer){
    Container* c;
    if(pickContainer == 0)
        c = new Container(car);
    else c = new Container(toolList);

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