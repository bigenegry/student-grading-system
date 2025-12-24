#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer() { reset(); }

    void reset() {
        start_ = std::chrono::high_resolution_clock::now();
    }

    long long elapsed_ms() const {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(now - start_).count();
    }

private:
    std::chrono::high_resolution_clock::time_point start_;
};

#endif
