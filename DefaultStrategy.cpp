#include "DefaultStrategy.h"

DefaultStrategy::DefaultStrategy(F1Team*team,int index):TeamStrategy(team,index)
{
    //ctor
    cout<<this->getTeam()->getTeamName()<<" has chosen an Default Strategy for car "<< index<<endl;
    Tires* tires = new HardTires();
    this->getTeam()->getCurrentCar(this->getIndex())->changeTires(tires);

}

DefaultStrategy::~DefaultStrategy()
{
    //dtor
}
void DefaultStrategy::print()
{
}
bool DefaultStrategy::UseBoost()
{

    this->setBoost(false);
    return this->getBoost();
}
