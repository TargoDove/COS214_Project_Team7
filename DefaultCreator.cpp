#include "DefaultCreator.h"

DefaultCreator::DefaultCreator(TeamStrategy* strat,int index):StrategyCreator(strat,index)
{
    //ctor

}

DefaultCreator::~DefaultCreator()
{
    //dtor
}
TeamStrategy* DefaultCreator::createStrategy(F1Team*team)
{
    return new DefaultStrategy(team,this->getIndex());
}
