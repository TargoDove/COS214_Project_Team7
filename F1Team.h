#ifndef F1TEAM_H
#define F1TEAM_H

#include "EventObject.h"
#include "Driver.h"

using namespace std;

class F1Team : public EventObject
{
	public:
    F1Team();
    virtual ~F1Team();
    virtual void update(Date date);
    void setRaceList(RaceingEvent**);
  private:
    string teamName;
    int teamID;
    int points;
    int qualifyScore;
    int windTunnelTokens; //= 400
    double budget;
    F1Car** currentCars;
    F1Car **nextCars;
    Driver** drivers;
    EngineeringDepartments** departments;
    Logistics* logistics;
    RacingEvent** raceList; 
    void applyDepartmentImprovements();
    void applyStrategy();
};

#endif
