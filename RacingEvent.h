#ifndef RACINGEVENT_H
#define RACINGEVENT_H

class RacingEvent {

private:
	string raceName;
	Date startDate;
	RaceTrack track;

public:
    RacingEvent(string name, Date sDate, RaceTrack trk);
    ~RacingEvent();
	Date getDate();
	string getName();
};

#endif
