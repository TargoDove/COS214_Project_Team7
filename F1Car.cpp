#include "F1Car.h"

F1Car::F1Car()
{
  strategy = NULL;
  location = "Factory"; //Factory -> home, other options include "in transit" or race locations
  fittedTires = NULL;
  carSpecifications = new GenericList<F1CarSpecification>();
  currentYearCar = true;
}

F1Car::~F1Car()
{
  if(strategy != NULL) delete strategy;

  delete carSpecifications;
}

F1CarSpecification *F1Car::getSpecification(int index)
{
  return carSpecifications->getItem(index);
}

F1CarSpecification *F1Car::getSpecification(string name)
{
  return carSpecifications->getItem(name);
}

void F1Car::addSpecification(F1CarSpecification * spec)
{
  cout << "Adding " << spec->getName() << " specification to F1Car" << endl;

  carSpecifications->addItem(spec);
}

Tires *F1Car::getTires()
{
  return fittedTires;
}

Tires *F1Car::changeTires(Tires * newTires)
{
  Tires *oldTires = fittedTires;
  fittedTires = newTires;
  return oldTires;
}

void F1Car::setStrategy(Strategy * newStrategy)
{
  if(strategy != NULL) delete strategy;

  strategy = newStrategy;
}

Strategy *F1Car::getStrategy()
{
  return strategy;
}

void F1Car::addToRaceScore(int lapScore){
  raceScore+=lapScore;
}
int F1Car::getRaceScore(){
  return raceScore;
}

string F1Car::getLocation()
{
  return location;
}

void F1Car::setLocation(string l)
{
  location = l;
}

bool F1Car::isCurrentYearCar()
{
  return currentYearCar;
}
void F1Car::setCurrentYear(bool val)
{
  currentYearCar = val;
}