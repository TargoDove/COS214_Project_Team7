#include "AgressiveStrategy.h"

// AgressiveStrategy::AgressiveStrategy(F1Team*team,int index)
// {
//     // //ctor
//     // cout << team->getTeamName() << " has chosen an Agressive Strategy for car " << index << endl;
//     // Tires* tires = new SoftTires();
//     // team->getCurrentCar(index)->changeTires(tires);
// }

AgressiveStrategy::AgressiveStrategy()
{
    tireSetSize = 5;
    integrityCutoff = 0.3;

    templateSet = new Tires *[tireSetSize];
    templateSet[0] = new SoftTires();
    templateSet[1] = new SoftTires();
    templateSet[2] = new SoftTires();
    templateSet[3] = new SoftTires();
    templateSet[4] = new HardTires();
}

AgressiveStrategy::~AgressiveStrategy()
{
    //Do Nothing
}

bool AgressiveStrategy::useBoostStraight(Tires * t)
{
    return true;
}

bool AgressiveStrategy::useBoostCorner(Tires * t)
{
    return true;
}
