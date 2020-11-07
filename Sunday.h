#ifndef SUNDAY_H
#define SUNDAY_H

class Sunday : RacingDay, Racing {


public:
	Sunday();

	void handleNextDay(RacingDay* day);

	void checkDay();
};

#endif

