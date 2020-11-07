#ifndef CORNERELEM_H
#define CORNERELEM_H

#include "LapElement.h"

class CornerElem : LapElement {

public:
	int cornerTemp;

	void takeCorner();

	void handleLap();
};

#endif
