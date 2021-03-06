#ifndef F1CAR_H
#define F1CAR_H

#include <string>
#include "TeamStrategy.h"
#include "F1CarSpecification.h"
#include "GenericList.h"
#include "Tires.h"

using namespace std;

class TeamStrategy;

class F1Car
{
	public:
    F1Car();
    ~F1Car();
    F1CarSpecification *getSpecification(int); //Will return NULL if given int is bigger than numberOfSpecifications
    F1CarSpecification *getSpecification(string); //Will return NULL if specificed Specification doesn't exist
    void addSpecification(F1CarSpecification *);
    Tires *getTires();
    Tires* changeTires(Tires*); //Returns old tires and takes new tires
    void setStrategy(TeamStrategy *); //Takes new Strategy and deletes old strategy
    TeamStrategy *getStrategy();
    void addToRaceScore(int lapScore);
	  int getRaceScore();
    string getLocation();
    void setLocation(string);
    bool isCurrentYearCar();
    void setCurrentYear(bool);
    void addRacePoints(int);
    void clearRacePoints();

  private: 
	  int raceScore; //Set back to zero once points have been added to team
    TeamStrategy *strategy;
    string location; //Factory -> home, other options include "in transit" or race locations
    bool currentYearCar;
    GenericList<F1CarSpecification>* carSpecifications;
    Tires *fittedTires;
    //Be better if the spare tires are created and transported and then held in the garage
};

#endif
