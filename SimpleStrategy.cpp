#include "SimpleStrategy.h"

// SimpleStrategy::SimpleStrategy(F1Team*team,int index):TeamStrategy(team,index)
// {
//     //ctor
//     cout<<this->getTeam()->getTeamName()<<" has chosen an Simple Strategy for car "<< index<<endl;
//     Tires* tires = new MediumTires();
//     this->getTeam()->getCurrentCar(this->getIndex())->changeTires(tires);
// }

SimpleStrategy::SimpleStrategy()
{
  tireSetSize = 5;
  integrityCutoff = 0.6;

  //{"Weight", "EnginePower", "Aerodynamics", "BreakEfficiency", "Boost", "DriverAssistance"};
  priorities[0] = 3;
  priorities[1] = 2;
  priorities[2] = 1;
  priorities[3] = 3;
  priorities[4] = 4;
  priorities[5] = 1;

  templateSet = new Tires *[tireSetSize];
  templateSet[0] = new SoftTires();
  templateSet[1] = new HardTires();
  templateSet[2] = new HardTires();
  templateSet[3] = new HardTires();
  templateSet[4] = new HardTires();
}

SimpleStrategy::~SimpleStrategy()
{
  //Do Nothing
}

bool SimpleStrategy::useBoostStraight(Tires *t)
{
  return false;
}

bool SimpleStrategy::useBoostCorner(Tires *t)
{
  return true;
}