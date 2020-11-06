class WindTunnel {
private:
    int Tokens;
public:
    WindTunnel();
    virtual ~WindTunnel();
    int getTokens();
    void decrement();
    double displayPerformance();
};
