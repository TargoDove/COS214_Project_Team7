#ifndef RACINGCONTEXT_H
#define RACINGCONTEXT_H

class RacingContext {

private:
	RacingDay raceDay;

public:
	RacingContext();

	void ~RacingContext();

	void nextDay();

	void checkDay();

	void setRacingDay(RacingDay* raceDay);
};

#endif
