#ifndef SIMPLESTRATEGY_H
#define SIMPLESTRATEGY_H

#include "TeamStrategy.h"

class SimpleStrategy : public TeamStrategy
{
public:
  SimpleStrategy();
  virtual ~SimpleStrategy();
  //virtual Tires **getNewTireSets();
  //virtual bool performPitstop(AssembledCar *);
  virtual bool useBoostStraight(Tires *);
  virtual bool useBoostCorner(Tires *);
};
#endif // SIMPLESTRATEGY_H
