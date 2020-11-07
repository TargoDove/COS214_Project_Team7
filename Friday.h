#ifndef FRIDAY_H
#define FRIDAY_H

class Friday : RacingDay, PracticeTrack {


public:
	Friday();

	void checkDay();

	void handleNextDay(RacingDay* day);
};

#endif
