#pragma once
#include <vector>
#include "motion.h"
#include "random.h"



void commandRouter(std::vector<Particle>& particles, const Wall& w, Random& random, bool& running);
void addParticleCommand(std::vector<Particle>& particles, const Wall& w, Random& random);
void eraseParticleCommand(std::vector<Particle>& particles, const Wall& w, Random& random);
