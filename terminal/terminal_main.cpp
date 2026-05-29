#include <iostream>
#include <vector>
#include <unordered_map>
#include "motion.h"
#include "random.h"
#include "commands.h"

int main() {
    Random random;
    Wall w {};
    int step = 20;

    std::vector<Particle> particles {};
    for (int i = 0; i < 3; ++i) {
        particles.push_back({ 
            random.rangeFloat(w.lWall, w.rWall), 
            random.rangeFloat(w.bWall, w.tWall),
            random.rangeFloat(-3.0f, 3.0f),
            random.rangeFloat(-3.0f, 3.0f)
        });
    }

    for (int i = 0; i < step; ++i) {
        updateParticles(particles, w);
        printParticles(particles, i);
    }
    bool running = true;
    while (running) {
        commandRouter(particles, w, random, running);
    }

    return 0;
}

