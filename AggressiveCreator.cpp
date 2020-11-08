#include "AggressiveCreator.h"

AggressiveCreator::AggressiveCreator(TeamStrategy* strat,int index):StrategyCreator(strat,index)
{
    //ctor
}

AggressiveCreator::~AggressiveCreator()
{
    //dtor
}
TeamStrategy* AggressiveCreator::createStrategy(F1Team*team)
{
      return new AgressiveStrategy(team,this->getIndex());
}
