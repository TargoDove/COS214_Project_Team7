#ifndef CORNERELEM_H
#define CORNERELEM_H

class CornerElem : LapElement {

public:
	int cornerTemp;

	void takeCorner();

	void handleLap();
};

#endif
