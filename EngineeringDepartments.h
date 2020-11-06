#ifndef ENGINEERINGDEPARTMENTS_H
#define ENGINEERINGDEPARTMENTS_H

#include <string>
#include "F1CarSpecification.h"
#include "Testing.h"

using namespace std;

class EngineeringDepartments
{
	public:
    EngineeringDepartments();
    ~EngineeringDepartments();
    string getName();
    void performImprovement(F1CarSpecification*);
    double* getImprovement();
    int getG1Specialists();
    int getG2Specialists();
    void setSpecialists(int, int);

  private:
    string name;
    int numG1Specialists;
    int numG2Specialists;
    double probabilityOfImprovement;
    double baseImprovementRange;
    double specialistCost;
    Testing* testing;
};

#endif