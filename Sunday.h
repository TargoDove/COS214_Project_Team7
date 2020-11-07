#ifndef SUNDAY_H
#define SUNDAY_H

#include "RacingDay.h"
#include "PrizeGiving.h"
#include "Racing.h"

class Sunday : public RacingDay, public Racing, public PrizeGiving {

public:
	Sunday();

	void handleNextDay(RacingDay* day);

	void checkDay();
};

#endif

