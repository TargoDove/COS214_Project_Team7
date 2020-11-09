#include "Container.h"
#include <iostream>

Container::Container(bool dest, string* tools, Tire** tireParts, int teamId, racingEvent* raceList){
    ArrivalStatus = false;
    loaded = false; //Tests if a container is ready to be shipped. If yes, the daycount will increase. If no, it will ready the container for transport.
    dayCount = 0; //Used to simulate the passage of time.
    GarageIndex = teamId;
    destination = dest;
    toolList = tools;
    tires = tireParts;
    ContainerType = "tools";
    GarageIndex = teamId;
    race = raceList;
    cout << "A container to transport the tools is being prepared" << "\n";
}

//This is a metaphorical 'container' that groups together everything that needs to be transported on the plane.
Container::Container(bool dest, F1Car** LeCars, Driver** LeDrivers ,int teamId, racingEvent* raceList){
    ArrivalStatus = false;
    loaded = false;
    dayCount = 0;
    destination = dest;
    cars = LeCars;
    drivers = LeDrivers;
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