#ifndef RACINGDAY_H
#define RACINGDAY_H

class RacingDay {

public:
	//state for the days
	//completely virtual
	virtual void handleNextDay(RacingDay* day);

	virtual void checkDay();

	~RacingDay();
};

#endif
