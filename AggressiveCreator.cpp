#include "AggressiveCreator.h"

AggressiveCreator::AggressiveCreator()
{
    //Do nothing
}

AggressiveCreator::~AggressiveCreator()
{
    //Do nothing
}

TeamStrategy *AggressiveCreator::createStrategy(F1Team *team, int index)
{
    cout << "Agressive Strategy has been chosen for " << team->getTeamName() << "'s car " << index << endl;
    return new AgressiveStrategy();
}
