#ifndef LOGISTICS_H
#define LOGISTICS_H

#include "Warehouse.h"
#include "Transportation.h"

class Logistics{
    private:
        Warehouse* warehouse;
        Container** container;
        Transportation** transport;
        int toolsTransported[27];
        int carTransported[27];
       //  Date currDate;
    public:
      //  void setDate(Date date);
        Logistics();
        ~Logistics();
        void run(F1Car* car, Date date, RacingEvent* raceList, int id);
};
#endif