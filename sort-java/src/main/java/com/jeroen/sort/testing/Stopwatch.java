package com.jeroen.sort.testing;

public class Stopwatch {

    void start() {
        if (running) {
            System.err.println("Stopwatch is already running!");
            return;
        }
        running = true;
        started = System.nanoTime();
    }

    void stop() {
        if (!running) {
            System.err.println("Stopwatch isn't running!");
            return;
        }
        ended = System.nanoTime();
        running = false;
    }

    long getDifference() {
        if (running) {
            System.err.println("Stopwatch is still running!\nCall stop first!");
            return -1;
        }
        if (started < 0 || ended < 0) {
            System.err.println("Stopwatch has not been started!\nNo difference to calculate");
            return -1;
        }
        return ended - started;
    }

    private long started = -1;
    private long ended = -1;
    private boolean running = false;

}
