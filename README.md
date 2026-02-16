# Viewer3D for Windows


An OpenGL-powered 3D image viewer featuring asynchronous asset loading and dynamic GPU texture promotion. This project serves as an exploration of real-time graphics rendering and multi-threaded resource management in C++.

![image alt](https://github.com/beki-github/viewer3D/blob/9928f0deab6e3f34a49a7b8e2b54897ebbe17e5f/Screenshot%202026-02-16%20062328.png)
![image alt](https://github.com/beki-github/viewer3D/blob/9928f0deab6e3f34a49a7b8e2b54897ebbe17e5f/Screenshot%202026-02-16%20062503.png)


## 🚀 Overview


Viewer3D provides an immersive environment for navigating image libraries in a 3D space. By implementing a Producer-Consumer multithreading model, the system separates heavy disk I/O from the rendering pipeline, allowing the user to move freely while high-resolution textures are loaded and "promoted" to the GPU in the background.

## 🛠️ Tech Stack
* **Language: C++ (Modern Standards)**

* **Graphics API: OpenGL 4.3 (Core Profile)**

* **Build System: CMake**

* **Image Logic: stb_image for driver-level texture decoding**

* **Shading: GLSL (Custom Vertex and Fragment shaders)**

* **Mathematics: GLM (OpenGL Mathematics)**

## 🧩 Core Architecture
* **Asynchronous Loader: A dedicated background thread that handles directory iteration and stbi loading to prevent main-thread "hitching."**

* **GPU Promotion Queue: A thread-safe std::queue using std::mutex to manage the transfer of image data from CPU RAM to GPU VRAM.**

* **Dynamic Scaling: Integrated aspect ratio math within the Model matrix to ensure images maintain original proportions regardless of resolution.**

* **FPS Camera: A 6-DOF Euler-angle camera system for intuitive navigation using WASD and mouse-look.**

## ⚙️ Initial Setup
* **1. Prerequisite Configuration**
Ensure your local machine is configured with the necessary GCC compilers and graphics headers by following the steps in readGLsetup.md.

* **2. Clone the Repository**
Bash
git clone https://github.com/beki-github/viewer3D/tree/main
cd viewer3D
* **3. Build via VS Code**
* **Select Kit: Press Ctrl + Shift + P and run CMake: Select a Kit. Select your GCC compiler.**
* **Select Variant: Press Ctrl + Shift + P and run CMake: Select Variant. Choose Release.**
* **Reconfigure: Press Ctrl + Shift + P and run CMake: Delete Cache and Reconfigure.**
* **Compile: Press F7 or click Build in the status bar to generate the executable.**
