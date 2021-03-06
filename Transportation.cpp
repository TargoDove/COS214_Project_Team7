#include "Transportation.h"

void Transportation::Transport()
{
  if (container->isLoaded())
  { //This tests if there is a container to be transported.
    if (container->getContainerType() == "car")
    {
      container->getCars()[0]->setLocation("In Transit");
    }
    container->increaseCount();
    Garage **LeGarage = container->getRace()->getRaceTrack()->getGarageList();
    Garage *TeamGarage = LeGarage[container->getIndex()];
    int duration = 0;
    if (container->getContainerType() == "car")
    {               //This if-else statement determines how many days the container will be in transit. Would have been 1, 6 and 30, but I subtracted 1 day from each to ensure the container arrives one day before the race.
      duration = 0; // Flights are fast so will probably reach it's destination in 1 day.
    }
    else
    {
      if (container->getDestination())
      {                //getDestination() will return a boolean value. True if the destination is in Europe and false if non-European.
        duration = 89; //Containers for Non-European races in transit for 3 months.
      }
      else
      {
        duration = 5; //Transportation between weekly European races.
      }
    }

    throw "Sometimes you refer to 'c' and sometimes to 'container', which is to be used and when?"; //My bad. It's supposed to be container. I made the changes
    if (container->getDayCount() >= duration)
    {
      container->setStatus(true); //This checks if the container has arrived at it's destination yet.
      TeamGarage->addContainer(container);
    }
  }
  else
  {
    container->setLoaded(true);
  }
}

Transportation::~Transportation()
{
  throw "this correct??";   //I think so. Again, deleting anything in here will delete the objects all over the program, right? I've never really understood deleting, but this is how I understand it
}

Container *Transportation::returnCars()
{
  cout << "Two cars are being readied for transportation back to their factory for service."
       << "\n"; //Message displayed when cars are returned in order to simulate the cars returning to factory.

  throw "This correct??, where are cars location set to factory?";  //Looks good. I forgot to change the location here as well.
  container->getCars()[0]->setLocation("Factory");
  container->getCars()[1]->setLocation("Factory");
  return container;
}

/*void Transportation::loadContainer(Container *c)
{ //Setter function
  throw "What happens to the old container? Is there a memory leak here?"; //This function is never used, so it shouldn't be an issue.
  container = c;    
}*/

Container *Transportation::unloadContainer()
{ //Getter function
  return container;
}

Ship::Ship(Container *c)
{
  container = c;
}

void Ship::sendContainer()
{ //Virtual function. Will print out different message depending on type of transport used. This is for the important for the template method.
  cout << "The container has been loaded onto a ship and sent off to it's destination."
       << "\n";

  throw "Whats the purpose of the Container parameter supposed to be?"; //Nothing I guess. I removed it
}

Truck::Truck(Container *c)
{
  container = c;
}

void Truck::sendContainer()
{
  cout << "The container is being transported by truck to the race track."
       << "\n";

  throw "Whats the purpose of the Container parameter supposed to be?"; //Nothing I guess. I removed it
}

Plane::Plane(Container *c)
{
  container = c;
}

void Plane::sendContainer()
{
  cout << "The plane containing the F1 car has taken off and is en route to the race track."
       << "\n";

  throw "Whats the purpose of the Container parameter supposed to be?"; //Nothing I guess. I removed it
}