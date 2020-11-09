#include "DefaultStrategy.h"

// DefaultStrategy::DefaultStrategy(F1Team*team,int index):TeamStrategy(team,index)
// {
//     //ctor
//     cout<<this->getTeam()->getTeamName()<<" has chosen an Default Strategy for car "<< index<<endl;
//     Tires* tires = new HardTires();
//     this->getTeam()->getCurrentCar(this->getIndex())->changeTires(tires);

// }

DefaultStrategy::DefaultStrategy()
{
  tireSetSize = 5;
  integrityCutoff = 0.5;

  templateSet = new Tires *[tireSetSize];
  templateSet[0] = new MediumTires();
  templateSet[1] = new MediumTires();
  templateSet[2] = new MediumTires();
  templateSet[3] = new MediumTires();
  templateSet[4] = new MediumTires();
}

DefaultStrategy::~DefaultStrategy()
{
  //Do Nothing
}

bool DefaultStrategy::useBoostStraight(Tires *t)
{
  if (t->getIntegrity() >= 0.8)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool DefaultStrategy::useBoostCorner(Tires *t)
{
  if (t->getIntegrity() < 0.8)
  {
    return true;
  }
  else
  {
    return false;
  }
}