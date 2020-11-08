#include "Friday.h"
#include <iostream>

Friday::Friday(RacingEvent* ev) : RacingDay(ev) {
}

void Friday::handle(Date date)
{
  if (date.getDayOfWeek() == 5)
  {
    RaceTrack * track = event->getRaceTrack()
    int numTeams = track->getNumGarages();

    for(int i = 0; i < numTeams; i++)
    {
      Garage * garage = track->getGarage(i);
      if(garage != NULL && checkGarage(garage))
      {
        for(int g = 0; g < garage->getNumCars(); g++)
        {
          F1Car * car = garage->getF1Car(g);
          int specNum = 0;
          while(car->getSpecification(specNum) != NULL)
          {
            car->getSpecification(specNum++)->applyImprovements();
          }
        }
      }
    }
  }
  else
  {
    event->setState(new Saturday(ev));
  }
}
