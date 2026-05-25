#pragma once
#include <vector>
#include "random.h"

struct Particle {
    float posX {0.0f};
    float posY {0.0f};
    float velX {2.2f};
    float velY {3.2f};
};

struct Wall {
    float lWall {0.0f};
    float rWall {800.0f};
    float bWall {0.0f};
    float tWall {600.0f};
};

void updatePosition(Particle& p, const Wall& w);
void updateParticles(std::vector<Particle>& particles, const Wall& w);
void printParticles(const std::vector<Particle>& particles, int frameNum);
Particle createRandomParticle(const Wall& w, Random& random);
void addRandomParticle(std::vector<Particle>& particles, const Wall& w, Random& random, int count);
void eraseLastParticle(std::vector<Particle>& particles);
void eraseRaylibParticles(std::vector<Particle>& particles);
void eraseAllParticles(std::vector<Particle>& particles);