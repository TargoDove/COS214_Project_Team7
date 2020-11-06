#include "Tires.h"

Tires::Tires()
{
  speed = 1.0;
  durability = 1.0;
  integrity = 1.0;
}

Tires::Tires(double s, double d, double i)
{
  speed = s;
  durability = d;
  integrity = i;
}

Tires::~Tires()
{
    //Do nothing
}

double Tires::getIntegrity()
{
  return integrity;
}

double Tires::getSpeed()
{
  return speed;
}

double Tires::getDurability()
{
  return durability;
}
