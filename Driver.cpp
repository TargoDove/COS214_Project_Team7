#include "Driver.h"

Driver::Driver()
{
  skill = 100;
  currentPoints = 0;
}

Driver::Driver(double s, double c)
{
  skill = s;
  currentPoints = c;
}

Driver::~Driver()
{
  //Do nothing
}

void Driver::addPoints(double c)
{
  currentPoints = c;
}

double Driver::getPoints()
{
  return currentPoints;
}

void Driver::clearPoints()
{
  currentPoints = 0;
}

void Driver::addSkill(double s)
{
  skill += s;
}

double Driver::getSkill()
{
  return skill;
}
