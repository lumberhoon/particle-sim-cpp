# Particle Sim C++

A C++ particle simulation project I’m building to learn C++ structure, real-time rendering, physics simulation, and eventually CPU/GPU performance testing.

This started as a terminal-based particle sim and is now a Raylib visual prototype.

## Current Version

**v0.2 - Raylib Visualization**

## Features

- C++17
- Raylib rendering
- `std::vector` particle storage
- Random particle spawning
- Wall bouncing
- Add, remove, clear, and pause controls
- FPS and particle count HUD
- Borderless fullscreen toggle
- Display logic split into `display.cpp` / `display.h`
- Terminal prototype preserved in `terminal/`
- CMake build setup

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

### macOS Dependencies

```bash
brew install raylib pkg-config cmake
```

### Build with CMake

From the project root:

```bash
cmake -S . -B build
cmake --build build
```

Run:

```bash
./build/particle_sim
```

### Manual Compile Option

If I want to compile directly without CMake:

```bash
clang++ src/main.cpp src/particle.cpp src/random.cpp src/display.cpp -Iinclude -std=c++17 $(pkg-config --libs --cflags raylib) -o particle_sim
```

Run:

```bash
./particle_sim
```

## Project Structure

```text
include/     Header files
src/         Main Raylib simulation code
terminal/    Original terminal prototype
build/       Generated CMake build folder, not committed
```

## Project Goal

The goal is to build this from a simple particle sim into a more realistic and performance-focused physics simulation project.

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
