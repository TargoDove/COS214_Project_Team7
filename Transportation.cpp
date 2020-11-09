#include "Transportation.h"
#include <iostream>

Transportation::Transport(Container* c){
    if(c->loaded){
        if(c->getContainerType() == "car"){
                    c->getCars()[0]->setLocation("In Transit");
        }
        c->increaseCount();
        Garage** LeGarage = c->getRace()->getRaceTrack()->getGarageList();
        Garage* TeamGarage = LeGarage[c->getIndex()];
        if(c->getContainerType() == "car"){
            duration = 0;
        }else{
            if(c->getDestination()){ //getDestination() will return a boolean value. True if the destination is in Europe and false if non-European.
                duration = 89;
            }else{
                duration = 5;
            }
        }

        if(container->getDayCount() >=duration){
                container->setStatus(true);
                TeamGarage->addContainer(c);
        }
        
    }else{
        container->loaded = true;
    }
}

Container* Transportation::returnCars(){
    cout << "Two cars are being readied for transportation back to their factory for service." << "\n"; //Message displayed when cars are returned in order to simulate the cars returning to factory.
    return container;
}

void Transportation::loadContainer(Container* c){ //Setter function
    container = c;
}

Container* Transportation::unloadContainer(){ //Getter function
    return container;
}

Ship::Ship(Container* c){
    container = c;
}

void Ship::sendContainer(Container* c){ //Virtual function. Will print out different message depending on type of transport used. This is for the important for the template method.
    cout << "The container has been loaded onto a ship and sent off to it's destination." << "\n";
}

Truck::Truck(Container* c){
    container = c;
}

void Truck::sendContainer(Container* c){
    cout << "The container is being transported by truck to the race track." << "\n";
}

Plane::Plane(Container* c){
    container = c;
}

void Plane::sendContainer(Container* c){
    cout << "The plane containing the F1 car has taken off and is en route to the race track." << "\n";
}