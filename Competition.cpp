#include "Competition.h"

Competition::Competition(Date sDate, int nTeams, int nRaces)
{
  startDate = sDate;
  numTeams = nTeams;
  numRaces = nRaces;
  teamList = new F1Team*[numTeams];
  raceList = new RacingEvent*[numRaces];
}

Competition::~Competition()
{
  // TODO - implement Competition::~Competition()
  throw "Not yet implemented";
}

void Competition::update(Date date)
{
  // TODO - implement Competition::update(Date date)
  //Loop throught races and run the ones in progress based on date
  throw "Not yet implemented";

  for (int i = 0; i < currRaceCount; i++)
  {
    if (raceList[i]->getStartDate() <= date && raceList[i]->getEndDate() >= date){
      raceList[i]->runRace(date);
    }
  }
}

void Competition::addTeam(F1Team *team)
{
  if (currTeamCount != numTeams)
  {
    teamList[currTeamCount++] = team;
  }
  else
  {
    cout << "Team Limit Reached, unable to add team" << endl;
  }
}

void Competition::printTeamNames()
{
  for (int i = 0; i < currTeamCount; i++)
  {
    cout << teamList[i]->getTeamName() << " is competing." << endl;
  }
}
void Competition::addRace(RacingEvent *race)
{
  if (currRaceCount < numRaces)
  {
    raceList[currRaceCount++] = race;
  }
  else
  {
    cout << "Race Limit Reached, unable to add race" << endl;
  }
}
void Competition::printRaceNames()
{
  for (int i = 0; i < currRaceCount; i++)
  {
    cout << raceList[i]->getName() << endl;
  }
}