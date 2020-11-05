#ifndef RACING_H
#define RACING_H

class Racing {

private:
	F1Car gridOrder[];
	F1Car finishOrder[];

public:
	/**
	 * used to add points to a teams finalScore
	 */
	void addFinalScore();

	/**
	 * used to add points to qailfying score
	 */
	void addQualifyScore();

	void simulateLapOrder();

	void simulateLapTime();

	string performPitstop(boolean pitstop);

	void raceLap();

	int tallyPoints();

	void raceEvent();
};

#endif
