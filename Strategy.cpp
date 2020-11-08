#include "Strategy.h"

Strategy::Strategy(F1Team*team)
{
    //ctor
      this->team = team;
}

Strategy::~Strategy()
{
    //dtor

}
TeamStrategy* Strategy::chooseStategy(int index)
{
    StrategyCreator* strategy;
    TeamStrategy *teamStrategy;

    double weight = team->getCurrentCar(index)->getSpecification("Weight")->getTheoreticalValue();
    double Aerodynamics = team->getCurrentCar(index)->getSpecification("Aerodynamics")->getTheoreticalValue();
    double EnginePower = team->getCurrentCar(index)->getSpecification("EnginePower")->getTheoreticalValue();
    double BreakEffieciency = team->getCurrentCar(index)->getSpecification("BreakEffieciency")->getTheoreticalValue();
    double Boost = team->getCurrentCar(index)->getSpecification("Boost")->getTheoreticalValue();

    double total  = weight+Aerodynamics+EnginePower+BreakEffieciency+Boost;

    if(total>1200)
    {
        strategy = new AggressiveCreator(teamStrategy,index);
       return strategy->createStrategy(team);
    }
    if(total<=1200 && total>=700)
    {
       strategy = new SimpleCreator(teamStrategy,index);
       return strategy->createStrategy(team);
    }
    else{
        strategy = new DefaultCreator(teamStrategy,index);
        return strategy->createStrategy(team);
    }
}
