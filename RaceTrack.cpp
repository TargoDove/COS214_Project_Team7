#include "RaceTrack.h"
#include "Competition.h"

RaceTrack::RaceTrack(int nStraights, int nCorners, string clim, int numLaps, int lLen, string tLocation, string tName, Garage** garageList) {
    numStraights = nStraights;
    numCorners = nCorners;
    total = numStraights + numCorners;
    percentStr = 100*numStraights/total;
    percentCor = 100*numCorners/total;
    climate = clim;
    numLaps = numLaps;
    trackLocation = tLocation;
    trackName = tName;
    lapLen = lLen;
    Garage** garageList;
    for (int i = 0; i < Competition->numTeams; ++i) {

    }
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
