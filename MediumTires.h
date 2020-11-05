#ifndef MEDIUMTIRES_H
#define MEDIUMTIRES_H

#include "Tires.h"

using namespace std;

class MediumTires : public Tires
{
	public:
    MediumTires();
    ~MediumTires();
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