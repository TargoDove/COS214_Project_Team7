#include "Director.h"

Director::Director(Builder*b)
{
  builder = b;
}
  Director::~Director()
  {
    delete builder;
  }
  void Director::construct()
  {
    builder->buildCompetition();
    builder->buildRacingEvents();
    builder->buildF1Teams();
  }