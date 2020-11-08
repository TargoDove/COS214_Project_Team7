#include "Saturday.h"

Saturday::Saturday(RacingEvent *ev, list<AssembledCar *> l) : RacingDay(ev)
{
  carList = l;
}

void Saturday::handle(Date)
{
  if (date.getDayOfWeek() == 6 && !carList.empty())
  {
    RaceTrack * track = event->getRaceTrack();

    for (AssembledCar * car: carList){
      car->setRaceTime(track->raceSingleLap(car));
    }

    int size = carList->size();

    //bubble sort
    for(int i = 0; i < size-1; i++){
      for(int j = 1; j < size; j++){
        if (carList[j - 1]->getRaceTime() > carList[j]->getRaceTime())
        {
          swap(carList[j - 1], carList[j]);
        }
      }
    }

    event->setState(new Sunday(ev, carList));
  } else {
    event->setState(NULL);
  }
}