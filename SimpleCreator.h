#ifndef SIMPLECREATOR_H
#define SIMPLECREATOR_H

#include "StrategyCreator.h"
#include "SimpleStrategy.h"
#include "TeamStrategy.h"

class SimpleCreator : public StrategyCreator
{
public:
  SimpleCreator();
  virtual ~SimpleCreator();
  TeamStrategy *createStrategy(F1Team *team, int index);
};

#endif // SIMPLECREATOR_H
