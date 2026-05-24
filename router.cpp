#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include "motion.h"
#include "random.h"
#include "commands.h"



void commandRouter(std::vector<Particle>& particles, const Wall& w, Random& random, bool& running) {

    std::string command {};
    std::cout << "Command: ";
    std::cin >> command;      

    std::unordered_map<std::string, std::function<void()>> comMap;

    comMap["a"] = [&particles, &w, &random]() {addParticleCommand(particles, w, random);};
    comMap["e"] = [&particles, &w, &random]() {eraseParticleCommand(particles, w, random);};
    comMap["q"] = [&running]() {std::cout << "Exiting...\n"; running = false;};

        
    if (!(comMap.contains(command))) {
        std::cout << "a: Add more Particles\ne: Erase Particles\nq: Quit\n\n";
    } else {
        comMap[command]();
    }
}


