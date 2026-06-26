#include <cstdio>

#include "raylib.h"

#include "aniengine/aniengine.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "AniEngine Demo");

    // A 3D camera looking at the origin.
    Camera3D camera = {0};
    camera.position = (Vector3){6.0f, 6.0f, 6.0f};  // where the camera sits
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};    // what it looks at
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};        // which way is "up"
    camera.fovy = 45.0f;                            // field of view (degrees)
    camera.projection = CAMERA_PERSPECTIVE;

    const Vector3 cubePosition = {0.0f, 0.0f, 0.0f};

    SetTargetFPS(60);

    // Render loop: runs until the window is closed (ESC or close button).
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        DrawGrid(10, 1.0f);  // ground reference grid
        EndMode3D();

        DrawText(TextFormat("AniEngine version: %s", aniengine::version()), 10, 10, 20, DARKGRAY);
        DrawFPS(screenWidth - 90, 10);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
