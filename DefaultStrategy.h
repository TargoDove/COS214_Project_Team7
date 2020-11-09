#ifndef DEFAULTSTRATEGY_H
#define DEFAULTSTRATEGY_H

#include "TeamStrategy.h"

class DefaultStrategy:public TeamStrategy
{
public:
  DefaultStrategy();
  virtual ~DefaultStrategy();
  //virtual Tires **getNewTireSets();
  //virtual bool performPitstop(AssembledCar *);
  virtual bool useBoostStraight(Tires *);
  virtual bool useBoostCorner(Tires *);
};

#endif // DEFAULTSTRATEGY_H
