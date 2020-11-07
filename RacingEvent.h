#ifndef RACINGEVENT_H
#define RACINGEVENT_H

#include "RaceTrack.h"
#include "Date.h"

class RacingEvent {

private:
	string raceName;
	Date startDate;
	RaceTrack track;

public:
    RacingEvent(string name, Date sDate, RaceTrack* trk);
    ~RacingEvent();
	RaceTrack getRaceTrack();
	Date getDate();
	string getName();
};

#endif
