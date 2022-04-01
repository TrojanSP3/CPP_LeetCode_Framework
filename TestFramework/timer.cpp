#include "timer.h"

Timer::Timer()
{
    started=false;
    stopped=false;
}

void Timer::start()
{
    begin=std::chrono::high_resolution_clock::now();
    started=true;
}

void Timer::stop()
{
    end=std::chrono::high_resolution_clock::now();
    stopped=true;
}

long Timer::countMS()
{
    if(!started)
        return -1;
    if(!stopped)
        end=std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> fsec = end-begin;
    std::chrono::milliseconds d = std::chrono::duration_cast<std::chrono::milliseconds>(fsec);
    return d.count();
}

std::string Timer::toString()
{
    return "Duration: "+std::to_string(countMS())+" ms";
}

