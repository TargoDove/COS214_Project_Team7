#include "Container.h"
#include <iostream>

Container::Container(bool dest, string* tools, int teamId, racingEvent* raceList){
    ArrivalStatus = false;
    loaded = false;
    dayCount = 0;
    GarageIndex = teamId;
    destination = dest;
    toolList = tools;
    ContainerType = "tools";
    GarageIndex = teamId;
    race = raceList;
    cout << "A container to transport the tools is being prepared" << "\n";
}

Container::Container(bool dest, F1Car* LeCar, int teamId, racingEvent* raceList){
    ArrivalStatus = false;
    loaded = false;
    dayCount = 0;
    destination = dest;
    Car = LeCar;
    ContainerType = "car";
    GarageIndex = teamId;
    races = raceList;
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

string* Container::getTools(){
    return toolList;
}

F1Car* Container::getCar(){
    return Car;
}

int Container::getIndex(){
    return GarageIndex;
}