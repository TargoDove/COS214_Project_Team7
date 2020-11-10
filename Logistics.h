#ifndef LOGISTICS_H
#define LOGISTICS_H

#include "Warehouse.h"
#include "Transportation.h"
#include "Date.h"

class RacingEvent;

class Logistics{
    private:
        Warehouse* warehouse;
        Container** nonEuropToolsContainer;
        Container* container;
        Transportation** ship;
        Transportation* truck;
        Transportation* plane;
        bool toolsTransported[30];
        bool carTransported[30];
        int containerCount;
       //  Date currDate;
    public:
      //  void setDate(Date date);
        Logistics(RacingEvent** raceList, F1Car** car, Driver** drivers);
        void trackTools();
        bool raceOver(int, int);
        ~Logistics();
        void run(Date date, int id); // Calls warehouse to create container, creates transport and initializes the transportation of car and tools
};
#endif