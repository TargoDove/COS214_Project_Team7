#ifndef COMPETITION_H
#define COMPETITION_H

#include "RacingEvent.h"
#include "EventObject.h"
#include "Date.h"
#include "F1Team.h"
#include <iostream>

//class Competition : EventObject, RacingEvent{ <- why would this inherit from RacingEvent?
class Competition : public EventObject{

private:
	Date startDate;
	int numTeams;
	int numRaces;
	F1Team** teamList;
	RacingEvent** raceList;
	int currTeamCount = 0;
  int currRaceCount = 0;

public:
	Competition(Date sDate, int nTeams, int nRaces);
	~Competition();
	virtual void daysEvents() = 0;
	void addTeam(F1Team* team); 					//adds a team to the event
	void addRace(RacingEvent* race);
	void printRaceNames();
	void printTeamNames();
	virtual void update(Date);
};

#endif
