#ifndef DEFAULTCREATOR_H
#define DEFAULTCREATOR_H
#include "DefaultStrategy.h"
#include "SimpleCreator.h"
class DefaultCreator:public StrategyCreator
{
    public:
        DefaultCreator(TeamStrategy* strat,int index);
        virtual ~DefaultCreator();
        TeamStrategy* createStrategy(F1Team*team);
};

#endif // DEFAULTCREATOR_H
