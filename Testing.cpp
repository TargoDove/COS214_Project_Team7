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

