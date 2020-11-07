#ifndef RACETRACK_H
#define RACETRACK_H

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
	string trackName;
	int lapLen;
	Garage** garageList;

public:
	RaceTrack(int numStraights, int numCorners, string climate, int numLaps, int lapLen, string trackLocation, string trackName, Garage** garageList);

	void ~RaceTrack();

	string getTrackName();

	string getTrackLocation();

	int getTotalLength();

	string checkWeather();
	
	Garage** getGarageList(return garageList;);
};

#endif
