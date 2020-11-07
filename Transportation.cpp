#include "Transportation.h"
#include <iostream>

Transportation::Transport(Container* c){
    if(c->loaded){
        c->increaseCount();
        Garage** LeGarage = c->race.getRaceTrack().getGarageList();
        Garage* TeamGarage = LeGarage[c->getIndex()];
        if(c->getDestination()){
            if(c->getDayCount >=6){
                c->setStatus = true;
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

Transportation::void loadcontainer(){
    container = c;
}

Transportation::Container* unloadcontainer(){
    return container;
}

Ship::Ship(Container* c){
    container = c;
}

Ship::sendContainer(Container* c){
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