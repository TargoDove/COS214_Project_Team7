#ifndef RACETRACK_H
#define RACETRACK_H

#include "Garage.h"
#include "Competition.h"

class RaceTrack {

private:
	int numStraights;
	int percentStr;
	int numCorners;
	int percentCor;
	int total;
	string climate;
	int numLaps;
	string trackLocation;
	boolean isEuropean;
	string trackName;
	int lapLen;
	Garage** garageList;
	int numberOfGarages;
	LapElement* trackLap;

public:
	RaceTrack(int numStraights, int numCorners, string climate, int numLaps, int lapLen, string trackLocation, string trackName, int numGarages, bool inEuro);
	void ~RaceTrack();
	void buildLap();
	//LapElement* getTrackLap();
	double raceSingleLap(AssembledCar*);
	double raceFull(AssembledCar*);
	string getTrackName();
	string getTrackLocation();
	int getTotalLength();
	string checkWeather();
	Garage** getGarageList();
	Garage *getGarage(int);
	int getNumGarages();

	//void setGarageList(Garage** garageList);
	
	//void setGarageList(Garage** garageList);
};

#endif
