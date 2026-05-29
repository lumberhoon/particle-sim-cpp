#pragma once
#include "motion.h"
#include <vector>

struct DisplayScale {
    float uiScale;
    float particleRadius;
    int smallText;
    int normalText;
};


void updateWalltoScreen(Wall& w);
void toggleBorderlessFullscreen(bool& fullscreen, int windowWidth, int windowHeight);
void drawParticles(const std::vector<Particle>& particles, float particleRadius);
DisplayScale calculateDisplayScale(int windowWidth);
void renderUi(const DisplayScale& d, const std::vector<Particle>& particles, int screenWidth, int screenHeight, bool paused);