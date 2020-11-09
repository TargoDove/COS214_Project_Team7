#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include "F1Car.h"
#include "RacingEvent.h"
#include "Garage.h"
using namespace std;
class Container
{
    private:
        bool ArrivalStatus;
        bool loaded;
        bool destination;
        string* toolList;
        F1Car** cars;
        Driver** drivers
        Tire** tires;
        int dayCount;
        int GarageIndex;
        racingEvent* race;
        string ContainerType;
	public:
		Container(bool dest, string* tools, Tire** tireParts, int teamId, racingEvent* raceList);  //Two different constructors. This is to decide whether the car or the tools will be transported in this container.
        Container(bool dest, F1Car** LeCars, Driver** LeDrivers ,int teamId, racingEvent* raceList);
        bool getStatus();
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
        Tire** getTires();

};

#endif