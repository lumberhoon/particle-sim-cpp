#include "raylib.h"
#include <iostream>
#include <vector>
#include "motion.h"
#include "random.h"
#include "commands.h"

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
            fullscreen = !fullscreen;

        if (fullscreen) {
            int monitor = GetCurrentMonitor();
            Vector2 monitorPos = GetMonitorPosition(monitor);

            SetWindowState(FLAG_WINDOW_UNDECORATED);
            SetWindowPosition(static_cast<int>(monitorPos.x), static_cast<int>(monitorPos.y));
            SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
        } else {
            ClearWindowState(FLAG_WINDOW_UNDECORATED);
            SetWindowSize(windowWidth, windowHeight);
            SetWindowPosition(100, 100);
        }
}

        w.lWall = 0.0f;
        w.rWall = static_cast<float>(GetScreenWidth());
        w.bWall = 0.0f;
        w.tWall = static_cast<float>(GetScreenHeight());

        if (!paused) {
            updateParticles(particles, w);
        }

        // Start Drawing Logic

        BeginDrawing();
        ClearBackground(BLACK);
        
        float uiScale = static_cast<float>(GetScreenWidth()) / static_cast<float>(windowWidth);

        if (uiScale > 1.35f) {
            uiScale = 1.35f;
        }

        float particleRadius = 3.0f * uiScale;
        int smallText = static_cast<int>(10 * uiScale);
        int normalText = static_cast<int>(20 * uiScale);

        for (Particle& p : particles) {
            DrawCircle(p.posX, p.posY, particleRadius, YELLOW);
        }

        // Texts

        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        DrawText(TextFormat("Particles: %zu", particles.size()), 10, 10, smallText, WHITE);
        const char* fpsText = TextFormat("FPS: %d", GetFPS());
        DrawText(fpsText, screenWidth - MeasureText(fpsText, normalText) - 10, 10, normalText, WHITE); 
        DrawText("A: Add 10 | E: Remove 10 | C: Clear | Space: Pause", 10, 70, smallText, WHITE);
        DrawText("SHIFT + A: Add 1,000 | SHIFT + E: Remove 1,000", 10, 100, smallText, WHITE);
        DrawText("F: Fullscreen", 10, 130, smallText, WHITE);
        DrawText(TextFormat("Screen: %d x %d", screenWidth, screenHeight), 10, 160, smallText, WHITE);

        if (!paused) {
            DrawText("Status: Running", 10, 40, smallText, WHITE);
        } else {
           DrawText("Status: Paused", 10, 40, smallText, WHITE); 
        }

        EndDrawing();

        
    }

    CloseWindow();
    return 0;
}