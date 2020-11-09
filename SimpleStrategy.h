#ifndef SIMPLESTRATEGY_H
#define SIMPLESTRATEGY_H

#include "TeamStrategy.h"
#include "MediumTires.h"


class SimpleStrategy:public TeamStrategy
{
public:
        SimpleStrategy(F1Team*team,int index);
        virtual ~SimpleStrategy();
        void print();
        bool UseBoost();

};
#endif // SIMPLESTRATEGY_H
