#include "RacingEvent.h"

RacingEvent::RacingEvent(string name, Date sDate, RaceTrack* trk) {
    raceName = name;
    startDate = sDate;
    track = trk;
}

RaceTrack* RaceTrack::getRaceTrack(){
	return track
}
Date RacingEvent::getDate() {
	return startDate;
}
string RacingEvent::getName() {
    return raceName;
}
