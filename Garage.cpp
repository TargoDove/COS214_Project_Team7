#include "Garage.h"

Garage::Garage()
{
  assembledCars = NULL;

  numCars = 0;
}

Garage::~Garage()
{
  // TODO - implement Garage::~Garage()
  //At the end of the competition:
  //-Containers are deleted??
  throw "Not yet implemented";
}

void Garage::unpackContainers()
{
  // TODO - implement Garage::unpackContainers()
  throw "Not yet implemented";
}

void Garage::addContainer(Container *container)
{
  containers.push_back(container);
}

bool Garage::haveTools()
{
  return (numCars > 0);
}

int Garage::getNumCars()
{
  return numCars;
}

AssembledCar *Garage::getAssembledCar(int index){
  if(index < numCars && index >= 0){
    return AssembledCars[index];
  }
}
