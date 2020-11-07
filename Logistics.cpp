#include "Logistics.h"

Logistics::Logistics(RacingEvent** raceList, F1Car* car ){
    warehouse = new Warehouse(car, raceList, date);
    transport = new Transport*[2];//idx = 0 -> ship/truck, idx = 1 -> plane
    container = new Container*[2];//idx = 0 -> tools, idx = 1 -> car
}
        
Logistics::~Logistics(){
    delete warehouse;
    warehouse = null;

    for(int i=0; i<2; i++){
        delete [] transport[i];
        delete [] container[i];
    }

    delete transport;
    delete container;
}

void Logistics::run(Date date,int id){
    int difference;
    for(int i = 0; i< 25 ; i++){
        monthDiff = warehouse->getRacingEvent()[i]->getRaceTrack()->getDate()->getMonth() - date.getMonth();
        dayDiff = warehouse->getRacingEvent()[i]->getRaceTrack()->getDate()->getDay() - date.getDay();
        //1 = transported, 0= not transported
        if(monthDiff == 3 && warehouse->getRacingEvent()[i]->getRaceTrack()->inEurop() == 1){ // edit depending on where type attribte is
            if(toolsTransported[i] == 0){// 1 = nonEurpean
                container[0] = warehouse->createContainer(1,1, id,warehouse->getRacingEvent()[i] );
                transport[0] = new Ship();
                toolsTransport[i] = 1;
                container[0] = transport[0]->Transport(container[0]);
            }
            container[0] = transport[0]->Transport(container[0]);
                
                //container[0] = transport[0]->Transport(container[0]);
        }else if(monthDiff <= 1 && ((dayDiff >= -24 && dayDiff <= -21) || dayDiff == 7)){
            if(toolsTransported[i] == 0){
                container[0] = warehouse->createContainer(0,1, id, warehouse->getRacingEvent()[i]);
                transport[0] = new Truck();
                toolsTransport[i] = 1;
            }
            container[0] = transport[0]->Transport(container[0]);
        }else if(monthDiff <= 1 && ((dayDiff >= -30 && dayDiff <= -27) || dayDiff == 1)){
            if(carTransported[i] == 0){
                if(warehouse->getRacingEvent()[i]->getRaceTrack()->inEurop() == 1)
                    type = 1;
                else type = 0;
                    container[1] = warehouse->createContainer(type,0, id, warehouse->getRacingEvent()[i]);
                    transport[1] = new Plane();
                    carTransported[i] = 1;
                    
            }
            container[1] = transport[1]->Transport(container[1]);
        }
    } 
    //need to simulate time that has passed while in transit

}