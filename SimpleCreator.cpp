#include "SimpleCreator.h"

SimpleCreator::SimpleCreator()
{
    //Do nothing
}

SimpleCreator::~SimpleCreator()
{
    //Do nothing
}

TeamStrategy *SimpleCreator::createStrategy(F1Team *team, int index)
{
    cout << "Simple Strategy has been chosen for " << team->getTeamName() << "'s car " << index << endl;
    return new SimpleStrategy();
}
