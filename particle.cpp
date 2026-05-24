#include "motion.h"
#include "random.h"
#include <iostream>

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
    Particle p = { .posX = random.rangeFloat(w.lWall, w.rWall), 
                   .posY = random.rangeFloat(w.bWall, w.tWall),
                   .velX = random.rangeFloat(-1.0f, 9.5f),
                   .velY = random.rangeFloat(-1.0f, 9.5f)
                 };
   return p; 
}