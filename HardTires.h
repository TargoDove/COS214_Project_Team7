#ifndef HARDTIRES_H
#define HARDTIRES_H

#include "Tires.h"

using namespace std;

class HardTires : public Tires
{
	public:
    HardTires();
    ~HardTires();
    virtual double getIntegrity();
    virtual double getSpeed();
    virtual double getDurability();
    virtual void decreaseIntegrity(double);
    virtual Tires *clone();

  private:
    double integrity; //1.0
    double speed;
    double durability;
};

#endif