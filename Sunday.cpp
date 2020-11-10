#include "Sunday.h"

Sunday::Sunday(RacingEvent *ev, list<AssembledCar *> l) : RacingDay(ev)
{
	carList = l;
	int pArray[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
	pointsArraySize = 10;

	pointsArray = new int[pointsArraySize];
	for (int i = 0; i < pointsArraySize; i++){
		pointsArray[i] = pArray[i];
	}
}

Sunday::~Sunday()
{
	delete [] pointsArray;
}

void Sunday::handle(Date)
{
	if (date.getDayOfWeek() == 7 && !carList.empty())
	{
		RaceTrack *track = event->getRaceTrack();

		for (AssembledCar *car : carList)
		{
			car->setRaceTime(track->raceFull(car));
		}

		int size = carList->size();

		//bubble sort
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 1; j < size; j++)
			{
				if (carList[j - 1]->getRaceTime() > carList[j]->getRaceTime())
				{
					swap(carList[j - 1], carList[j]);
				}
			}
		}

		for (int i = 0; i < pointsArraySize; i++)
		{
			carList[i]->getF1Car()->addRacePoints(pointsArray(i));
			carList[i]->getDriver()->addPoints(pointsArray(i));
		}
	}
	event->setState(NULL);
}
