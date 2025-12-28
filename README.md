# MinecraftClone (OpenGL)

A Minecraft-style voxel renderer written in **C++** using **modern OpenGL**, **GLFW**, and **GLEW**.  
The project focuses on low-level graphics programming, batching, camera systems, and procedural terrain generation.

This project uses **CMake** as its build system and **does not require any specific IDE**.

---

## Features

- OpenGL 3.2 Core Profile (macOS compatible)
- Batched cube rendering for performance
- Texture atlas–based block rendering
- First-person camera movement and rotation
- Procedural terrain generation using Simplex noise
- Custom rendering abstractions (VAO, VBO, shaders)

---

## Requirements

### macOS

- **CMake** ≥ 3.15  
- **Xcode Command Line Tools**
- **Homebrew**
- **GLFW**
- **GLEW**
- OpenGL (system-provided on macOS)

Install dependencies with Homebrew:

```bash
brew install glfw glew
```
## Build and Run

This project uses **CMake** and can be built entirely from the command line.

### Build

From the project root directory:

```bash
cmake -S . -B build
cmake --build build
```
## Run

The executable must be run from the `build/` directory so that relative paths to
shaders and textures resolve correctly.

After building the project:

```bash
cd build
./MinecraftClone
```
## Controls

### Camera Movement (Keyboard)

| Key | Action |
|----|----|
| **W** | Move forward |
| **S** | Move backward |
| **A** | Move left |
| **D** | Move right |

Movement is handled by the `CameraMovement` system and provides first-person navigation through the world.

---

### Camera Rotation (Mouse)

- **Mouse movement** controls camera rotation (yaw & pitch)
- Cursor is captured by the window for FPS-style look control

Rotation is handled by the `CameraRotation` and `MouseInput` systems.

---

### Terrain / Noise Controls (Keyboard)

| Key | Action |
|----|----|
| **↑ Arrow** | Increase noise offset (Y) |
| **↓ Arrow** | Decrease noise offset (Y) |
| **→ Arrow** | Increase noise offset (X) |
| **← Arrow** | Decrease noise offset (X) |
| **Q** | Decrease noise scale |
| **E** | Increase noise scale |

These controls modify the **Simplex noise parameters** used for procedural terrain generation in real time.

---

