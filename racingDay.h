#ifndef RACINGDAY_H
#define RACINGDAY_H

class racingDay {

private:
	int dayNum;

public:
	/**
	 * simulates at race with all of the teams in teamList, stores score for each team in F1Team score var
	 */
	void raceDay();

	/**
	 * gives each F1Team a score that will be used for the grid layout
	 */
	void raceQualify();

	/**
	 * uses the team list and a sorting algorithm to work out the grid layout
	 * 
	 * (grid layout should give small bonuses to cars with higher rankings)
	 */
	int simulateTrack(F1Car testCar);

	void checkDay();

	void nextDay();
};

#endif
