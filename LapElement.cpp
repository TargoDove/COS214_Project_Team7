#include "LapElement.h"

LapElement::LapElement(int num, LapElement *el)
{
	elementsPerLap = num;
	nextElement = el;
}

virtual LapElement::~LapElement()
{
	if(nextElement != NULL)
	{
		delete nextElement;
	}
}

virtual void LapElement::setNextElement(LapElement *el)
{
	if(nextElement == NULL)
	{
		nextElement = el;
	} 
	else 
	{
		el->setNextElement(nextElement);
		nextElement = el;
	}
}
