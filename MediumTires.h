#ifndef MEDIUMTIRES_H
#define MEDIUMTIRES_H

#include "Tires.h"

class MediumTires : public Tires
{
	public:
    MediumTires();
    ~MediumTires();
    virtual void decreaseIntegrity(double);
    virtual Tires *clone();

  protected:
    MediumTires(double, double, double);
};

#endif