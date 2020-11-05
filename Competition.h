#ifndef COMPETITION_H
#define COMPETITION_H

class Competition : EventObject, RacingEvent{

private:
	int startDate;
	int numTeams;
	int numRaces;
	F1Team* teamList;
	RacingEvent* raceList;
	int currTeamCount = 0;
    int currRaceCount = 0;


public:
	Competition(int startDate, int numTeams, RacingEvent raceEvents[]);

	virtual void daysEvents() = 0;

	/**
	 * adds a team to the event
	 */
	void addTeam(F1Team parameter);

	void addRace(Racing Event);

	void getRaceNames();

	void getTeamNames();
};

#endif
