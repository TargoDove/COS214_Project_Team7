#ifndef TEAMSTRATEGY_H
#define TEAMSTRATEGY_H

//#include "F1Team.h"
#include "SoftTires.h"
#include "MediumTires.h"
#include "HardTires.h"
#include "AssembledCar.h"

class AssembledCar;

class TeamStrategy
{
public:
  //TeamStrategy(F1Team *team, int index);
  virtual ~TeamStrategy();
  virtual Tires **getNewTireSets();
  virtual bool performPitstop(AssembledCar *);
  virtual bool useBoostStraight(Tires *) = 0;
  virtual bool useBoostCorner(Tires *) = 0;
  virtual int getPriority(string);

protected:
  double integrityCutoff;
  Tires** templateSet;
  int tireSetSize;
  int * priorities;

};

#endif // TEAMSTRATEGY_H
