#include "Sunday.h"
#include <iostream>

Sunday::Sunday() {
	checkDay();
	//Call the race function;
	//call prize giving function
	PrizeGiving* prizeGiving = new PrizeGiving();
	prizeGiving->announceWinners();
}

void Sunday::handleNextDay(RacingDay* day) {
	~RacingContext();
}

void Sunday::checkDay() {
    cout<<"Today is Sunday, Race Day."<<endl;
}
