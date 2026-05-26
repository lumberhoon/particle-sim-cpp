#include "raylib.h"
#include <iostream>
#include <vector>
#include "motion.h"
#include "random.h"
#include "commands.h"

int main() {
    InitWindow(800,600, "Raylib Main");
    SetTargetFPS(120);
    Random random;
    Wall w {};
    bool paused = false;

    std::vector<Particle> particles {};
    for (int i = 0; i < 600 ; ++i) {
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
            if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_A)) {
                addRandomParticle(particles, w, random, 1000);
            } else {
                addRandomParticle(particles, w, random, 10);
                }
        }

        if (IsKeyPressed(KEY_E)) {
            if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_E)) {
                if (particles.size() >= 1000) {
                    eraseRaylibParticles(particles, 1000);
                }
            } else {
                if (particles.size() >= 10) {
                eraseRaylibParticles(particles, 10);
                }
            }
        }

        if (IsKeyPressed(KEY_C)) {
            eraseAllParticles(particles);
        }

        if (IsKeyPressed(KEY_SPACE)) {
            paused = !paused;
        }

        if (!paused) {
            updateParticles(particles, w);
        }

        // Start Drawing Logic

        BeginDrawing();
        ClearBackground(BLACK);
        
        for (Particle& p : particles) {
            DrawCircle(p.posX, p.posY, 3, YELLOW);
        }

        // Texts

        DrawText(TextFormat("Particles: %zu", particles.size()), 10, 10, 20, WHITE);
        DrawText(TextFormat("FPS: %d", GetFPS()), 700, 10, 20, WHITE); 
        DrawText("A: Add 10 | E: Remove 10 | C: Clear | Space: Pause", 10, 70, 20, WHITE);

        if (!paused) {
            DrawText("Status: Running", 10, 40, 20, WHITE);
        } else {
           DrawText("Status: Paused", 10, 40, 20, WHITE); 
        }

        EndDrawing();

        
    }

    CloseWindow();
    return 0;
}