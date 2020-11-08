#include "Friday.h"

Friday::Friday(RacingEvent* ev) : RacingDay(ev) {
}

void Friday::handle(Date date)
{
  int count = 0;
  if (date.getDayOfWeek() == 5)
  {
    RaceTrack * track = event->getRaceTrack();
    int numTeams = track->getNumGarages();

    for(int i = 0; i < numTeams; i++)
    {
      Garage * garage = track->getGarage(i);
      if(garage != NULL && checkGarage(garage))
      {
        for(int g = 0; g < garage->getNumCars(); g++)
        {
          F1Car * car = garage->getAssembledCar(g)->getF1Car();
          int specNum = 0;
          while(car->getSpecification(specNum) != NULL)
          {
            car->getSpecification(specNum++)->applyImprovements();
          }
          count++;
          carList.push_back(garage->getAssembledCar(g));
        }
      }
    }
    event->setState(new Saturday(ev, carList));
  } else {
    event->setState(NULL);
  }
}
