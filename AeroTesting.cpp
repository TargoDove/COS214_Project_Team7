#include "AeroTesting.h"

AeroTesting::AeroTesting()
{
    confidenceRange=0;
}

AeroTesting::~AeroTesting()
{

}

double AeroTesting::getTestedvalue()
{
    return confidenceRange;
}


void AeroTesting::TypeOfTest(double cR)
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
