#include "motion.h"
#include "random.h"
#include <iostream>
#include <vector>
#include <limits>

void updatePosition(Particle& p, const Wall& w) {

    p.posX += p.velX;
    p.posY += p.velY;

    if (p.posX >= w.rWall || p.posX <= w.lWall) {
        p.velX = -p.velX;
    } 
    if (p.posY >= w.tWall || p.posY <= w.bWall) {
        p.velY = -p.velY;
    }

    if (p.posX >= w.rWall) {
        p.posX = w.rWall;
    }
    if (p.posX <= w.lWall) {
        p.posX = w.lWall;
    }
    if (p.posY >= w.tWall) {
        p.posY = w.tWall;
    }
    if (p.posY <= w.bWall) {
        p.posY = w.bWall;
    } 
}

void updateParticles(std::vector<Particle>& particles, const Wall& w) {
    for (Particle& p : particles) {
        updatePosition(p, w);
    }
}

void printParticles(const std::vector<Particle>& particles, int frameNum) {
    for (std::size_t i = 0; i < particles.size(); ++i) {
        std::cout << "Frame " << frameNum << " Particle " << i+1 << " position x: " << particles[i].posX
                  << ", Particle " << i+1 << " position y: " << particles[i].posY << "\n";
    }
}


void addRandomParticle(std::vector<Particle>& particles, const Wall& w, Random& random, int count) {
    for (int i = 0; i < count; ++i) {
        Particle particle = createRandomParticle(w, random);
        particles.push_back(particle);
    }
}


Particle createRandomParticle(const Wall& w, Random& random) {
    Particle p = { random.rangeFloat(w.lWall, w.rWall), 
                   random.rangeFloat(w.bWall, w.tWall),
                   random.rangeFloat(-3.0f, 3.0f),
                   random.rangeFloat(-3.0f, 3.0f)
                 };
   return p; 
}

void eraseLastParticle(std::vector<Particle>& particles) {
    bool running = true;
    int count {};
    while (running) {
        
        std::cout << "Particle amount: ";
        std::cin >> count;

        if (count < 0) {
            std::cout << "Cannot be a negative number\n\n";
            continue;
        }

        if (static_cast<std::size_t>(count) > particles.size()) {
            std::cout << "Removal Amount must be smaller or equal to Particle Amount.\n\n";
            continue;

        } 
        
        running = false;
    
        }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < count; ++i) {
        particles.pop_back();
    }
}

void eraseRaylibParticles(std::vector<Particle>& particles, int count) {
    for (int i = 0; i < count; ++i) {
        particles.pop_back();
    }
}

void eraseAllParticles(std::vector<Particle>& particles) {
    particles.clear();

    std::cout << "All particles removed...\n\n";
}