#include "BreakTesting.h"

BreakTesting::BreakTesting()
{
    confidenceRange=0;
}

BreakTesting::~BreakTesting()
{

}

double BreakTesting::getTestedvalue()
{
    return confidenceRange;
}


void BreakTesting::TypeOfTest(double cR)
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
