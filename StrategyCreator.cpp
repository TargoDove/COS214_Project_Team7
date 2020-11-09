#include "StrategyCreator.h"

StrategyCreator::StrategyCreator(TeamStrategy* strat,int index)
{
    //ctor
    this->teamStrategy = strat;
    this->index = index;
}

StrategyCreator::~StrategyCreator()
{
    //dtor
}
int StrategyCreator::getIndex()
{
    return index;
}

