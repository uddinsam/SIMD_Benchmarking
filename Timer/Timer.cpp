/*
 *  Timer.cpp
 */

#include <windows.h>
#include <assert.h>

#include "Timer.h"

float timer::SecondsPerCycle = 0.0f;

void timer::initTimer() {
    LARGE_INTEGER Frequency;
    QueryPerformanceFrequency(&Frequency);
    SecondsPerCycle = 1.0f / Frequency.QuadPart;
}

LARGE_INTEGER timer::getTimer() {
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);
    return time;
}

void timer::tic() {
    ticTime = this->getTimer();
}

void timer::toc() {
    tocTime = this->getTimer();
    assert( tocTime.QuadPart > ticTime.QuadPart );
    deltaTime.QuadPart = tocTime.QuadPart - ticTime.QuadPart;
}

void timer::ticRaw() {
    ticRawTime = __rdtsc();
}

void timer::tocRaw() {
    tocRawTime = __rdtsc();
    deltaRawTime = tocRawTime - ticRawTime;
}

void timer::reset() {
    ticTime.QuadPart = 0;
    tocTime.QuadPart = 0;
    deltaTime.QuadPart = 0;
    ticRawTime = 0;
    tocRawTime = 0;
    deltaRawTime = 0;
}

unsigned __int64 timer::timeInRawCycles() {
    return deltaRawTime;
}

LONGLONG timer::timeInCycles() {
    return deltaTime.QuadPart;
}

float timer::timeInSeconds() {
    float floatTime;
    floatTime = static_cast<float>(deltaTime.QuadPart);
    floatTime *= SecondsPerCycle;
    return floatTime;
}