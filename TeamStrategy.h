#ifndef TEAMSTRATEGY_H
#define TEAMSTRATEGY_H

#include "F1Team.h"
#include "SoftTires.h"
#include "MediumTires.h"
#include "HardTires.h"

class TeamStrategy
{
public:
  //TeamStrategy(F1Team *team, int index);
  virtual ~TeamStrategy();
  virtual Tires **getNewTireSets();
  virtual bool performPitstop(AssembledCar *);
  virtual bool useBoostStraight(Tires *) = 0;
  virtual bool useBoostCorner(Tires *) = 0;
  //virtual void print() = 0;
  //virtual bool UseBoost() = 0;

  //F1Team *getTeam();
  //bool getBoost();
  //void setBoost(bool expression);
  //int getIndex();

protected:
  double integrityCutoff;
  Tires** templateSet;
  int tireSetSize;
//   //bool boost;
//   //F1Team *team;
//   //int index;
};

#endif // TEAMSTRATEGY_H
