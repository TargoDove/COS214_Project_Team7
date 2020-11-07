#include "Transportation.h"
#include <iostream>

Transportation::Transport(Container* container){
    if(container->loaded){
        container->increaseCount();
        Garage** LeGarage = container->race.getRaceTrack().getGarageList();
        Garage TeamGarage = LeGarage[container->getIndex()];
        if(container->getDestination()){
            if(container->getDayCount >=6){
                container->setStatus = true;
                TeamGarage.setContainer(container);
            }
        }else{
            if(container->getDayCount >=90){
                container->setStatus = true;
                TeamGarage.setContainer(container);
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