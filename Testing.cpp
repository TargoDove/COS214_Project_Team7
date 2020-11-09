#include "Testing.h"

Testing::Testing(Testing *n)
{
    next = n;
    //confidenceRange=0;
    //testingMethod = new TestingMethod();
}

Testing::~Testing()
{
    if(next != NULL)
    {
        delete next;
    }
    delete testingMethod;
}

void Testing::setNext(Testing *n)
{
    if(next == NULL)
    {
        next = n;
    } else 
    {
        n->setNext(next);
        next = n;
    }
}

    // double Testing::getTestedvalue()
    // {
    //     return confidenceRange;
    // }
