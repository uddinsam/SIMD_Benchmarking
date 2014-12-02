/*
 *  Timer.h
 */

#ifndef TIMER_H
#define TIMER_H

#include <windows.h>
#include <intrin.h>

class timer {
public:
    static void initTimer();

    timer() {
        this->reset();
    }

    void tic();
    void toc();
    void reset();

    void ticRaw();
    void tocRaw();
    unsigned __int64 timeInRawCycles();

    LONGLONG timeInCycles();
    float timeInSeconds();

private:	
    LARGE_INTEGER getTimer();

    static float  SecondsPerCycle;
    LARGE_INTEGER ticTime;
    LARGE_INTEGER tocTime;
    LARGE_INTEGER deltaTime;
    float		  timeSeconds;

    unsigned __int64 ticRawTime;
    unsigned __int64 tocRawTime;
    unsigned __int64 deltaRawTime;

};

#endif TIMER_H