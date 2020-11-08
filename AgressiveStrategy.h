#ifndef AGRESSIVESTRATEGY_H
#define AGRESSIVESTRATEGY_H
#include "TeamStrategy.h"
#include "SoftTires.h"

class AgressiveStrategy:public TeamStrategy
{
    public:
        AgressiveStrategy(F1Team*team,int index);
        virtual ~AgressiveStrategy();
        void print();
        bool UseBoost();

};

#endif // AGRESSIVESTRATEGY_H
