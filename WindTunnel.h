#include "TestingMethod.h"

class WindTunnel:TestingMethod {
private:
    int Tokens;
public:
    WindTunnel();
    WindTunnel(int);
    virtual ~WindTunnel();
    int getTokens();
    void decrement();
    double displayPerformance();
    virtual void testPerformance(double);
};
