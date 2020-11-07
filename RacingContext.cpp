#include "RacingContext.h"
#include <iostream>

RacingContext::RacingContext() {
	cout<<"Start of Race Weekend.";
	raceDay = new Friday();
}
RacingContext::~RacingContext(){
    cout<<"End of Race Weekend.";
    delete raceDay;
}

void RacingContext::nextDay() {
	raceDay->handleDay(this);
}

void RacingContext::checkDay() {
	cout<<raceDay->checkDay();
}

void RacingContext::setRacingDay(RacingDay* newRaceDay) {
	delete raceDay;
	raceDay = newRaceDay;
	cout<<"New Race Day."<<endl;
}
