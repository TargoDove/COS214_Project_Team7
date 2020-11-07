#include "Testing.h"
#include "WindTunnel.h"

class DriverAssistTesting: public Testing {
public:
    DriverAssistTesting();
    virtual ~DriverAssistTesting();
    virtual double getTestedvalue();
    virtual void TypeOfTest(double); //confidenceRange will be passed through here
};
