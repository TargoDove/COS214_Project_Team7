#ifndef ASSEMBLEDCAR_H
#define ASSEMBLEDCAR_H

#include "Tires.h"
#include "Driver.h"
#include "F1Car.h"
#include <list>

class AssembledCar {

  private:
    Tires **spareTires; 
    F1Car *f1Car;
    Driver *driver;
    string* toolList;
    int numTools;
    int numTires; // Can be a maximum of 5
    double raceTime;

  public:
    AssembledCar(Tires **, F1Car *, Driver *, string*, int, int);
    ~AssembledCar();
    Tires** getSpareTires();
    F1Car * getF1Car();
    Driver* getDriver();
    int getNumTools();
    int getNumTires();
    double getRaceTime();
    void setRaceTime(double);
};

#endif