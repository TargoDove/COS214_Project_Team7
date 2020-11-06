#include "HardTires.h"

HardTires::HardTires()
{
  speed = 1.0;
  durability = 1.4;
  integrity = 1.0;
}

HardTires::HardTires(double s, double d, double i) : Tires(s, d, i)
{
}

void HardTires::decreaseIntegrity(double per)
{
  integrity *= (1-per/durability);
}

Tires *HardTires::clone()
{
  return new HardTires(this->getSpeed(), this->getDurability(), this->getIntegrity());
}