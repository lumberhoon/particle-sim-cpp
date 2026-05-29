#pragma once

#include <random>

class Random {
public:
    Random();

    float rangeFloat(float min, float max);
    int rangeInt(int min, int max);

private:
    std::mt19937 rng;
};
