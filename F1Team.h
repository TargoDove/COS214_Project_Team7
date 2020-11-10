#ifndef F1TEAM_H
#define F1TEAM_H

#include "EventObject.h"
#include "Driver.h"
#include "F1Car.h"
#include "EngineeringDepartments.h"
#include "Logistics.h"
#include "RacingEvent.h"
#include "Strategy.h"
#include "Iterator.h"

using namespace std;

class F1Team : public EventObject
{
	public:
    //F1Team();
    F1Team(string n, int id, double b, F1Car **cCars, F1Car **nCars, Driver **drs);
    virtual ~F1Team();
    virtual void update(Date date);
    void setRaceList(RacingEvent **rList);
    void setLogistics(Logistics *l);
    void setCarStrategies();
    F1Car* getCurrentCar(int);
    F1Car *getNextYearCar(int);
    //int qualifyScore;
    string getTeamName();
    double getBudget();
    int getPoints();
    void addPoints(int);
    void addDepartment(EngineeringDepartments*);
    Driver* getDriver(int);
    void applyStrategy();

  private:
    string teamName;
    int teamID;
    int points;
    int windTunnelTokens; //= 400
    double budget;
    F1Car** currentCars;
    F1Car **nextCars;
    Driver** drivers;
    //EngineeringDepartments** departments;
    GenericList<EngineeringDepartments>* departments;
    Logistics* logistics;
    RacingEvent** raceList;
    void applyDepartmentImprovements(F1Car *);
};

#endif
