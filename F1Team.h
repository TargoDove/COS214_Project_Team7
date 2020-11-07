#ifndef F1TEAM_H
#define F1TEAM_H

#include "EventObject.h"
#include "Driver.h"
#include "F1Car.h"
#include "EngineeringDepartments.h"
#include "Logistics.h"
#include "RacingEvent.h"

using namespace std;

class F1Team : public EventObject
{
	public:
    //F1Team();
    F1Team(string n, int id, double b, F1Car **cCars, F1Car **nCars, Driver **drs);
    virtual ~F1Team();
    virtual void update(Date date);
    void setRaceList(RaceingEvent **rList);
    void setLogistics(Logistics *l);
    void getCurrentCar(int);
    void getNextYearCar(int);
    int points;
    int qualifyScore;
  private:
    string teamName;
    int teamID;
    int windTunnelTokens; //= 400
    double budget;
    F1Car** currentCars;
    F1Car **nextCars;
    Driver** drivers;
    //EngineeringDepartments** departments;
    GenericList<EngineeringDepartments>* departments;
    Logistics* logistics;
    RacingEvent** raceList; 
    void applyDepartmentImprovements();
    void applyStrategy();
};

#endif
