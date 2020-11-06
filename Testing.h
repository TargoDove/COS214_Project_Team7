#include "TestingMethod.h"

class Testing {

private:
    double confidenceRange;
    TestingMethod *testingMethod;
    virtual double getTestedvalue();
    virtual double finalResult();

public:
        Testing();
        virtual ~Testing();
        double *testComponent(double);
};
