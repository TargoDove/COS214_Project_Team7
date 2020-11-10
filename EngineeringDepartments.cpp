#include "EngineeringDepartments.h"

EngineeringDepartments::EngineeringDepartments(string n, string sp, double b, double p, double s, Testing *t)
{
  name = n;
  specificationName = sp;
  baseImprovementRange = b;
  probabilityOfImprovement = p;
  specialistCost = s;
  numG1Specialists = 0;
  numG2Specialists = 0;
  testing = t;
}

EngineeringDepartments::~EngineeringDepartments()
{
  delete testing;
}

string EngineeringDepartments::getName()
{
  return name;
}

string EngineeringDepartments::getSpecificationName()
{
  return specificationName;
}

void EngineeringDepartments::performImprovement(F1CarSpecification *spec, bool isG1)
{
  double randNum = 1.0 * rand();
  randNum /= RAND_MAX;

  if(randNum <= probabilityOfImprovement){
    spec->addImprovement(getImprovement(isG1, spec));
  }
}

double *EngineeringDepartments::getImprovement(bool isG1, F1CarSpecification *spec)
{
  if (isG1)
    return testing->testComponent(baseImprovementRange * numG1Specialists, spec);
  else
    return testing->testComponent(baseImprovementRange * numG2Specialists, spec);
}

int EngineeringDepartments::getG1Specialists()
{
  return numG1Specialists;
}

int EngineeringDepartments::getG2Specialists()
{
  return numG2Specialists;
}

void EngineeringDepartments::setSpecialists(int g1, int g2)
{
  numG1Specialists = g1;
  numG2Specialists = g2;
}

double EngineeringDepartments::getSpecialistCost()
{
  return specialistCost;
}
