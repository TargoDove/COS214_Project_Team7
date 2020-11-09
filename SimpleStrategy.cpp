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