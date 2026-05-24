#include "random.h"

Random::Random()
    : rng(std::random_device{}())
{
}

float Random::rangeFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(rng);
}

int Random::rangeInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}