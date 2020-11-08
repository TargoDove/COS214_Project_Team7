#include "AgressiveStrategy.h"

AgressiveStrategy::AgressiveStrategy(F1Team*team,int index):TeamStrategy(team,index)
{
    //ctor
    cout<<this->getTeam()->getTeamName()<<" has chosen an Agressive Strategy for car "<< index<<endl;
    Tires* tires = new SoftTires();
    this->getTeam()->getCurrentCar(index)->changeTires(tires);
}

AgressiveStrategy::~AgressiveStrategy()
{
    //dtor
}
void AgressiveStrategy::print()
{

}
bool AgressiveStrategy::UseBoost()
{

    this->setBoost(true);
    return this->getBoost();
}
