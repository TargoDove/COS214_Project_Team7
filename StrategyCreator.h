#ifndef STRATEGYCREATOR_H
#define STRATEGYCREATOR_H
#include "TeamStrategy.h"
#include "F1Team.h"

class StrategyCreator
{
    public:
        StrategyCreator(TeamStrategy* strat,int index);
        virtual ~StrategyCreator();
        int getIndex();

       virtual TeamStrategy* createStrategy(F1Team* team)=0;

    private:
    TeamStrategy* teamStrategy;
    int index;
};

#endif // STRATEGYCREATOR_H
