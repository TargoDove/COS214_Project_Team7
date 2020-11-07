#ifndef SATURDAY_H
#define SATURDAY_H

#include "RacingDay.h"
#include "PracticeTrack.h"
#include "Racing.h"

class Saturday : public RacingDay, public PracticeTrack, public Racing
{

public:
	Saturday();

	void checkDay();

	void handleNextDay(RacingDay* day);
};

#endif
