#include "RaceTrack.h"

RaceTrack::RaceTrack(int nStraights, int nCorners, string clim, int numLaps, int lLen, string tLocation, string tName, int numGarages, bool inEuro, double s, double f, double sLen, double penalty)
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
  cornerSharpness = s; //Should ideally be 0.5 to 2
  trackFriction = f;  //Should be between 1.0 and 4.0
  straightLength = sLen;     //Should ideally be 100 to 200
  pitstopTimePenalty = penalty; //Should probably be between 10-20 seconds
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
  delete trackLap;

  for(int i = 0; i < numberOfGarages; i++){
    delete garageList[i];
  }
  delete [] garageList;
}

void RaceTrack::buildLap()
{
  trackLap = new CornerElem(numCorners, NULL, cornerSharpness, trackFriction);
  trackLap = new StraightElem(numStraights, trackLap, straightLength, trackFriction);
  trackLap = new PitstopElem(1, trackLap, pitstopTimePenalty);
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
  return trackName;
}

string RaceTrack::getTrackLocation()
{
  return trackLocation;
}

int RaceTrack::getTotalLength()
{
  return total;
}

string RaceTrack::checkWeather()
{
  return climate;
}

bool RaceTrack::inEurope()
{
  return isEuropean;
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