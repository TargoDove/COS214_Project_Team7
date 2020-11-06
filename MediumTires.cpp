#include "MediumTires.h"

MediumTires::MediumTires()
{
  speed = 1.2;
  durability = 1.2;
  integrity = 1.0;
}

MediumTires::MediumTires(double s, double d, double i) : Tires(s, d, i)
{
}

void MediumTires::decreaseIntegrity(double per)
{
  integrity *= (1-per/durability);
}

Tires *MediumTires::clone()
{
  return new MediumTires(this->getSpeed(), this->getDurability(), this->getIntegrity());
}