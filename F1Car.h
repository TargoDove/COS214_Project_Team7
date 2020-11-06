#ifndef F1CAR_H
#define F1CAR_H

#include <string>
#include "F1CarSpecification.h"
#include "Strategy.h"

using namespace std;

class F1Car
{
	public:
    F1Car();
    ~F1Car();
    F1CarSpecification *getSpecification(int); //Will return NULL if given int is bigger than numberOfSpecifications
    F1CarSpecification *getSpecificationByName(string); //Will return NULL if specificed Specification doesn't exist
    void addSpecification(F1CarSpecification *);
    Tires *getTires();
    Tires* changeTires(Tires*); //Returns old tires and takes new tires
    void setStrategy(Strategy*); //Takes new Strategy and deletes old strategy

  private: 
    Strategy *strategy;
    string location;
    F1CarSpecification** carSpecifications;
    int numberOfSpecifications;
    Tires *fittedTires();
    //Be better if the spare tires are created and transported and then held in the garage
};

#endif