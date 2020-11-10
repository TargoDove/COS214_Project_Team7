#ifndef STRATEGYCREATOR_H
#define STRATEGYCREATOR_H

#include "TeamStrategy.h"
//#include "F1Team.h"

class StrategyCreator
{
public:
  StrategyCreator();
  virtual ~StrategyCreator();

  virtual TeamStrategy *createStrategy(F1Team *team, int index) = 0;
};

#endif // STRATEGYCREATOR_H
