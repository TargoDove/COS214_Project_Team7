#include "AssembledCar.h"

AssembledCar::AssembledCar(Tires **t, F1Car *c, Driver *d, string *tools, int nTools, int nTires)
{
  spareTires = t;
  f1Car = c;
  driver = d;
  toolList = tools;
  numTools = nTools;
  numTires = nTires;
  raceTime = -1.0;
}
AssembledCar::~AssembledCar()
{
  //At the end of the competition:
  //-tires are scrapped/donated (thus deleted)
  //-Cars are returned
  //-Drivers are returned
  //-Tools are scrapped/donated (thus deleted)

  if (toolList != NULL)
    delete[] toolList;

  if (f1Car != NULL)
    f1Car->changeTires(NULL);

  if (spareTires != NULL)
  {
    for (int i = 0; i < numTires; i++)
    {
      if (spareTires[i] != NULL)
        delete spareTires[i];
    }
    delete [] spareTires;
  }
}
Tires **AssembledCar::getSpareTires()
{
  return spareTires;
}
F1Car *AssembledCar::getF1Car()
{
  return f1Car;
}
Driver *AssembledCar::getDriver()
{
  return driver;
}

int AssembledCar::getNumTools()
{
  return numTools;
}
int AssembledCar::getNumTires()
{
  return numTires;
}

double AssembledCar::getRaceTime(){
  return raceTime;
}

void AssembledCar::setRaceTime(double t){
  raceTime = t;
}