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
        delete transport[i];
        delete container[i];
    }

    delete [] transport;
    delete [] container;
}

void Logistics::run(Date date,int id){
    int monthDiff, dayDiff;
    bool inEuro;
    for(int i = 0; i< 30 && warehouse->getRacingEvent()[i] != nullptr ; i++){
        monthDiff = warehouse->getRacingEvent()[i]->getRaceTrack()->getDate()->getMonth() - date.getMonth();
        dayDiff = warehouse->getRacingEvent()[i]->getRaceTrack()->getDate()->getDay() - date.getDay();
        //1 = transported, 0= not transported
        inEuro = warehouse->getRacingEvent()[i]->getRaceTrack()->inEurop();
        if(monthDiff <= 3 && inEuro == false){
            if(toolsTransported[i] == false){
                container[0] = warehouse->createContainer(1,1, id,warehouse->getRacingEvent()[i] );
                transport[0] = new Ship(container[0]);
                toolsTransport[i] = 1;
            }
            transport[0]->Transport(container[0]);
                
        }else if(monthDiff <= 1 && ((dayDiff >= -24 && dayDiff <= -21) || dayDiff <= 7)){
            if(toolsTransported[i] == false){
                container[0] = warehouse->createContainer(0,1, id, warehouse->getRacingEvent()[i]);
                transport[0] = new Truck(container[0]);
                toolsTransport[i] = 1;
            }
            transport[0]->Transport(container[0]);
        }else if(monthDiff <= 1 && ((dayDiff >= -30 && dayDiff <= -27) || dayDiff == 1)){
            if(carTransported[i] == false){
                if(inEuro == true)
                    type = 1;
                else type = 0;
                    container[1] = warehouse->createContainer(type,0, id, warehouse->getRacingEvent()[i]);
                    transport[1] = new Plane(container[1]);
                    carTransported[i] = 1;
                    
            }
            container[1] = transport[1]->Transport(container[1]);
        }
    } 
    //need to simulate time that has passed while in transit

}