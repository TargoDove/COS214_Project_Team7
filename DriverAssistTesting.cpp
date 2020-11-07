#include "DriverAssistTesting.h"

DriverAssistTesting::DriverAssistTesting()
{
    confidenceRange=0;
}

DriverAssistTesting::~DriverAssistTesting()
{

}

double DriverAssistTesting::getTestedvalue()
{
    return confidenceRange;
}


void DriverAssistTesting::TypeOfTest(double cR)
{
    confidenceRange=cR;
    if(cR>0 && cR<0.3 ) //if Range is less than 0.3 then send to WindTunnel for more accurate testing
    {
        testPerformance(cR);
    }
    else
    {
        //send for Testing to Simulator
    }
}
