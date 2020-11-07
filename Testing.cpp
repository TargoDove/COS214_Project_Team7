#include "Testing.h"
#include <cstdlib>

Testing::Testing()
{
    confidenceRange=0;
}
Testing::~Testing()
{

}
double Testing::getTestedvalue()
{
    return confidenceRange;
}


void Testing::TypeOfTest(double cR)
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
