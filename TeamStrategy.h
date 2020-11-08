#ifndef TEAMSTRATEGY_H
#define TEAMSTRATEGY_H

#include "F1Team.h"

class TeamStrategy
{
    public:
        TeamStrategy(F1Team*team,int index);
        virtual ~TeamStrategy();
        virtual  void print()=0;
        virtual bool UseBoost()=0;

        F1Team* getTeam();
        bool getBoost();
        void setBoost(bool expression);
        int getIndex();

    private:
    bool boost;
    F1Team* team;
    int index;
};

#endif // TEAMSTRATEGY_H
