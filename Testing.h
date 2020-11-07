#include "TestingMethod.h"
#include "WindTunnel.h"

class Testing:public WindTunnel {

protected:
    double confidenceRange;


public:
        Testing();
        virtual ~Testing();
        virtual double getTestedvalue();
        void TypeOfTest(double); //confidenceRange will be passed through here

};
