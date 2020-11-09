#include "DefaultCreator.h"

DefaultCreator::DefaultCreator()
{
    //Do nothing
}

DefaultCreator::~DefaultCreator()
{
    //Do nothing
}

TeamStrategy *DefaultCreator::createStrategy(F1Team *team, int index)
{
    cout << "Default Strategy has been chosen for " << team->getTeamName() << "'s car " << index << endl;
    return new DefaultStrategy();
}
