#ifndef GARAGE_H
#define GARAGE_H

#include "Container.h"
#include "AssembledCar.h"

class Container;

class Garage {

  private:
    list<Container *> containers;
    AssembledCar** assembledCars;
    int numCars; //will always be maximum of 2

  public:
    Garage();
    ~Garage();
    void unpackContainers();
    void addContainer(Container*);
    bool haveTools();
    int getNumCars();
    AssembledCar *getAssembledCar(int);
};

#endif
