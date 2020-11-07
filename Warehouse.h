#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "F1Car.h"
#include "RacingEvent.h"
#include "Container.h"
#include "Date.h"

#include <string>

using namespace std;

class Warehouse{
    private:
        string toolList[];
        F1Car* car;
        RacingEvent** raceList;
    public:
        Warehouse(F1Car*, RacingEvent**);
        void checkDate();
        Container* createContainer(bool, bool, int);
        void reinstateContainer(Container* container);
        void setRacingEvent(RacingEvent* list);
        RacingEvent* getRacingEvent();
        //void setDate(Date date);
        void setCar(F1Car* car);
        void setTools(string[] tools);
};
#endif