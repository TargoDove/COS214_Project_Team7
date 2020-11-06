#include "F1Car.h"

F1Car::F1Car()
{
  strategy = NULL;
  location = "Home";
  carSpecifications = NULL;
  numberOfSpecifications = 0;
  fittedTires = NULL;
}

F1Car::~F1Car()
{
  if(strategy != NULL) delete strategy;

  for(int i = 0; i < numberOfSpecifications; i++){
    if(carSpecifications[i] != NULL)
      delete carSpecifications[i];
  }

  if (carSpecifications != NULL)
    delete [] carSpecifications;
}

F1CarSpecification *F1Car::getSpecification(int index)
{
  if (index < 0 || index >= numberOfSpecifications) return NULL;
  else
    return carSpecifications[index];
}

F1CarSpecification *F1Car::getSpecificationByName(string name)
{
  for(int i = 0; i < numberOfSpecifications; i++){
    if (name.compare(carSpecifications[i]->getName()) == 0)
      return carSpecifications[i];
  }
  return NULL;
}

void F1Car::addSpecification(F1CarSpecification * spec)
{
  cout << "Adding " << spec->getName() << " specification to F1Car" << endl;

  F1CarSpecification **newArr = new F1CarSpecification*[numberOfSpecifications+1];

  for(int i = 0; i < numberOfSpecifications; i++){
    newArr[i] = carSpecifications[i];
  }
  numberOfSpecifications++;
  newArr[numberOfSpecifications] = spec;
  delete [] carSpecifications;
  carSpecifications = newArr;
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
