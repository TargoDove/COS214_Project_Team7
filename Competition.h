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
	Date prizeGivingDate;
	bool endDateSet;
	int numTeams;
	int numRaces;
	F1Team** teamList;
	RacingEvent** raceList;
	int currTeamCount;
  int currRaceCount;

public:
	Competition(Date sDate, int nTeams, int nRaces);
	~Competition();
	//virtual void daysEvents() = 0;
	void addTeam(F1Team* team); 					//adds a team to the event
	void addRace(RacingEvent* race);
	F1Team** getTeams();
	int getNumTeams();
	RacingEvent** getRaceList();
	void printRaceNames();
	void printTeamNames();
	void conductPrizeGiving();
	virtual void update(Date);
};

#endif
