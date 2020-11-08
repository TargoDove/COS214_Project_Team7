#include "Friday.h"
#include <iostream>

Friday::Friday(RacingEvent* ev) : RacingDay(ev) {
}

void Friday::handle(Date date)
{
  if (date.getDayOfWeek() == 5)
  {
    
  }
  else
  {
    event->setState(new Saturday(ev));
  }
}
