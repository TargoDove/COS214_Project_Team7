#ifndef AGGRESSIVECREATOR_H
#define AGGRESSIVECREATOR_H

#include "AgressiveStrategy.h"
#include "StrategyCreator.h"

class AggressiveCreator : public StrategyCreator
{
public:
  AggressiveCreator();
  virtual ~AggressiveCreator();
  TeamStrategy *createStrategy(F1Team *team, int index);
};

#endif // AGGRESSIVECREATOR_H
