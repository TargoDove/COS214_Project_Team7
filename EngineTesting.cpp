#include "EngineTesting.h"

EngineTesting::EngineTesting()
{
    confidenceRange=0;
}

EngineTesting::~EngineTesting()
{

}

double EngineTesting::getTestedvalue()
{
    return confidenceRange;
}


void EngineTesting::TypeOfTest(double cR)
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
