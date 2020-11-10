#ifndef AGRESSIVESTRATEGY_H
#define AGRESSIVESTRATEGY_H

#include "TeamStrategy.h"

class AgressiveStrategy : public TeamStrategy
{
public:
  AgressiveStrategy();
  virtual ~AgressiveStrategy();
  //virtual Tires **getNewTireSets();
  //virtual bool performPitstop(AssembledCar *);
  virtual bool useBoostStraight(Tires *);
  virtual bool useBoostCorner(Tires *);
};

#endif // AGRESSIVESTRATEGY_H
