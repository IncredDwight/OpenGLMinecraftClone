# MinecraftClone (OpenGL)

A Minecraft-style voxel renderer written in **C++** using **modern OpenGL**, **GLFW**, and **GLEW**.  
The project focuses on low-level graphics programming, batching, camera systems, and procedural terrain generation.

This project uses **CMake** as its build system and **does not require Xcode or any specific IDE**.

---

## Features

- OpenGL 3.2 Core Profile (macOS compatible)
- Batched cube rendering for performance
- Texture atlas–based block rendering
- First-person camera movement and rotation
- Procedural terrain generation using Simplex noise
- Custom rendering abstractions (VAO, VBO, shaders)
- Clean, portable CMake-based build

---

## Screenshots / Demo

> (Optional: add screenshots or a GIF here once you have one)

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
