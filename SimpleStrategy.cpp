#include "SimpleStrategy.h"

SimpleStrategy::SimpleStrategy(F1Team*team,int index):TeamStrategy(team,index)
{
    //ctor
    cout<<this->getTeam()->getTeamName()<<" has chosen an Simple Strategy for car "<< index<<endl;
    Tires* tires = new MediumTires();
    this->getTeam()->getCurrentCar(this->getIndex())->changeTires(tires);
}

SimpleStrategy::~SimpleStrategy()
{
    //dtor
}
void SimpleStrategy::print()
{
}
bool SimpleStrategy::UseBoost()
{
    this->setBoost(false);
    return this->getBoost();
}
