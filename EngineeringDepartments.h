#ifndef ENGINEERINGDEPARTMENTS_H
#define ENGINEERINGDEPARTMENTS_H

#include <string>
#include "F1CarSpecification.h"
#include "Testing.h"

using namespace std;

class EngineeringDepartments
{
	public:
    //EngineeringDepartments();
    EngineeringDepartments(string n, string sp, double b, double p, double s, Testing *t);
    ~EngineeringDepartments();
    string getName();
    string getSpecificationName();
    void performImprovement(F1CarSpecification *, bool);
    double *getImprovement(bool);
    int getG1Specialists();
    int getG2Specialists();
    void setSpecialists(int, int);

  private:
    string name;
    string specificationName;
    int numG1Specialists;
    int numG2Specialists;
    double probabilityOfImprovement;
    double baseImprovementRange;
    double specialistCost;
    Testing* testing;
};

#endif