#include "Testing.h"
#include "WindTunnel.h"

class AeroTesting: public Testing {

public:
    AeroTesting();
    virtual ~AeroTesting();
    virtual double getTestedvalue();
    virtual void TypeOfTest(double); //confidenceRange will be passed through here

};
