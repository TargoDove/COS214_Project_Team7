#include "Racing.h"
#include <algorithm>

Racing::Racing(F1Team* gOrder, int nTeams) {
    numTeams = nTeams;
    for (int i = 0; i <nTeams; i++) {
        gridOrder[i] = gOrder[i];
        cout<<"Position "<<i+1<<" is set."<<endl;
        //add a specific buff to cars at the front?
    }
    cout<<"All cars are on the track."<<endl;
}
Racing::~Racing(){
    for (int i = 0; i < numTeams; i++) {
        gridOrder[i] = 0;
    }
    cout<<"All cars are off the track."
}
void Racing::swap(F1Team *xteam, F1Team *yteam)
{
    F1Team temp = *xteam;
    *xteam = *yteam;
    *yteam = temp;
}

void Racing::addFinalScore(F1Team* team) {
    int n = sizeof(team);
    int i, j;
    for (i = 0; i < n-1; i++)
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (team[j]->getF1Car(0)->getRaceScore > team[j+1]->getF1Car(0)->getRaceScore)
                swap(&team[j], &team[j+1]);
    }
    team[0]->points+=25;
    team[1]->points+=18;
    team[2]->points+=15;
    team[3]->points+=12;
    team[4]->points+=10;
    team[5]->points+=8;
    team[6]->points+=6;
    team[7]->points+=4;
    team[8]->points+=2;
    team[9]->points+=1;
	//need to make sure
}

void Racing::addQualifyScore(F1Team* team) {
	sort;
}

void Racing::raceLapOrder() {
	// TODO - implement Racing::simulateLapOrder
	throw "Not yet implemented";
}

void Racing::raceLapScore() {
	// TODO - implement Racing::simulateLapTime
	throw "Not yet implemented";
}

string Racing::performPitstop(boolean pitstop) {
	// TODO - implement Racing::performPitstop
	throw "Not yet implemented";
}

void Racing::raceLap() {
	// TODO - implement Racing::raceLap
	throw "Not yet implemented";
}

int Racing::tallyPoints() {
	// TODO - implement Racing::tallyPoints
	throw "Not yet implemented";
}

void Racing::raceEvent(int numLaps) {
	// TODO - implement Racing::raceEvent
	throw "Not yet implemented";
}


void Racing::raceEvent() {
	// TODO - implement Racing::raceEvent
	throw "Not yet implemented";
}
