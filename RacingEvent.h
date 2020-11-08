#ifndef RACINGEVENT_H
#define RACINGEVENT_H

#include "RaceTrack.h"
#include "Date.h"
#include "RacingDay.h"
#include "Friday.h"
#include "Saturday.h"
#include "Sunday.h"

class RacingEvent {

private:
	string raceName;
	Date startDate;
	Date endDate;
	RaceTrack* track;
	RacingDay* dayState;

public:
    RacingEvent(string name, Date sDate, RaceTrack* trk);
    ~RacingEvent();
		void RunRace(Date);
		RaceTrack* getRaceTrack();
		Date getStartDate();
		Date getEndDate();
		string getName();
		void setState(RacingDay*);
};

#endif
