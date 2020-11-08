#ifndef SIMPLECREATOR_H
#define SIMPLECREATOR_H

#include "StrategyCreator.h"
#include "SimpleStrategy.h"
#include "TeamStrategy.h"
class SimpleCreator:public StrategyCreator
{
    public:
        SimpleCreator(TeamStrategy* strat,int index);
        virtual ~SimpleCreator();
        TeamStrategy* createStrategy(F1Team*team);
};

#endif // SIMPLECREATOR_H
