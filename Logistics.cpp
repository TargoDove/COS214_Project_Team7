#include "Logistics.h"

//Your method is called from within this method -> "void F1Team::update(Date date)"
//Please can you look at the new Garage and AssembledCar classes and update
//logistics to work with those
//Since each F1Team has two cars competing in each race, two cars will need to be 
//transported along with two Drivers (these will be by plane)
//You will be able to get an array of 5 Tire ptrs (Tire*) by 
//calling: car->getStrategy()->getNewTireSets()
//I haven't implemented the method yet but I will tomorrow. Its return type will be "Tire**"

//When the F1Car is at home its "location" should be set to "Factory"
//When the F1Car is on the plane (in the container), its "location" should be set to "In Transit"
//When the F1Car is in the AssembledCar, its "location" should be set to "(Race Name)"

//The day after the Race is finished, we need to transport the Drivers and F1Cars back to the factory
//Either Logistics need to check when it is 1 day after the end of the race 
//or the Garage or Race needs a way of asking Logistics to fly the Cars/Drivers back (possible command pattern??)
//Please give it some thought

//Also just check your method calls below as I have change "RaceTrack::getDate()" to "RaceTrack::getStartDate()" and added "RaceTrack::getEndDate()"

Logistics::Logistics(RacingEvent** raceList, F1Car** cars, Driver** drivers ){
    warehouse = new Warehouse(car, raceList, drivers);
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

void Logistics::

void Logistics::run(Date date,int id){
    int monthDiff, dayDiff;
    bool inEuro;
    for(int i = 0; i< 30 && warehouse->getRacingEvent()[i] != NULL ; i++){
        monthDiff = warehouse->getRacingEvent()[i]->getStartDate()->getMonth() - date.getMonth();
        dayDiff = warehouse->getRacingEvent()[i]->getStartDate()->getDay() - date.getDay();
        endDayDiff = date.getDay() - warehouse->getRacingEvent()[i]->getEndDate()->getDay();
        endMonthDiff = date.getMonth() - warehouse->getRacingEvent()[i]->getEndDate()->getMonth();
        //1 = transported, 0= not transported
        inEuro = warehouse->getRacingEvent()[i]->getRaceTrack()->inEurop();
        if(monthDiff <= 3 && inEuro == false){
            if(toolsTransported[i] == false){
                container[0] = warehouse->createContainer(1,1, id,warehouse->getRacingEvent()[i] );
                transport[0] = new Ship(container[0]);
                toolsTransport[i] = 1;
            }
            transport[0]->Transport(container[0]);
                
        }else if((monthDiff == 1  || monthDiff == 0)){
            if((dayDiff >= -24 && dayDiff <= -21) || dayDiff <= 7){
                if(toolsTransported[i] == false){
                    container[0] = warehouse->createContainer(0,1, id, warehouse->getRacingEvent()[i]);
                    transport[0] = new Truck(container[0]);
                    toolsTransport[i] = 1;
                }
                transport[0]->Transport(container[0]);
            }else if((dayDiff >= -30 && dayDiff <= -27) || dayDiff == 1){
                if(carTransported[i] == false){
                    if(inEuro == true)
                        type = 1;
                    else type = 0; //use brackets else only the first line will be executed
                    container[1] = warehouse->createContainer(type,0, id, warehouse->getRacingEvent()[i]);
                    transport[1] = new Plane(container[1]);
                    carTransported[i] = 1;
                    
                }
                container[1] = transport[1]->Transport(container[1]);
            }
        }else if((endMonthDiff == 1 || endMonthDiff == 0) && ((endDayDiff >= -30 && endDayDiff <= -27) || endDayDiff == 1)){
            warehouse->reinstateContainer(transport[1]->returnCars());
        }
    } 
    //need to simulate time that has passed while in transit

}