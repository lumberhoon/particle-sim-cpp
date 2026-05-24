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
            .posX = random.rangeFloat(w.lWall, w.rWall), 
            .posY = random.rangeFloat(w.bWall, w.tWall),
            .velX = random.rangeFloat(-1.0f, 9.5f),
            .velY = random.rangeFloat(-1.0f, 9.5f)
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

