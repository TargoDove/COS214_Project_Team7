#include "SimpleCreator.h"

SimpleCreator::SimpleCreator(TeamStrategy* strat,int index):StrategyCreator(strat,index)
{
    //ctor
}

SimpleCreator::~SimpleCreator()
{
    //dtor
}
TeamStrategy* SimpleCreator::createStrategy(F1Team*team)
{

    return new SimpleStrategy(team,this->getIndex());
}
