#include <raylib.h>


Vector2 Vector2Scale(Vector2 v, float scale) {
    return { v.x * scale, v.y * scale };
}
Vector2 Vector2Add(const Vector2& a, const Vector2& b) {
    return { a.x + b.x, a.y + b.y };
}

int main() {
    // Initialize window and OpenGL context
    InitWindow(800, 800, "Voi jumalauta");

    // Set up a frame rate limit
    SetTargetFPS(60);
    Vector2 jokuA = {(float)GetScreenWidth()/2, 0.0f};
    Vector2 jokuB = {0.0f, (float)GetScreenHeight()/2};
    Vector2 jokuC = {(float)GetScreenWidth(), (float)GetScreenHeight()/0.75f};

    Vector2 speedA = {1, 1};
    Vector2 speedB = {1, -1};
    Vector2 speedC = {-1, 1};

    float nopeus = 400.0f;

    // Main game loop
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();
        // Begin drawing
        BeginDrawing();

        ClearBackground(BLACK);
        DrawLineV(jokuA, jokuB, GREEN);
        DrawLineV(jokuB, jokuC, YELLOW);
        DrawLineV(jokuC, jokuA, BLUE);

        jokuA = Vector2Add(jokuA, Vector2Scale(speedA, nopeus * deltaTime));
        jokuB = Vector2Add(jokuB, Vector2Scale(speedB, nopeus * deltaTime));
        jokuC = Vector2Add(jokuC, Vector2Scale(speedC, nopeus * deltaTime));

        if (jokuA.x < 0 || jokuA.x > screenWidth)  speedA.x *= -1.0f;
        if (jokuA.y < 0 || jokuA.y > screenHeight) speedA.y *= -1.0f;

        // Kimpoamiset B:lle
        if (jokuB.x < 0 || jokuB.x > screenWidth)  speedB.x *= -1.0f;
        if (jokuB.y < 0 || jokuB.y > screenHeight) speedB.y *= -1.0f;

        // Kimpoamiset C:lle
        if (jokuC.x < 0 || jokuC.x > screenWidth)  speedC.x *= -1.0f;
        if (jokuC.y < 0 || jokuC.y > screenHeight) speedC.y *= -1.0f;


        // End drawing
        EndDrawing();
    }

    // De-initialize the window and OpenGL context
    CloseWindow();

    return 0;
}

