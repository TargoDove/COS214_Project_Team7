#include "TeamStrategy.h"

TeamStrategy::TeamStrategy()
{
  tireSetSize = 5;
  integrityCutoff = 0.0;

  templateSet = NULL;
  priorities = new int[6];
}

TeamStrategy::~TeamStrategy()
{
  if (templateSet != NULL)
  {
    for (int i = 0; i < tireSetSize; i++)
    {
      delete templateSet[i];
    }

    delete[] templateSet;
  }
}

Tires **TeamStrategy::getNewTireSets()
{
  Tires **newSet = new Tires *[tireSetSize];

  if (templateSet == NULL)
    return NULL;

  for (int i = 0; i < tireSetSize; i++)
  {
    newSet[i] = templateSet[i]->clone();
  }

  return newSet;
}

bool TeamStrategy::performPitstop(AssembledCar *aCar)
{
  F1Car *car = aCar->getF1Car();
  if (car->getTires() != NULL && car->getTires()->getIntegrity() > integrityCutoff)
  {
    return false;
  }

  //Get first tireset with 100% integrity or tires with highest integrity
  int highest = 0;
  int hIntegrity = aCar->getSpareTires()[0]->getIntegrity();
  for (int i = 1; i < 5; i++)
  {
    if (aCar->getSpareTires()[i]->getIntegrity() == 1.0)
    {
      highest = i;
      hIntegrity = 1.0;
      break;
    }
    else if (aCar->getSpareTires()[i]->getIntegrity() > hIntegrity)
    {
      highest = i;
      hIntegrity = aCar->getSpareTires()[i]->getIntegrity();
    }
  }

  if (aCar->getSpareTires()[highest] == car->getTires())
  {
    return false;
  }
  else
  {
    car->changeTires(aCar->getSpareTires()[highest]);
  }

  return true;
}

int TeamStrategy::getPriority(string specName)
{
  string specNames[6] = {"Weight", "EnginePower", "Aerodynamics", "BreakEfficiency", "Boost", "DriverAssistance"};
  if(priorities == NULL) return -1;

  for(int i = 0; i < 6; i++){
    if(specName.compare(specNames[i]) == 0)
    {
      return priorities[i];
    }
  }
  return 0;
}