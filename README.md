# Particle Sim C++

A C++ particle simulation project built to practice C++ structure, real-time rendering, physics simulation, and eventually CPU/GPU performance testing.

This started as a terminal-based particle simulation and is now a Raylib visual prototype.

## Current Version

**v0.2 - Raylib Visualization**

## Current Features

- C++17
- Raylib rendering
- `std::vector` particle storage
- Random particle spawning
- Wall bouncing
- Add, remove, clear, pause controls
- FPS and particle count HUD
- Borderless fullscreen toggle
- Display logic split into `display.cpp` / `display.h`
- Original terminal version preserved

## Controls

| Key | Action |
|---|---|
| `A` | Add 10 particles |
| `Shift + A` | Add 1,000 particles |
| `E` | Remove 10 particles |
| `Shift + E` | Remove 1,000 particles |
| `C` | Clear all particles |
| `Space` | Pause / resume |
| `F` | Toggle borderless fullscreen |

## Build

### macOS

Install Raylib:

```bash
brew install raylib pkg-config
```

Compile:

```bash
clang++ main.cpp particle.cpp random.cpp display.cpp -std=c++17 $(pkg-config --libs --cflags raylib) -o particle_sim
```

Run:

```bash
./particle_sim
```

## Project Goal

The goal is to build from a basic particle sim into a more realistic and performance-focused physics simulation project.

Future versions will focus on better physics, CPU benchmarking, memory layout comparisons, and eventually GPU acceleration.

## Roadmap

### v0.3 - Better Particle Physics

- Gravity
- Drag / friction
- Bounce damping
- Mouse interaction
- Physics settings
- Substeps

### Later

- CPU benchmark mode
- AoS vs SoA comparison
- Cloth simulation
- Spatial grid optimization
- Water-like particle simulation
- CUDA version
- ROCm/HIP exploration

## Notes

On macOS, borderless fullscreen may not cover the screen perfectly because of menu bar or safe-area behavior. Fullscreen is not the main focus of this project right now.
