#ifndef RACINGDAY_H
#define RACINGDAY_H

class RacingDay {


public:
	virtual void handleNextDay(RacingDay* day);

	virtual void checkDay();

	void ~RacingDay();
};

#endif
