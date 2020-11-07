#include "CarWeightTesting.h"

CarWeightTesting::CarWeightTesting()
{
    confidenceRange=0;
}
Testing::~Testing()
{

}
double CarWeightTesting::getTestedvalue()
{
    return confidenceRange;
}


void CarWeightTesting::TypeOfTest(double cR)
{
    confidenceRange=cR;
    if(cR<0.3)
    {
        testPerformance(cR);
    }
    else
    {
        //send for Testing to Simulator
    }
}
