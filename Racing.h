#ifndef RACING_H
#define RACING_H

class Racing {

private:
    int numTeams;
	F1Car gridOrder[];
	F1Car finishOrder[];

public:
    Racing(F1Car gOrder[], int nTeams);
    F1Car gOrder[], int nTeams;
	/**
	 * used to add points to a teams finalScore
	 */
	void addFinalScore();

	/**
	 * used to add points to qailfying score
	 */
	void addQualifyScore();

	void raceLapOrder();

	void raceLapScore();

	string performPitstop(boolean pitstop);

	void raceLap();

	int tallyPoints();

	void raceEvent();
};

#endif
