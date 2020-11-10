#include "Competition.h"

Competition::Competition(Date sDate, int nTeams, int nRaces)
{
  startDate = sDate;
  prizeGivingDate = sDate;
  endDateSet = false;
  currTeamCount = 0;
  currRaceCount = 0;
  numTeams = nTeams;
  numRaces = nRaces;
  teamList = new F1Team*[numTeams];
  raceList = new RacingEvent*[numRaces];
}

Competition::~Competition()
{
  // TODO - implement Competition::~Competition()
  //throw "Not yet implemented";

  for(int i = 0; i < currTeamCount; i++)
  {
    if(teamList[i] != NULL)
    {
      delete teamList[i];
    }
  }
  delete teamList;

  for (int i = 0; i < currRaceCount; i++)
  {
    if (raceList[i] != NULL)
    {
      delete raceList[i];
    }
  }
  delete raceList;
}

void Competition::update(Date date)
{
  // TODO - implement Competition::update(Date date)
  //Loop throught races and run the ones in progress based on date
  //Need to hold prize giving after all races are complete
  //throw "Not yet implemented";
  if(date < startDate)
  {
    return;
  }

  for (int i = 0; i < currRaceCount; i++)
  {
    if (raceList[i]->getStartDate() <= date && raceList[i]->getEndDate() >= date){
      raceList[i]->runRace(date);
    }

    if(!endDateSet){
      if (raceList[i]->getEndDate() > prizeGivingDate)
      {
        prizeGivingDate = raceList[i]->getEndDate();
      }
    }
  }
  if (!endDateSet)
  {
    endDateSet = true;
    prizeGivingDate.incrementDate(2);
  }
  if (date == prizeGivingDate)
  {
    conductPrizeGiving();
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

void Competition::conductPrizeGiving()
{
  string constructorsName[] = {"-", "-", "-"};
  int constructorsPoints[] = {0, 0, 0};

  string driversName[] = {"-", "-", "-"};
  int driversPoints[] = {0, 0, 0};

  for(int i = 0; i< currTeamCount; i++)
  {
    if(teamList[i]->getPoints() > constructorsPoints[2])
    {
      constructorsPoints[2] = teamList[i]->getPoints();
      constructorsName[2] = teamList[i]->getTeamName();

      if (constructorsPoints[2] > constructorsPoints[1])
      {
        string n = constructorsName[2];
        int p = constructorsPoints[2];
        constructorsName[2] = constructorsName[1];
        constructorsPoints[2] = constructorsPoints[1];
        constructorsName[1] = n;
        constructorsPoints[1] = p;

        if (constructorsPoints[1] > constructorsPoints[0])
        {
          string n = constructorsName[1];
          int p = constructorsPoints[1];
          constructorsName[1] = constructorsName[0];
          constructorsPoints[1] = constructorsPoints[0];
          constructorsName[0] = n;
          constructorsPoints[0] = p;
        }
      }
    }
    for(int j = 0; j < 2; j++){
      if (teamList[i]->getDriver(j)->getPoints() > driversPoints[2])
      {
        driversPoints[2] = teamList[i]->getDriver(j)->getPoints();
        driversName[2] = teamList[i]->getTeamName() + "'s Driver " + to_string(j);

        if (driversPoints[2] > driversPoints[1])
        {
          string n = driversName[2];
          int p = driversPoints[2];
          driversName[2] = driversName[1];
          driversPoints[2] = driversPoints[1];
          driversName[1] = n;
          driversPoints[1] = p;

          if (driversPoints[1] > driversPoints[0])
          {
            string n = driversName[1];
            int p = driversPoints[1];
            driversName[1] = driversName[0];
            driversPoints[1] = driversPoints[0];
            driversName[0] = n;
            driversPoints[0] = p;
          }
        }
      }
    }
  }

  cout << endl
       << "CONGRADULATIONS TO OUR CONSTRUCTORS CHAMPIONSHIP WINNERS!" << endl
       << "In first place we have team '"
       << constructorsName[0]
       << "' with "
       << constructorsPoints[0]
       << " points." << endl
       << "In second place we have team '"
       << constructorsName[1]
       << "' with "
       << constructorsPoints[1]
       << " points." << endl
       << "In third place we have team '"
       << constructorsName[2]
       << "' with "
       << constructorsPoints[2]
       << " points." << endl << endl;

  cout << endl
       << "CONGRADULATIONS TO OUR DRIVERS CHAMPIONSHIP WINNERS!" << endl
       << "In first place we have team "
       << driversName[0]
       << " with "
       << driversPoints[0]
       << " points." << endl
       << "In second place we have team "
       << driversName[1]
       << " with "
       << driversPoints[1]
       << " points." << endl
       << "In third place we have team "
       << driversName[2]
       << " with "
       << driversPoints[2]
       << " points." << endl
       << endl;
}