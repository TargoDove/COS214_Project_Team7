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
    warehouse = new Warehouse(cars, raceList, drivers);
    transport = new Transportation*[2];//idx = 0 -> ship/truck, idx = 1 -> plane
    container = new Container*[2];//idx = 0 -> tools, idx = 1 -> car
}
        
Logistics::~Logistics(){
    delete warehouse;
    warehouse = nullptr;

    for(int i=0; i<2; i++){
        delete transport[i];
        delete container[i];
    }

    delete [] transport;
    delete [] container;
}

void Logistics::run(Date date,int id){
    int monthDiff, dayDiff,  endDayDiff,  endMonthDiff, type;
    bool inEuro;
    for(int i = 0; i< 30 && warehouse->getRacingEvent()[i] != NULL ; i++){
        Date startDate = warehouse->getRacingEvent()[i]->getStartDate();
        monthDiff = startDate.getMonth() - date.getMonth();
        dayDiff = startDate.getDay() - date.getDay();
        
        Date endDate = warehouse->getRacingEvent()[i]->getEndDate();
        endDayDiff = date.getDay() - endDate.getDay();
        endMonthDiff = date.getMonth() - endDate.getMonth();
        inEuro = warehouse->getRacingEvent()[i]->getRaceTrack()->inEurope();


        //Start to transport if there is a Non European race 3 months away and the tools havent yet been transported.
        //Still call the transport function if there is non european race <= 3 months away and the tools are already in transit. This is done to track the container
        if(monthDiff <= 3 && inEuro == false){  
            if(toolsTransported[i] == false){
                container[0] = warehouse->createContainer(1,1, id,warehouse->getRacingEvent()[i] );//1 = toolsContainer, 1= non european
                transport[0] = new Ship(container[0]);
                toolsTransported[i] = true;
            }
            transport[0]->Transport(container[0]);
                
        }else if((monthDiff == 1  || monthDiff == 0)){

            //Transport tools if the race is 7 days away.Track tools if tols have already been transported and race is <=7 days away
            //Take into account if you're on the last days of the month and 7 days away is the following month
            if((dayDiff >= -24 && dayDiff <= -21) || dayDiff <= 7){
                if(toolsTransported[i] == false){
                    type = 0;
                    container[0] = warehouse->createContainer(type,1, id, warehouse->getRacingEvent()[i]);
                    transport[0] = new Truck(container[0]);
                    toolsTransported[i] = true;
                }
                transport[0]->Transport(container[0]);
            }else if((dayDiff >= -29 && dayDiff <= -26) || dayDiff == 2){//Start to transport cars 2 days before race. Track cars if race < 2 days away 
                if(carTransported[i] == false){
                    if(inEuro == true)
                        type = 1;
                    else type = 0;
                    container[1] = warehouse->createContainer(type,0, id, warehouse->getRacingEvent()[i]);
                    transport[1] = new Plane(container[1]);
                    carTransported[i] = true;
                    
                }
                transport[1]->Transport(container[1]);
            }
            
        //return cars and drivers to the warehouse a day after the race. Drivers are stored in the same container as cars
        }else if((endMonthDiff == 1 || endMonthDiff == 0) && ((endDayDiff >= -30 && endDayDiff <= -27) || endDayDiff == 1)){
            warehouse->reinstateContainer(transport[1]->returnCars());
        }
    } 
    //need to simulate time that has passed while in transit

}