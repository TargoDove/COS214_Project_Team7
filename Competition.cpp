#include <iostream>
#include "Competition.h"

Competition::Competition(Date sDate, int nTeams, int nRaces) {
    startdate=sDate;
    numTeams=nTeams;
    numRaces=nRaces;
    teamList = new F1Team[numTeams];
    raceList = new RaceEvent[numRaces];
}

void Competition::addTeam(F1Team team) {
    if (currTeamCount!=num) {
        teamList[currTeamCount] = team;
    }
    else{cout<<"Team Limit Reached, unable to add team"}
}

void Competition::getTeamNames() {
    for (int i = 0; i < numTeams; i++) {
        cout<<teamList[i]->teamName<<" is competing."<<endl;
    }
}
void Competition::addRace(RacingEvent race) {
    if (currRaceCountCount!=numRaces) {
        raceList[currRaceCount] = race;
    }
    else{cout<<"Race Limit Reached, unable to add race"}
}
void Competition::getRaceNames() {
    for (int i = 0; i < numRaces; i++) {
        cout<<raceList[i]->raceName<<endl;
    }
