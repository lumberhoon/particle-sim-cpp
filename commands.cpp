#include <iostream>
#include <vector>
#include <limits>
#include "motion.h"
#include "commands.h"
#include "random.h"


void addParticleCommand(std::vector<Particle>& particles, const Wall& w, Random& random) {
    //Handle type validation later

    int spawnCount {};
    std::cout << "\nAdd Particles: ";
    std::cin >> spawnCount;

    int step {};
    std::cout << "\nFrame count: ";
    std::cin >> step;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    addRandomParticle(particles, w, random, spawnCount);

    for (int i = 0; i < step; ++i) {
        updateParticles(particles, w);
        printParticles(particles, i);
    }
}

void eraseParticleCommand(std::vector<Particle>& particles, const Wall& w, Random& random) {
    return;
}