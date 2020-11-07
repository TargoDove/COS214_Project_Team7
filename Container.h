#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include "F1Car.h"
using namespace std;
class Container
{
    private:
        bool ArrivalStatus;
        bool destination;
        string* toolList;
        F1Car* Car;
        int dayCount;
        int GarageIndex;
        string ContainerType;
	public:
		Container(bool dest, string* tools, int teamId);
        Container(bool dest, F1Car* LeCar, int teamId);
        bool getStatus();
        void setStatus(bool status);
        string* getContents();
        void setContents(string tools[]);
        bool getDestination();
        void setDestination(bool dest);
        void increaseCount();
        int getDayCount();
        string getContainerType();
        string* getTools();
        F1Car* getCar();
};

#endif