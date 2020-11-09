#ifndef DEFAULTCREATOR_H
#define DEFAULTCREATOR_H

#include "DefaultStrategy.h"
#include "SimpleCreator.h"

class DefaultCreator : public StrategyCreator
{
public:
  DefaultCreator();
  virtual ~DefaultCreator();
  TeamStrategy *createStrategy(F1Team *team, int index);
};

#endif // DEFAULTCREATOR_H
