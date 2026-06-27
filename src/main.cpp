#include <cmath>
#include <cstdio>

#include "raylib.h"

#include "animengine/animengine.h"
#include "animengine/curve.h"

struct AnimatedCube {
    Vector3 position;
    Color color;
    animengine::Curve curve;
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "AnimEngine Demo - Easing Functions");

    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 8.0f, 20.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    const float period = 4.0f;
    const float cubeSize = 1.5f;
    const float spacing = 3.5f;

    AnimatedCube cubes[6];
    const char* labels[6] = {"StepStart", "StepEnd", "Linear", "EaseIn", "EaseOut", "EaseInOut"};
    Color colors[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};

    for (int i = 0; i < 6; i++) {
        cubes[i].position = {(i - 2.5f) * spacing, 0.0f, 0.0f};
        cubes[i].color = colors[i];
        cubes[i].curve.addKeyframe(0.0f, -1.0f, static_cast<animengine::Easing>(i));
        cubes[i].curve.addKeyframe(2.0f, 1.0f, static_cast<animengine::Easing>(i));
        cubes[i].curve.addKeyframe(4.0f, -1.0f);
    }

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        const float t = std::fmod(static_cast<float>(GetTime()), period);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        for (int i = 0; i < 6; i++) {
            float y = cubes[i].curve.evaluate(t);
            Vector3 pos = {cubes[i].position.x, y, cubes[i].position.z};
            DrawCube(pos, cubeSize, cubeSize, cubeSize, cubes[i].color);
            DrawCubeWires(pos, cubeSize, cubeSize, cubeSize, DARKGRAY);
        }
        DrawGrid(10, 1.0f);
        EndMode3D();

        DrawText(TextFormat("Time: %.2f", t), 10, 10, 20, DARKGRAY);
        for (int i = 0; i < 6; i++) {
            DrawText(labels[i], 10, 35 + i * 20, 16, cubes[i].color);
        }

        DrawFPS(screenWidth - 90, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
