#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "RacingEvent.h"
#include "F1Car.h"
#include "Container.h"
#include "Date.h"

#include <string>

using namespace std;

class Warehouse{
    private:
        string toolList[];
        F1Car* car;
        Date currDate;
        RacingEvent* raceList;
        int teamId;
    public:
        Warehouse(F1Car*, RacingEvent*, Date, int);
        void checkDate();
        Container* createContainer(bool, bool);
        void reinstateContainer(Container* container);
        void setRacingEvent(RacingEvent* list);
        RacingEvent* getRacingEvent();
        void setDate(Date date);
        void setCar(F1Car* car);
        void setTools(string[] tools);
};
#endif