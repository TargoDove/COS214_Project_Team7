#ifndef GARAGE_H
#define GARAGE_H

#include "Tires.h"

class Garage {

  public:
    Tires ***carTires; //carTires[0] is the array of tires for car1, carTires[0][0] is a Tires ptr to the first set of tires for car1
    Container* container;
};

#endif
