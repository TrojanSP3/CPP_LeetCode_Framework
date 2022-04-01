#ifndef TIMER_H
#define TIMER_H

#include <string>
#include <chrono>

class Timer
{
public:
    Timer();
    void start();
    void stop();
    long countMS();
    std::string toString();
private:
    std::chrono::high_resolution_clock::time_point begin;
    std::chrono::high_resolution_clock::time_point end;
    bool started;
    bool stopped;
};

#endif // TIMER_H
