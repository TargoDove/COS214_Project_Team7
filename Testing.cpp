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
double Testing::finalResult()
{
    for(int i=0;i<3; i++)
    {
        confidenceRange=(rand() % 10);
    }
}
