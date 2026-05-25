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
    bool run = true;

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
        BeginDrawing();
        ClearBackground(BLUE);
        
        for (Particle& p : particles) {
            DrawCircle(p.posX, p.posY, 3, YELLOW);
        }

        if (run) {
            updateParticles(particles, w);
        }

        DrawText("Raylib works", 10, 280, 20, BLACK);
        EndDrawing();

        if (IsKeyPressed(KEY_A)) {
            addRandomParticle(particles, w, random, 10);
        }

        if (IsKeyPressed(KEY_E)) {
            eraseRaylibParticles(particles);
        }

        if (IsKeyPressed(KEY_C)) {
            eraseAllParticles(particles);
        }

        if (IsKeyPressed(KEY_SPACE)) {
            run = !run;
        }
    }

    CloseWindow();
    return 0;
}