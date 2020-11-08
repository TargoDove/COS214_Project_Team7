#include "Garage.h"

Garage::Garage()
{
  carTires = new Tires**[2];
  carTires[0] = NULL;
  carTires[1] = NULL;
  f1Cars = new F1Car *[2];
  f1Cars[0] = NULL;
  f1Cars[1] = NULL;
  drivers = new Driver *[2];
  drivers[0] = NULL;
  drivers[1] = NULL;

  numCars = 0;
  numTires = new int[2];
  numTires[0] = 0;
  numTires[1] = 0;

  toolList = NULL;
}

Garage::~Garage()
{
  // TODO - implement Garage::~Garage()
  //At the end of the competition:
  //-tires are scrapped/donated (thus deleted)
  //-Cars are returned
  //-Drivers are returned
  //-Tools are scrapped/donated (thus deleted)
  //-Containers are deleted??
  throw "Not yet finished";

  if(toolList != NULL) delete [] toolList;

  if (f1Cars[0] != NULL)
    f1Cars[0]->changeTires(NULL);

  if (f1Cars[1] != NULL)
    f1Cars[1]->changeTires(NULL);

  for(int t = 0; t < 2; t++){
    if (carTires[t] != NULL)
    {
      for(int i = 0; i < numTires[t]; i++)
      {
        if (numTires[t][i] != NULL)
          delete numTires[t][i];
      }
      delete[] numTires[t];
    }
  }
  delete [] numTires;
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

Tires **Garage::getTireSets(int carIndex)
{
  if(carIndex >= numCars || numTires[carIndex] == 0 || carTires[carIndex] == NULL) return NULL;

  return carTires[carIndex];
}

F1Car *Garage::getF1Car(int carIndex)
{
  if (carIndex >= numCars || f1Cars[carIndex] == NULL)
    return NULL;

  return f1Cars[carIndex];
}

Driver *Garage::getDriver(int carIndex)
{
  if (carIndex >= numCars || drivers[carIndex] == NULL)
    return NULL;

  return drivers[carIndex];
}

bool Garage::haveTools()
{
  return toolList != NULL;
}

int Garage::getNumCars()
{
  return numCars;
}
