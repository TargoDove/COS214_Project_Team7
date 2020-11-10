#ifndef HARDTIRES_H
#define HARDTIRES_H

#include "Tires.h"

class HardTires : public Tires
{
	public:
    HardTires();
    ~HardTires();
    virtual void decreaseIntegrity(double);
    virtual Tires *clone();

  protected:
    HardTires(double, double, double);
};

#endif