//
// Created by Jeroen
//

#ifndef SORT_CPP_STOPWATCH_H
#define SORT_CPP_STOPWATCH_H

#include <chrono>

class Stopwatch {
public:
    Stopwatch() = default;

    void start();

    void stop();

    long getDifference();

private:
    typedef std::chrono::high_resolution_clock::time_point TimePoint;

    TimePoint started = std::chrono::high_resolution_clock::from_time_t(-1);
    TimePoint ended = std::chrono::high_resolution_clock::from_time_t(-1);
    bool running = false;
};


#endif //SORT_CPP_STOPWATCH_H
