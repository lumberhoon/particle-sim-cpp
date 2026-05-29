#include "raylib.h"
#include <vector>
#include "motion.h"
#include "random.h"
#include "display.h"

int main() {

    const int windowWidth = 800;
    const int windowHeight = 600;
    bool fullscreen = false;

    InitWindow(windowWidth, windowHeight, "Raylib Main");
    SetTargetFPS(120);
    Random random;
    Wall w {};
    bool paused = false;

    std::vector<Particle> particles {};
    for (int i = 0; i < 10 ; ++i) {
        particles.push_back({
            random.rangeFloat(w.lWall, w.rWall),
            random.rangeFloat(w.bWall, w.tWall),
            random.rangeFloat(-3.0f, 3.0f),
            random.rangeFloat(-3.0f, 3.0f)
        });
    }

    while (!WindowShouldClose()) {
        // Keybinds

        if (IsKeyPressed(KEY_A)) {
            if (IsKeyDown(KEY_LEFT_SHIFT)) {
                addRandomParticle(particles, w, random, 1000);
            } else {
                addRandomParticle(particles, w, random, 10);
                }
        }

        if (IsKeyPressed(KEY_E)) {
            if (IsKeyDown(KEY_LEFT_SHIFT)) {
                eraseRaylibParticles(particles, 1000);
            } else {
                eraseRaylibParticles(particles, 10);
            }
        }

        if (IsKeyPressed(KEY_C)) {
            eraseAllParticles(particles);
        }

        if (IsKeyPressed(KEY_SPACE)) {
            paused = !paused;
        }
        
        if (IsKeyPressed(KEY_F)) {
            toggleBorderlessFullscreen(fullscreen, windowWidth, windowHeight);
        }

        updateWalltoScreen(w); 

        if (!paused) {
            updateParticles(particles, w);
        }

        // Start Drawing Logic

        BeginDrawing();
        ClearBackground(BLACK);

        DisplayScale displayScale = calculateDisplayScale(windowWidth);

        drawParticles(particles, displayScale.particleRadius);
        // Texts

        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();
        renderUi(displayScale, particles, screenWidth, screenHeight, paused);

        EndDrawing();

        
    }

    CloseWindow();
    return 0;
}