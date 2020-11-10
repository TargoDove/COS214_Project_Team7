#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include "F1Car.h"
#include "RacingEvent.h"
#include "Garage.h"
#include <iostream>
#include "Tires.h"

using namespace std;

class RacingEvent;

class Container
{
    private:
        bool ArrivalStatus;
        bool loaded;
        bool destination;
        string* toolList;
        F1Car** cars;
        Driver** drivers;
        Tires** tiresCar1;
        Tires** tiresCar2;
        int dayCount;
        int GarageIndex;    //Determines which garage the container should be stored in.
        RacingEvent* race;
        string ContainerType;
	public:
		Container(bool dest, string* tools, Tires** tires1, Tires** tires2, int teamId, RacingEvent* raceList);  //Two different constructors. This is to decide whether the car or the tools will be transported in this container.
        Container(bool dest, F1Car** LeCars, Driver** LeDrivers ,int teamId, RacingEvent* raceList);
        ~Container();
        bool getStatus();
        bool isLoaded();
        void setLoaded(bool);
        void setStatus(bool status);
        string* getContents();
        void setContents(string tools[]);
        bool getDestination();
        void setDestination(bool dest);
        void increaseCount();
        int getDayCount();
        int getIndex();
        string getContainerType();
        string* getTools();
        F1Car** getCars();
        Tires** getTires1(); //Tires for car 1
        Tires** getTires2(); //Tires for car 2
        Driver** getDrivers();
        RacingEvent* getRace();
};

#endif