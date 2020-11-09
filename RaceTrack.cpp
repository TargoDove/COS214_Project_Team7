#include "RaceTrack.h"

RaceTrack::RaceTrack(int nStraights, int nCorners, string clim, int numLaps, int lLen, string tLocation, string tName, int int numGarages, boolean inEuro)
{
  numStraights = nStraights;
  numCorners = nCorners;
  total = numStraights + numCorners;
  percentStr = 100 * numStraights / total;
  percentCor = 100 * numCorners / total;
  climate = clim;
  numLaps = numLaps;
  trackLocation = tLocation;
  isEuropean = inEuro;
  trackName = tName;
  lapLen = lLen;
  numberOfGarages = numGarages;
  garageList = new Garage *[numberOfGarages];
  trackLap = NULL;
  for (int i = 0; i < numberOfGarages; i++)
  {
    garageList[i] = new Garage();
  }
  buildLap();
}
// void RaceTrack::setGarageList(Garage** garageList){
// 	//change garageList??
// }

RaceTrack::~RaceTrack()
{
  // TODO - implement RaceTrack::~RaceTrack()
  throw "Not yet implemented";
}

void RaceTrack::buildLap()
{
  // TODO - implement RaceTrack::buildLap()
  //Need to create and link all the raceElements here
  throw "Not yet implemented";
}

double RaceTrack::raceSingleLap(AssembledCar * car)
{
  double time = 0;
  trackLap->handleLap(car, &time);
  return time;
}

double RaceTrack::raceFull(AssembledCar *car)
{
  double time = 0;
  for(int i = 0; i < numLaps; i++){
    trackLap->handleLap(car, &time);
  }
  return time;
}

// LapElement *RaceTrack::getTrackLap()
// {
//   return trackLap;
// }

string RaceTrack::getTrackName()
{
  return this->trackName;
}

string RaceTrack::getTrackLocation()
{
  return this->trackLocation;
}

int RaceTrack::getTotalLength()
{
  return this->total;
}

string RaceTrack::checkWeather()
{
  return this->climate;
}

boolean RaceTrack::inEurope()
{
  return this->isEuropean;
}

Garage **RaceTrack::getGarageList()
{
  return garageList;
}
Garage *RaceTrack::getGarage(int index)
{
  if (index < numberOfGarages)
  {
    return garageList[index];
  }
  else
  {
    return NULL;
  }
}
int RaceTrack::getNumGarages()
{
  return numberOfGarages;
}