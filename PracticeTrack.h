#ifndef PRACTICETRACK_H
#define PRACTICETRACK_H

class PracticeTrack {

private:
	float currentTime;
	float bestTime;
	/**
	 * the amount of practice laps taken
	 */
	int practiceLaps;

public:
	/**
	 * simulates track with current components, returns time taken
	 */
	int simulateTrack(F1Car testCar);
};

#endif
