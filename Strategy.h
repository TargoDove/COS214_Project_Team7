#ifndef STRATEGY_H
#define STRATEGY_H
#include "F1Team.h"

#include "AggressiveCreator.h"
#include "SimpleCreator.h"
#include "DefaultCreator.h"

#include "TeamStrategy.h"

class Strategy
{
    public:
        Strategy(F1Team*team);
        virtual ~Strategy();
        TeamStrategy* chooseStategy(int index);
        bool UseBoost();
private:
F1Team* team;

};

#endif // STRATEGY_H
