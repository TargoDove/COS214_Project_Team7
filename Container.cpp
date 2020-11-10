#include "Container.h"

Container::Container(bool dest, string* tools, Tires** tires1, Tires** tires2, int teamId, RacingEvent* raceList){
    ArrivalStatus = false;
    loaded = false; //Tests if a container is ready to be shipped. If yes, the daycount will increase. If no, it will ready the container for transport.
    dayCount = 0; //Used to simulate the passage of time.
    GarageIndex = teamId;
    destination = dest;
    toolList = tools;
    tiresCar1 = tires1;
    tiresCar2 = tires2;
    ContainerType = "tools";
    GarageIndex = teamId;
    race = raceList;
    cout << "A container to transport the tools is being prepared" << "\n";
}

//This is a metaphorical 'container' that groups together everything that needs to be transported on the plane.
Container::Container(bool dest, F1Car** LeCars, Driver** LeDrivers ,int teamId, RacingEvent* raceList){
    ArrivalStatus = false;
    loaded = false;
    dayCount = 0;
    destination = dest;
    cars = LeCars;
    drivers = LeDrivers;
    ContainerType = "car";
    GarageIndex = teamId;
    race = raceList;
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

F1Car** Container::getCars(){
    return cars;
}

bool Container::isLoaded()
{
    return loaded;
}

void Container::setLoaded(bool l)
{
    loaded = l;
}

int Container::getIndex(){
    return GarageIndex;
}

Tires **Container::getTires1()
{
    return this->tiresCar1;
}

Tires **Container::getTires2()
{
    return tiresCar2;
}

RacingEvent *Container::getRace()
{
    return race;
}

Driver **Container::getDrivers()
{
    return drivers;
}
