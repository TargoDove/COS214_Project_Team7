#ifndef PITSTOPELEM_H
#define PITSTOPELEM_H

#include "LapElement.h"

class PitstopElem : LapElement {

public:
	int pitstopTemp;

	string performPitstop(bool pitstop);

	void handleLap();
};

#endif
