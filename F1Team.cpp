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
  //setCarStrategies();//Must add departments first
}

F1Team::~F1Team()
{
  delete departments;

  int i = 0;
  while (getCurrentCar(i) != NULL)
  {
    delete getCurrentCar(i);
    delete drivers[i];
  }
  delete [] currentCars;
  delete [] drivers;
  i = 0;
  while (getNextYearCar(i) != NULL)
  {
    delete getNextYearCar(i);
  }
  delete [] nextCars;
  
  delete logistics;
}

void F1Team::setRaceList(RacingEvent **rList)
{
  raceList = rList;
}

void F1Team::setLogistics(Logistics *l)
{
  logistics = l;
}

void F1Team::setCarStrategies()
{
  int i = 0;
  Strategy* strat = new Strategy(this);

  while(getCurrentCar(i) != NULL)
  {
    getCurrentCar(i)->setStrategy(strat->chooseStategy(i));
  }

  i = 0;
  while (getCurrentCar(i) != NULL)
  {
    getNextYearCar(i)->setStrategy(strat->chooseStategy(i));
  }
}

void F1Team::update(Date date)
{
  // TODO - implement F1Team::update(Date date)
  throw "Not yet finnished";

  //Do we need to get or add another strategy?
  //Does the strategy change at all?

  logistics->run(date, teamID);

  if(currentCars[0]->getLocation().compare("Factory") == 0)
  {
    applyDepartmentImprovements(currentCars[0]);
  }

  if (currentCars[1]->getLocation().compare("Factory") == 0)
  {
    applyDepartmentImprovements(currentCars[1]);
  }

  if (nextCars[0]->getLocation().compare("Factory") == 0)
  {
    applyDepartmentImprovements(nextCars[0]);
  }

  if (nextCars[1]->getLocation().compare("Factory") == 0)
  {
    applyDepartmentImprovements(nextCars[1]);
  }
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

void F1Team::applyDepartmentImprovements(F1Car* car)
{
  Iterator* it = departments->createIterator();
  it->first();

  if(it->current() != NULL){
    string n = departments->getItem(it->current())->getSpecificationName();
    departments->getItem(it->current())->performImprovement(car->getSpecification(n), car->isCurrentYearCar());

    while(it->hasNext()){
      it->next();

      n = departments->getItem(it->current())->getSpecificationName();
      departments->getItem(it->current())->performImprovement(car->getSpecification(n), car->isCurrentYearCar());
    }
  }
}

double F1Team::getBudget()
{
  return budget;
}

void F1Team::applyStrategy(){
  // TODO - implement F1Team::applyStrategy()
  //Need to set G1 and G2 specialists for each department based on strategy and budget
  throw "Not yet implemented";
}

string F1Team::getTeamName(){
  return teamName;
}
