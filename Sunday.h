#ifndef SUNDAY_H
#define SUNDAY_H

class Sunday : RacingDay, Racing, PrizeGiving {


public:
	Sunday();

	void handleNextDay(RacingDay* day);

	void checkDay();
};

#endif

