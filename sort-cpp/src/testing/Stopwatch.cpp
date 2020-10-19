//
// Created by Jeroen
//

#include "Stopwatch.h"

#include <iostream>
#include <chrono>

void Stopwatch::start() {
    if (running) {
        std::cerr << "Stopwatch is already running!" << std::endl;
        return;
    }
    running = true;
    started = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop() {
    if (!running) {
        std::cerr << "Stopwatch isn't running!" << std::endl;
        return;
    }
    ended = std::chrono::high_resolution_clock::now();
    running = false;
}

long Stopwatch::getDifference() {
    if (running) {
        std::cerr << "Stopwatch is still running!\nCall stop first!" << std::endl;
        return -1;
    }
    if (started.time_since_epoch().count() < 0 || ended.time_since_epoch().count() < 0) {
        std::cerr << "Stopwatch has not been started!\nNo difference to calculate" << std::endl;
        return -1;
    }
    return std::chrono::duration_cast<std::chrono::nanoseconds>(ended - started).count();
}


