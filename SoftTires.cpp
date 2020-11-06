#include "SoftTires.h"

SoftTires::SoftTires()
{
  speed = 1.4;
  durability = 1.0;
  integrity = 1.0;
}

SoftTires::SoftTires(double s, double d, double i): Tires(s, d, i)
{}

void SoftTires::decreaseIntegrity(double per)
{
  integrity *= (1-per/durability);
}

Tires *SoftTires::clone(){
  return new SoftTires(this->getSpeed(), this->getDurability(), this->getIntegrity());
}