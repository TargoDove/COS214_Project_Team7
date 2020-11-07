#ifndef SATURDAY_H
#define SATURDAY_H

class Saturday : RacingDay, PracticeTrack, Racing{


public:
	Saturday();

	void checkDay();

	void handleNextDay(RacingDay* day);
};

#endif
