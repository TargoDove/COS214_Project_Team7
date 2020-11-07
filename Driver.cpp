#include "Driver.h"

Driver::Driver()
{
  skill = 100;
  currentPoints = 0;
  name = "Dummy"
}

Driver::Driver(double s, double c, string n)
{
  skill = s;
  currentPoints = c;
  name = n;
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

string Driver::getName()
{
  return name;
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
