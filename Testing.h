#ifndef TESTING_H
#define TESTING_H

#include "TestingMethod.h"
#include "F1CarSpecification.h"

class Testing
{
protected:
    //double confidenceRange;
    TestingMethod* testingMethod;
    Testing *next;

public:
    Testing(Testing *);
    virtual ~Testing();
    virtual double *testComponent(double, F1CarSpecification *) = 0;
    void setNext(Testing*);
    // virtual double getTestedvalue();
    // void TypeOfTest(double); //confidenceRange will be passed through here
};

#endif