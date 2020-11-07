#include "Testing.h"
#include "WindTunnel.h"

class EngineTesting:public Testing {
public:
    EngineTesting();
    virtual ~EngineTesting();
    virtual double getTestedvalue();
    virtual void TypeOfTest(double); //confidenceRange will be passed through here

};
