#include "Container.h"
#include <iostream>

Container::Container(bool dest, string* tools, int teamId){
    ArrivalStatus = false;
    dayCount = 0;
    GarageIndex = teamId;
    destination = dest;
    toolList = tools;
    ContainerType = "tools";
    cout << "A container to transport the tools is being prepared" << "\n";
}

Container::Container(bool dest, F1Car* LeCar, int teamId){
    ArrivalStatus = false;
    dayCount = 0;
    destination = dest;
    Car = LeCar;
    ContainerType = "car";
    cout << "Transport for the F1 car is being prepared" << "\n";
}

bool Container::getStatus(){
    return ArrivalStatus;
}

void Container::setStatus(bool status){
    ArrivalStatus = status;
}

string* Container::getContents(){
    return toolList;
}

void Container::setContents(string tools[]){
    toolList = tools;
}

bool Container::getDestination(){
    return destination;
}

void Container::setDestination(bool dest){
    destination = dest;
}

void Container::increaseCount(){
    dayCount++;
}

int Container::getDayCount(){
    return dayCount;
}

string Container::getContainerType(){
    return ContainerType;
}