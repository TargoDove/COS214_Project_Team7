#include "CompetitionBuilder.h"

void CompetitionBuilder::buildRacingEvents()
{
  //numRacingEvents = 21;

  Date date(1, 2, 2018);
  for(int i = 0; i < numRacingEvents; i++)
  {
    date.incrementDate(13);
    int nStraights = (int) 20+20*randNumGen();
    int nCorners = (int) 20 + 20 * randNumGen();
    int numLaps = (int) 30 + 20 * randNumGen();
    double sLen = 100 + 100 * randNumGen();
    double s = 0.5 + 1.5 * randNumGen();
    double f = 1 + 3 * randNumGen();
    double penalty = 15 + 10 * randNumGen();
    string clim = "Hot";
    string loc = "Location-" + to_string(i);
    string tName = "Track-" + to_string(i);
    Date tDate(1, 4, 2018);
    bool inEuro = (date > tDate) && (randNumGen() >= 0.8);

    RaceTrack *raceTrack = new RaceTrack(nStraights, nCorners, clim, numLaps, numLaps * sLen, loc, tName, 10, inEuro, s, f, sLen, penalty);

    RacingEvent* rEvent = new RacingEvent("RacingEvent"+to_string(i+1), date, raceTrack);
    comp->addRace(rEvent);
    date = rEvent->getStartDate();
  }
}

void CompetitionBuilder::buildF1Teams()
{
  string names[] = {"Mercedes",
                    "Ferrari",
                    "McLaren",
                    "Alpha",
                    "Beta",
                    "Red Bull",
                    "Williams",
                    "Red Point",
                    "Haas",
                    "Romeo"};
  //numTeams = 10;
  //numTeams = sizeof(names)/sizeof(names[0]);
  int numCars = 2;

  double budget;
  F1Car **cCars = new F1Car *[numCars];
  F1Car **nCars = new F1Car *[numCars];
  Driver **drivers = new Driver *[numCars];

  for (int i = 0; i < numTeams; i++)
  {
    budget = 800000 + 400000 * (((double)rand() * 1.0) / RAND_MAX);
    for (int j = 0; j < numCars; j++)
    {
      cCars[j] = new F1Car();
      cCars[j]->setCurrentYear(true);
      addSpecifications(cCars[j]);
      nCars[j] = new F1Car();
      nCars[j]->setCurrentYear(false);
      addSpecifications(nCars[j]);
      drivers[j] = new Driver(100, 0, "Driver" + to_string(j));
    }
    F1Team *tm = new F1Team(names[i], i + 1, budget, cCars, nCars, drivers);
    tm->setCarStrategies();
    tm->setRaceList(events);
    tm->setLogistics(new Logistics(events, cCars, drivers));
    addDepartments(tm);
    tm->applyStrategy();
    comp->addTeam(tm);
  }

  //delete[] names;
  delete[] cCars;
  delete[] nCars;
  delete[] drivers;
}

void CompetitionBuilder::addSpecifications(F1Car *car)
{
  car->addSpecification(new BreakEfficiency());
  car->addSpecification(new Boost());
  car->addSpecification(new EnginePower());
  car->addSpecification(new DriverAssistance());
  car->addSpecification(new Weight());
  car->addSpecification(new Aerodynamics());
}

void CompetitionBuilder::addDepartments(F1Team *team)
{
  WindTunnel* windTunnel = new WindTunnel();
  Testing *testing = new CarWeightTesting(NULL, windTunnel);
  testing = new BreakTesting(testing, windTunnel);
  testing = new AeroTesting(testing, windTunnel);
  testing = new BoostTesting(testing, windTunnel);
  testing = new EngineTesting(testing, windTunnel);
  testing = new DriverAssistTesting(testing, windTunnel);

  team->addDepartment(new EngineeringDepartments("Aerodynamics", "Aerodynamics", 0.1, 0.14, 40000, testing));
  team->addDepartment(new EngineeringDepartments("Mechanics", "BreakEfficiency", 0.082, 0.14, 40000, testing));
  team->addDepartment(new EngineeringDepartments("Engine", "EnginePower", 0.075, 0.14, 40000, testing));
  team->addDepartment(new EngineeringDepartments("Chassis", "Weight", 0.06, 0.14, 40000, testing));
  team->addDepartment(new EngineeringDepartments("Experimental", "Boost", 0.09, 0.14, 40000, testing));
  team->addDepartment(new EngineeringDepartments("Electronics", "DriverAssistance", 0.08, 0.14, 40000, testing));
}

double CompetitionBuilder::randNumGen()
{
  return (((double)rand() * 1.0) / RAND_MAX);
}

void CompetitionBuilder::buildCompetition()
{
  numTeams = 10;
  numRacingEvents = 21;
  Date date(12, 1, 2018);

  comp = new Competition(date, numTeams, numRacingEvents);

  events = comp->getRaceList();
  teams = comp->getTeams();
}
