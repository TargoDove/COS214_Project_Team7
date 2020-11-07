#include "RaceTrack.h"
#include "Competition.h"

RaceTrack::RaceTrack(int nStraights, int nCorners, string clim, int numLaps, int lLen, string tLocation, string tName, Garage** garageList, boolean inEuro) {
    numStraights = nStraights;
    numCorners = nCorners;
    total = numStraights + numCorners;
    percentStr = 100*numStraights/total;
    percentCor = 100*numCorners/total;
    climate = clim;
    numLaps = numLaps;
    trackLocation = tLocation;
    isEuropean = inEuro;
    trackName = tName;
    lapLen = lLen;
    Garage** garageList; //Paul: hwo should we initialise garageList
    
}
void RaceTrack::setGarageList(Garage** garageList){
	
}

string RaceTrack::getTrackName() {
	return this->trackName;
}

string RaceTrack::getTrackLocation() {
	return this->trackLocation;
}

int RaceTrack::getTotalLength() {
	return this->total;
}

string RaceTrack::checkWeather() {
    return this->climate;
}

boolean RaceTrack::inEurope(){
	return this->isEuropean;
}
