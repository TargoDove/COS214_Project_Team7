#include "Competition.h"

Competition::Competition(Date sDate, int nTeams, int nRaces)
{
  startdate = sDate;
  numTeams = nTeams;
  numRaces = nRaces;
  teamList = new F1Team*[numTeams];
  raceList = new RaceEvent*[numRaces];
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

  for (int i = 0; i < currRaceCountCount; i++)
  {
    if (raceList[i]->getStartDate() <= date && raceList[i]->getEndDate() >= date){
      raceList[i]->runRace(date);
    }
  }
}

void Competition::addTeam(F1Team *team)
{
  if (currTeamCount != num)
  {
    teamList[currTeamCount++] = team;
  }
  else
  {
    cout << "Team Limit Reached, unable to add team"
  }
}

void Competition::getTeamNames()
{
  for (int i = 0; i < currTeamCount; i++)
  {
    cout << teamList[i]->teamName << " is competing." << endl;
  }
}
void Competition::addRace(RacingEvent *race)
{
  if (currRaceCountCount < numRaces)
  {
    raceList[currRaceCount++] = race;
  }
  else
  {
    cout << "Race Limit Reached, unable to add race"
  }
}
void Competition::getRaceNames()
{
  for (int i = 0; i < currRaceCountCount; i++)
  {
    cout << raceList[i]->raceName << endl;
  }
}