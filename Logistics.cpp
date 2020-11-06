#include "Logistics.h"

void Logistics::run(F1Car* car, Date date, RacingEvent* raceList){
    warehouse = Warehouse(car, raceList, date);
    Container* carContain = warehouse->createContainer(0);
    Container* toolsContain = warehouse->createContainer(1);

    
}