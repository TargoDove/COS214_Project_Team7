#ifndef PRIZEGIVING_H
#define PRIZEGIVING_H

class PrizeGiving {

private:
	string podium[];
	string engineeringWin;
	string driverWin;
	string teamWin;

public:
	string celebrate();

	void announceWinner();
};

#endif
