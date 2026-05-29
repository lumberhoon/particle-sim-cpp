#include "raylib.h"
#include "motion.h"
#include "display.h"

    

void updateWalltoScreen(Wall& w) {
    w.lWall = 0.0f;
    w.rWall = static_cast<float>(GetScreenWidth());
    w.bWall = 0.0f;
    w.tWall = static_cast<float>(GetScreenHeight());
}

void toggleBorderlessFullscreen(bool& fullscreen, int windowWidth, int windowHeight) {
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

void drawParticles(const std::vector<Particle>& particles, float particleRadius) {
    for (const Particle& p : particles) {
        DrawCircle(p.posX, p.posY, particleRadius, YELLOW);
    }
}

DisplayScale calculateDisplayScale(int windowWidth) {
    DisplayScale d {};

    d.uiScale = static_cast<float>(GetScreenWidth()) / static_cast<float>(windowWidth);
    if (d.uiScale > 1.35f) {
        d.uiScale = 1.35f;
    }

    d.particleRadius = 3.0f * d.uiScale;
    d.smallText = static_cast<int>(10 * d.uiScale);
    d.normalText = static_cast<int>(20 * d.uiScale);

    return d;
}

void renderUi(const DisplayScale& d, const std::vector<Particle>& particles, int screenWidth, int screenHeight, bool paused) {

    DrawText(TextFormat("Particles: %zu", particles.size()), 10, 10, d.smallText, WHITE);
    const char* fpsText = TextFormat("FPS: %d", GetFPS());
    DrawText(fpsText, screenWidth - MeasureText(fpsText, d.normalText) - 10, 10, d.normalText, WHITE); 
    DrawText("A: Add 10 | E: Remove 10 | C: Clear | Space: Pause", 10, 70, d.smallText, WHITE);
    DrawText("SHIFT + A: Add 1,000 | SHIFT + E: Remove 1,000", 10, 100, d.smallText, WHITE);
    DrawText("F: Fullscreen", 10, 130, d.smallText, WHITE);
    DrawText(TextFormat("Screen: %d x %d", screenWidth, screenHeight), 10, 160, d.smallText, WHITE);

    if (!paused) {
        DrawText("Status: Running", 10, 40, d.smallText, WHITE);
    } else {
        DrawText("Status: Paused", 10, 40, d.smallText, WHITE); 
    }
}