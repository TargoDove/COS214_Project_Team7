#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "F1Car.h"
#include "RacingEvent.h"
#include "Container.h"
#include "Driver.h"


#include <string>

using namespace std;

class Warehouse{
    private:
        string* toolList;
        F1Car** cars;
        RacingEvent** raceList;
        Driver** drivers;
    public:
        Warehouse(F1Car**, RacingEvent**, Driver**);
        Container* createContainer(bool, bool, int, RacingEvent*);
        void reinstateContainer(Container* container);
        void setRacingEvent(RacingEvent** list);
        RacingEvent** getRacingEvent();
        //void setDate(Date date);
        void setCars(F1Car** car);
        void setTools(string* tools);
};
#endif