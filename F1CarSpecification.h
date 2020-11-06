#ifndef F1CARSPECIFICATION_H
#define F1CARSPECIFICATION_H

#include <string>
#include <list>
#include <stdlib.h> /* srand, rand */

using namespace std;

class F1CarSpecification
{
	public:
    F1CarSpecification();
    F1CarSpecification(double);
    virtual ~F1CarSpecification();
    virtual void addImprovement(double *);
    virtual void applyImprovements();
    virtual double getBaseValue();
    virtual double getTheoreticalValue();
    virtual string getName();

  protected:
    string name;
    double baseValue;
    list<double*> improvements;
    int numImprovements;
};

#endif