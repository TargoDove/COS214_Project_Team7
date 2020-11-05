#ifndef LAPELEMENT_H
#define LAPELEMENT_H

class LapElement : TrackShape {

private:
	int elementsPerLap;
	LapElement* nextElement;

public:
	int getScore(F1Car* raceCar, RaceTrack* track);

	void simulateLapTime();

	void simulateLapOrder();

	void handleLap();
};

#endif
