#ifndef PITSTOPELEM_H
#define PITSTOPELEM_H

class PitstopElem : LapElement {

public:
	int pitstopTemp;

	string performPitstop(boolean pitstop);

	void handleLap();
};

#endif
