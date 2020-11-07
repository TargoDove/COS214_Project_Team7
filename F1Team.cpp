#include "F1Team.h"

F1Team::F1Team(string n, int id, double b, F1Car **cCars, F1Car **nCars, Driver **drs)
{
  teamName = n;
  teamID = id;
  windTunnelTokens = 400; 
  budget = b;
  currentCars = cCars;
  nextCars = nCars;
  drivers = drs;
  departments = new GenericList<EngineeringDepartments>();
  logistics = NULL;
  raceList = NULL;
  points = 0;
  qualifyScore = 0;
}

F1Team::~F1Team()
{
  // TODO - implement F1Team::~F1Team
  throw "Not yet implemented";
}

void F1Team::setRaceList(RaceingEvent **rList)
{
  raceList = rList;
}

void F1Team::setLogistics(Logistics *l)
{
  logistics = l;
}

void F1Team::update(Date date)
{
  // TODO - implement F1Team::update(Date date)
  throw "Not yet finnished";

  //Do we need to get or add another strategy?
  //Does the strategy change at all?

  
}

F1Car* F1Team::getCurrentCar(int index)
{
  if(index >= 0 && index < 2)
    return currentCars[index];
  else 
    return NULL;
}
F1Car* F1Team::getNextYearCar(int index)
{
  if (index >= 0 && index < 2)
    return nextCars[index];
  else
    return NULL;
}

void F1Team::applyDepartmentImprovements()
{
  Iterator* it = departments->createIterator();
  it->first();

  if(it->current() != NULL){
    string n = it->current()->getSpecificationName();
    it->current()->performImprovement(currentCars[0]->getSpecification(n), true));
    it->current()->performImprovement(currentCars[1]->getSpecification(n), true));

    it->current()->performImprovement(nextCars[0]->getSpecification(n), false));
    it->current()->performImprovement(nextCars[1]->getSpecification(n), false));

    while(it->hasNext()){
      it->next();

      n = it->current()->getSpecificationName();
      it->current()->performImprovement(currentCars[0]->getSpecification(n), true));
      it->current()->performImprovement(currentCars[1]->getSpecification(n), true));

      it->current()->performImprovement(nextCars[0]->getSpecification(n), false));
      it->current()->performImprovement(nextCars[1]->getSpecification(n), false));
    }
  }
}

void F1Team::applyStrategy(){
  // TODO - implement F1Team::applyStrategy()
  //Need to set G1 and G2 specialists for each department based on strategy and budget
  throw "Not yet implemented";
}

string F1Team::getTeamName(){
  return name;
}
