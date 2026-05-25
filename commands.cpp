#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <functional>
#include <unordered_map>
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
    
    std::string command {};
    std::cout << "Erase Command: ";
    std::cin >> command;

    std::unordered_map<std::string, std::function<void()>> eraseMap;

    eraseMap["all"] = [&particles]() {eraseAllParticles(particles);};
    eraseMap["some"] = [&particles]() {eraseLastParticle(particles);};

    auto it = eraseMap.find(command);

    if (it == eraseMap.end() || command.empty()) {
        std::cout << "all: Remove all Particles\nsome: Erase some Particles\n\n";
    } else {
        it->second();
    }

}