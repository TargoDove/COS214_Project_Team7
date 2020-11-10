#ifndef SOFTTIRES_H
#define SOFTTIRES_H

#include "Tires.h"

class SoftTires : public Tires
{
	public:
    SoftTires();
    ~SoftTires();
    virtual void decreaseIntegrity(double);
    virtual Tires* clone();
    
  protected:
    SoftTires(double, double, double);
};

#endif