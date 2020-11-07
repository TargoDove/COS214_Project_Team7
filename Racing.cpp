#include "Racing.h"
#include <algorithm>

Racing::Racing(F1Team** gOrder, int nTeams) {
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

void Racing::addFinalScore(F1Team** team) {
	//sort teams into finish order
    int n = sizeof(team);
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (team[j]->getF1Car(0)->getRaceScore < team[j+1]->getF1Car(0)->getRaceScore)
                swap(&team[j], &team[j+1]);
    }
//give top 10 their points for the race
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
	for (int x = 0; x <n; x++) {
        	finishOrder[x] = team[x];
    }

}

F1Team** Racing::addQualifyScore(F1Team** team) {
	//race one lap and will each car a time
	//this time will then sort them into an array of teams from fastest to slowest
	//similar to addFinalScore
	//returns an array
}

double Racing::raceLapScore() {
	//will inherit from lapElement to race a lap and generate a time
}

string Racing::performPitstop(boolean pitstop) {
	//used to call pitstop class
}

F1Team** Racing::raceEvent(F1Teams** teams) {
	//called after constructor, it encapsualtes multiple functions
	// will take all teams and use raceLapScore for the amount of laps, adding each time to a total time
	//will then use addFinalScore to sort teams
	//returns the sorted list to be used by prize giving
}

