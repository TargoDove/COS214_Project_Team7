#ifndef AGGRESSIVECREATOR_H
#define AGGRESSIVECREATOR_H

#include "StrategyCreator.h"
#include "AgressiveStrategy.h"
class AggressiveCreator:public StrategyCreator
{
    public:
        AggressiveCreator(TeamStrategy* strat,int index);
        virtual ~AggressiveCreator();
        TeamStrategy* createStrategy(F1Team*team);
};

#endif // AGGRESSIVECREATOR_H
