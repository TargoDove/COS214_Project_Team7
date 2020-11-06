#ifndef PRACTICETRACK_H
#define PRACTICETRACK_H
#include "RaceTrack.h"
#include "F1Car.h"
class PracticeTrack {

private:
	int bestScore;
	int worstScore;
	int currentScore;

public:
	/**
	 * simulates track with current components, returns time taken
	 */
	 PracticeTrack();
	 ~PracticeTrack();
	void simulateTrack(F1Car* testCar, RaceTrack* track);

    int getBestScore(){return bestScore;}
    int getCurrentScore(){return currentScore;}
    int getWorstScore(){return worstScore;}

};

#endif

