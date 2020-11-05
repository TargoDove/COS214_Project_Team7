#include "Tires.h"

Tires::Tires()
{
  speed = 1.0;
  durability = 1.0;
  integrity = 1.0;
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
