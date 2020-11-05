#ifndef SOFTTIRES_H
#define SOFTTIRES_H

#include "Tires.h"

using namespace std;

class SoftTires : public Tires
{
	public:
    SoftTires();
    ~SoftTires();
    virtual double getIntegrity();
    virtual double getSpeed();
    virtual double getDurability();
    virtual void decreaseIntegrity(double);
    virtual Tires* clone();
    
  private:
    double integrity; //1.0
    double speed;
    double durability;
};

#endif