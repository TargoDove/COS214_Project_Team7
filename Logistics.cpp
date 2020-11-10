#include "Logistics.h"

//Your method is called from within this method -> "void F1Team::update(Date date)"
//Please can you look at the new Garage and AssembledCar classes and update
//logistics to work with those
//Since each F1Team has two cars competing in each race, two cars will need to be
//transported along with two Drivers (these will be by plane)
//You will be able to get an array of 5 Tire ptrs (Tire*) by
//calling: car->getStrategy()->getNewTireSets()
//I haven't implemented the method yet but I will tomorrow. Its return type will be "Tire**"

//When the F1Car is at home its "location" should be set to "Factory"
//When the F1Car is on the plane (in the container), its "location" should be set to "In Transit"
//When the F1Car is in the AssembledCar, its "location" should be set to "(Race Name)"

//The day after the Race is finished, we need to transport the Drivers and F1Cars back to the factory
//Either Logistics need to check when it is 1 day after the end of the race
//or the Garage or Race needs a way of asking Logistics to fly the Cars/Drivers back (possible command pattern??)
//Please give it some thought

//Also just check your method calls below as I have change "RaceTrack::getDate()" to "RaceTrack::getStartDate()" and added "RaceTrack::getEndDate()"

Logistics::Logistics(RacingEvent **raceList, F1Car **cars, Driver **drivers)
{
  warehouse = new Warehouse(cars, raceList, drivers);
  ship = new Transportation *[10]; 
  nonEuropToolsContainer = new Container *[10]; 
    containerCount = 0;
    truck = nullptr;
    plane = nullptr;
    ship = nullptr;
    container = nullptr;
}

Logistics::~Logistics()
{
  delete warehouse;
  warehouse = NULL;

  for (int i = 0; i < 10 && ship[i]!= nullptr; i++)
  {
    delete ship[i];
    delete nonEuropToolsContainer[i];
  }
  delete [] ship;
  delete [] nonEuropToolsContainer;

  delete container;
  delete truck;
  delete plane;
}

void Logistics::trackTools(){
    for(int i = 0; i<containerCount; i++){
        ship[i]->Transport();
    }
}

void Logistics::run(Date date, int id)
{
    int monthDiff, dayDiff, endDayDiff, endMonthDiff, type;
    bool inEuro;
    throw "Why 30??"; //It was a placeholder for the number of races taking place. 
                    //There are usually not more than 25 races. this check ,warehouse->getRacingEvent()[i] != NULL, 
                    //makes sure we dont got out of bounds 
    throw "If there are less than 30 racing events then an index out of bounds exception will be raised?";
    for (int i = 0; i < 30 && warehouse->getRacingEvent()[i] != NULL; i++)
    {
        Date startDate = warehouse->getRacingEvent()[i]->getStartDate();
        monthDiff = startDate.getMonth() - date.getMonth();
        dayDiff = startDate.getDay() - date.getDay();
        
        Date endDate = warehouse->getRacingEvent()[i]->getEndDate();
        endDayDiff = date.getDay() - endDate.getDay();
        endMonthDiff = date.getMonth() - endDate.getMonth();
        inEuro = warehouse->getRacingEvent()[i]->getRaceTrack()->inEurope();

    //Start to transport if there is a Non European race 3 months away and the tools havent yet been transported.
    //Still call the transport function if there is non european race <= 3 months away and the tools are already in transit. This is done to track the container
        if (monthDiff <= 3 && inEuro == false)
        {
            if (toolsTransported[i] == false)
            {
                throw "What happens to container[0]'s old value? Can I delete it or is it deleted elsewhere?";
                throw "What happens if you have multiple different containers busy being shipped at the same time?";
                throw "There isn't a 3 month gap between every race. Are old containers lost or overwritten or are they stored somewhere?";
                throw "What happens to transport[0]'s old value? Can I delete it or is it deleted elsewhere?";
                throw "Is there not a memory leak here?"; 
                
                //nonEuropToolsContainer - an array of containers that allow us to have different containers shipped at the same time.
                //ship - the different ships created for those containers
                if(containerCount >= 10){
                        containerCount = 0;
                        delete nonEuropToolsContainer[containerCount];
                        nonEuropToolsContainer[containerCount] = warehouse->createContainer(1, 1, id, warehouse->getRacingEvent()[i]);//1 = toolsContainer, 1= non european
                        delete ship[containerCount];
                        ship[containerCount] = new Ship(nonEuropToolsContainer[containerCount++]);
                        toolsTransported[i] = true;
                }else{
                    nonEuropToolsContainer[containerCount] = warehouse->createContainer(1, 1, id, warehouse->getRacingEvent()[i]);
                    ship[containerCount] = new Ship(nonEuropToolsContainer[containerCount++]);
                    toolsTransported[i] = true;
                }

            }
            trackTools();
        }
        else if ((monthDiff == 1 || monthDiff == 0))
        {

            //Transport tools if the race is 7 days away.Track tools if tols have already been transported and race is <=7 days away
            //Take into account if you're on the last days of the month and 7 days away is the following month
            if ((dayDiff >= -24 && dayDiff <= -21) || dayDiff <= 7)
            {
                if (toolsTransported[i] == false)
                {
                    type = 0;
                    delete container;
                    delete truck;
                    container = warehouse->createContainer(type, 1, id, warehouse->getRacingEvent()[i]);
                    truck = new Truck(container);
                    toolsTransported[i] = true;
                }
                truck->Transport();
            }
            else if ((dayDiff >= -29 && dayDiff <= -26) || dayDiff == 2)
            { //Start to transport cars 2 days before race. Track cars if race < 2 days away
                if (carTransported[i] == false)
                {
                    delete container;
                    delete plane;
                    if (inEuro == true)
                        type = 1;
                    else
                        type = 0;//only want the first line to execute. Whether its in Europe or not the method of transporting the cars is the same.
                        // Only difference is the location
                    container = warehouse->createContainer(type, 0, id, warehouse->getRacingEvent()[i]);
                    plane = new Plane(container);
                    carTransported[i] = true;
                }
                plane->Transport();
            }

            //return cars and drivers to the warehouse a day after the race. Drivers are stored in the same container as cars
        }
        else if (raceOver(endMonthDiff, endDayDiff) == true)
        {
            warehouse->reinstateContainer(plane->returnCars());
        }
    }
}

bool Logistics::raceOver(int endMonth, int endDay){
    if((endMonth == 1 || endMonth == 0) && ((endDay >= -30 && endDay <= -27) || endDay == 1)){
        return true;
    }
    return false;
}

//need to simulate time that has passed while in transit
