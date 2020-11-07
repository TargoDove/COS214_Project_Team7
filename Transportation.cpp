#include "Transportation.h"
#include <iostream>

Transportation::Transport(Container* c){
    if(c->loaded){
        c->increaseCount();
        Garage** LeGarage = c->race.getRaceTrack().getGarageList();
        Garage* TeamGarage = LeGarage[c->getIndex()];
        if(c->getDestination()){ //getDestination() will return a boolean value. True if the destination is in Europe and false if non-European.
            if(c->getDayCount >=6){
                c->setStatus = true; //Sets ArrivalStatus to true
                TeamGarage->container = c;
            }
        }else{
            if(container->getDayCount >=90){
                container->setStatus = true;
                TeamGarage->container = c
            }
        }
        
    }else{
        container->loaded = true;
    }
}

Transportation::void loadcontainer(){ //Setter function
    container = c;
}

Transportation::Container* unloadcontainer(){ //Getter function
    return container;
}

Ship::Ship(Container* c){
    container = c;
}

Ship::sendContainer(Container* c){ //Virtual function. Will print out different message depending on type of transport used. This is for the important for the template method.
    cout << "The container has been loaded onto a ship and sent off to it's destination." << "\n";
}

Truck::Truck(Container* c){
    container = c;
}

Truck::sendContainer(Container* c){
    cout << "The container is being transported by truck to the race track." << "\n";
}

Plane::Plane(Container* c){
    container = c;
}

Plane::sendContainer(Container* c){
    cout << "The plane containing the F1 car has taken off and is en route to the race track." << "\n";
}