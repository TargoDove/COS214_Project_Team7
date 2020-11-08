#ifndef DEFAULTSTRATEGY_H
#define DEFAULTSTRATEGY_H
#include "TeamStrategy.h"
#include "HardTires.h"

class DefaultStrategy:public TeamStrategy
{
    public:
        DefaultStrategy(F1Team*team,int index);
        virtual ~DefaultStrategy();
        void print();
        bool UseBoost();

};

#endif // DEFAULTSTRATEGY_H
