# AnimEngineDemo

AnimEngineDemo is built on top of [MiaoAnimEngine](https://github.com/WangSimiao2000/MiaoAnimEngine)

## Features

- Camera (3D perspective)
- Cube rendering
- Animation preview with easing functions (StepStart, StepEnd, Linear, EaseIn, EaseOut, EaseInOut)

## Building

### Requirements

- CMake 3.16 or higher
- C++17 compiler
- Dependencies are included as git submodules under `external/`

### Windows (MSVC)

```cmd
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

The executable will be generated at `build\Release\demo.exe`

### Linux / macOS (GCC/Clang)

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)  # Linux
# or
cmake --build .  # Generic
```

The executable will be generated at `build/demo`

### IDE Build

If using CLion, Visual Studio, or other CMake-compatible IDEs:

1. Open the project root directory
2. The IDE will automatically detect CMakeLists.txt
3. Select build configuration (Debug/Release)
4. Click the build button

### Notes

- The project automatically compiles `external/raylib` and `external/AnimEngine` dependencies
- raylib examples and games are disabled (`BUILD_EXAMPLES OFF`) to speed up compilation
- If git submodules are not initialized, run:
  ```bash
  git submodule update --init --recursive
  ```
