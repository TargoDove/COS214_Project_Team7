#ifndef LOGISTICS_H
#define LOGISTICS_H

#include "Warehouse.h"
#include "Transportation.h"

class Logistics{
    private:
        Warehouse* warehouse;
        Container** container;
        Transportation** transport;
        int toolsTransported[30];
        int carTransported[30];
       //  Date currDate;
    public:
      //  void setDate(Date date);
        Logistics(RacingEvent** raceList, F1Car* car);
        ~Logistics();
        void run(Date date, int id); // Calls warehouse to create container, creates transport and initializes the transportation of car and tools
};
#endif