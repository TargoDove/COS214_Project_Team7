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
  //Containers must be unpacked and contents must be used to create an array of AssembledCars
  //Since two cars are being shipped this will be an array of length 2
  if(containers.front()->getContainerType() == "car"){  //This initializes carContainer and toolContainer to the corresponding container.
    Container* carContainer = containers.front();
    Container* toolContainer = containers.back();
  }else{
    Container* carContainer = containers.back();
    Container* toolContainer = containers.front();
  }

  Tires** tires1 = toolContainer->getTires1();          //
  Tires** tires2 = toolContainer->getTires2();          //
 
  F1Car** carList = carContainer->getCars();            //
  F1Car* car1 = carList[0];                             //
  F1Car* car2 = carList[1];                             //
  string raceName = toolContainer->race->getName();     //  This entire part collects the data needed for the AssembledCar constructor from the stored containers.

  car1->setLocation(raceName);                          //
  car2->setLocation(raceName);                          //

  Driver* driver1 = carContainer->getDrivers().front(); //
  Driver* driver2 = carContainer->getDrivers().back();  //

  string* tools = toolContainer->getTools();            //

  AssembledCar finalCar1(tires1, car1, driver1, tools, 8, 5); //Here the 2 cars are assembled.
  AssembledCar finalCar2(tires2, car2, driver2, tools, 8, 5);

  AssembledCar FinalCars[] = {finalCar1, finalCar2};  //The AssembledCars array is created

  assembledCars = FinalCars;  //The array is stored.
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
