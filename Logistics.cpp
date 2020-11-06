#include "Logistics.h"

void Logistics::run(F1Car* car, Date date, RacingEvent* raceList, int id){
    warehouse = new Warehouse(car, raceList, date, id);
    Container* carContain;
    Container* toolsContain;
    Transportation* plane, truck, ship;

    difference = raceList->getDate().getMonth() - date.getMonth();

    cout << "Preparing tools for transportation.\n";
    if(difference>3=){
        //1 = non European, 1= tools container
        toolsContain = warehouse->createContainer(1,1);
        ship = new Ship();
        toolsContain = ship->Transport(toolsContain);
        //need to simulate the time that has passed while in transit
    }else{
        //0 = European, 1 = toolsContainer
        toolsContain = warehouse->createContainer(0,1);
        truck = new Truck();
        toolsContain = truck->Transport(toolsContain);
    }
    cout <<"Preparing car for Transportation.\n";
    plane = new Plane();
    carContain = warehouse->createContainer(1,0);
    carContain = plane->Transport(carContain);
    //need to simulate time that has passed while in transit
    carContain->setStatus(true);
    raceList->getRaceTrack()->getGarageList()[id] = carContain;
    raceList->getRaceTrack()->getGarageList()[id]->setIsHere(true);

    cout << "Container has arrived at destination.\n";

}