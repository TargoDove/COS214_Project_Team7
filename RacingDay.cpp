#include "RacingDay.h"

RacingDay::RacingDay(RacingEvent* ev)
{
  event = ev;
}

RacingDay::~RacingDay(){}

bool RacingDay::checkGarage(Garage*garage){
  if (garage != NULL && garage->haveTools())
    return true;
  else
    return false;
}
