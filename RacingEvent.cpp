#include "RacingEvent.h"

RacingEvent::RacingEvent(string name, Date sDate, RaceTrack* trk) {
    raceName = name;
    startDate = sDate;
    track = trk;
}
Date RacingEvent::getDate() {
	return startDate;
}
string RacingEvent::getName() {
    return raceName;
}
