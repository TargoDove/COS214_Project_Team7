#ifndef TRACKSHAPE_H
#define TRACKSHAPE_H

class TrackShape {

private:
	int numStraights;
	int numCorners;
	int pitstop;

public:
	TrackShape(int numStraights, int numCorners);

	void ~TrackShape();
};

#endif
