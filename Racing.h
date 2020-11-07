#ifndef RACING_H
#define RACING_H

using namespace std;

class Racing {

private:
    int numTeams;
	F1Car gridOrder[];
	F1Car finishOrder[];

public:
    Racing(F1Car gOrder[], int nTeams);
    ~Racing();
	void swap( int*, int*);
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
