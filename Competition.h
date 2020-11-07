#ifndef COMPETITION_H
#define COMPETITION_H

#include "RacingEvent.h"
#include "EventObject.h"
#include "Date.h"
#include "F1Team.h"

class Competition : EventObject, RacingEvent{

private:
	Date startDate;
	int numTeams;
	int numRaces;
	F1Team* teamList;
	RacingEvent* raceList;
	int currTeamCount = 0;
  int currRaceCount = 0;


public:
	Competition(Date sDate, int nTeams, int nRaces);

	virtual void daysEvents() = 0;

	/**
	 * adds a team to the event
	 */
	void addTeam(F1Team team);

	void addRace(RacingEvent race);

	void getRaceNames();

	void getTeamNames();
};

#endif
