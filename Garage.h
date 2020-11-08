#ifndef GARAGE_H
#define GARAGE_H

#include "Tires.h"
#include "Driver.h"
#include "F1Car.h"
#include "Container.h"
#include <list>

class Garage {

  private:
    list<Container *> containers;
    Tires ***carTires; //carTires[0] is the array of tires for car1, carTires[0][0] is a Tires ptr to the first set of tires for car1
    F1Car ** f1Cars;
    Driver **drivers;
    string * toolList; 
    int numCars; //will always be maximum of 2
    int * numTires; //Length 2 array, each value can be a maximum of 5

  public:
    Garage();
    ~Garage();
    void unpackContainers();
    void addContainer(Container*);
    Tires** getTireSets(int carIndex);
    F1Car * getF1Car(int carIndex);
    Driver* getDriver(int carIndex);
    bool haveTools();
    int getNumCars();
};

#endif
