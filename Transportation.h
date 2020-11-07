#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H
#include "Container.h"

#include <string>

using namespace std;

class Transportation{
    private:
        Container* container;
    public:
        Transport(Container* c);
        void loadContainer(Container* c);
        Container* unloadContainer();
        virtual sendContainer(Container* c);
}

class Ship : public Transportation{
    private:
        Container* container;
    public:
        Ship(Container* container);
        sendContainer(Container* container);
}

class Truck : public Transportation{
    private:
        Container* container;
    public:
        Truck(Container* container);
        sendContainer(Container* container);
}

class Plane : public Transportation{
    private:
        Container* container;
    public:
        Plane(Container* container);
        sendContainer(Container* container);
}
#endif