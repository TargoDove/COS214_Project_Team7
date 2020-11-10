#ifndef RACETRACK_H
#define RACETRACK_H

#include "Garage.h"
#include "Competition.h"
#include "CornerElem.h"
#include "PitstopElem.h"
#include "StraightElem.h"

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
	bool isEuropean;
	string trackName;
	int lapLen;
	Garage **garageList;
	int numberOfGarages;
	LapElement *trackLap;
	double cornerSharpness; //Should ideally be 0.5 to 2
	double trackFriction;		//Should be between 1.0 and 4.0
	double straightLength;	//Should ideally be 100 to 200
	double pitstopTimePenalty;

public:
	RaceTrack(int nStraights, int nCorners, string clim, int numLaps, int lLen, string tLocation, string tName, int numGarages, bool inEuro, double s, double f, double sLen, double penalty);
	~RaceTrack();
	void buildLap();
	//LapElement* getTrackLap();
	double raceSingleLap(AssembledCar *);
	double raceFull(AssembledCar *);
	string getTrackName();
	string getTrackLocation();
	int getTotalLength();
	string checkWeather();
	Garage **getGarageList();
	Garage *getGarage(int);
	int getNumGarages();
	bool inEurope();

	//void setGarageList(Garage** garageList);

	//void setGarageList(Garage** garageList);
};

#endif
