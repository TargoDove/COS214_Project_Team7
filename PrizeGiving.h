#ifndef PRIZEGIVING_H
#define PRIZEGIVING_H

#include "Racing.h"
#include <string>

class PrizeGiving: public Racing{

private:
	string driver1st;
    string driver2nd;
    string driver3rd;
	string teamWin;

public:
    PrizeGiving();

    ~PrizeGiving();

	void celebrate();

	void announceWinner();

};

#endif
