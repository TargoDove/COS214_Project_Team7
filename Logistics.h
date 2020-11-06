#ifndef LOGISTICS_H
#define LOGISTICS_H

#include "Warehouse.h"

class Logistics{
    private:
        Warehouse* warehouse;
    public:
        void run(F1Car* car, Date date, RacingEvent* raceList);
};
#endif