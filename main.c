#include <raylib.h>

#define TILE_WIDTH 64
#define TILE_HEIGHT 32

#define WIN_WIDTH 1200
#define WIN_HEIGHT 800

#define MAP_COLS 30
#define MAP_ROWS 30
#define MAP_WIDTH ((MAP_COLS + MAP_ROWS) * TILE_WIDTH / 2)
#define MAP_HEIGHT ((MAP_COLS + MAP_ROWS) * TILE_HEIGHT / 2)

typedef struct
{
  int type;
} Tile;

Tile Map[MAP_ROWS][MAP_COLS];

typedef struct
{
  Vector2 position;
} Player;

int main(void)
{
  InitWindow(WIN_WIDTH, WIN_HEIGHT, "GRID TEST");

  SetTargetFPS(60);

  float speed = 100.0f;

  // Initialize map
  for (int row = 0; row < MAP_ROWS; row++)
  {
    for (int col = 0; col < MAP_COLS; col++)
    {
      Map[row][col] = (Tile){.type = 0};
    }
  }

  int offset_x = (WIN_WIDTH / 2);
  int offset_y = (WIN_HEIGHT / 2) - (MAP_HEIGHT / 2);

  // Initialize player
  Player bob = {
      .position = (Vector2){
          .x = (float)(WIN_WIDTH / 2),
          .y = (float)(WIN_HEIGHT / 2)}};

  Camera2D cam = {0};
  cam.offset = (Vector2){WIN_WIDTH / 2, WIN_HEIGHT / 2};
  cam.target = bob.position;
  cam.zoom = 1.0f;

  while (!WindowShouldClose())
  {
    float dt = GetFrameTime();

    if (IsKeyDown(KEY_W))
    {
      bob.position.y -= speed * dt;
    }
    if (IsKeyDown(KEY_S))
    {
      bob.position.y += speed * dt;
    }
    if (IsKeyDown(KEY_D))
    {
      bob.position.x += speed * dt;
    }
    if (IsKeyDown(KEY_A))
    {
      bob.position.x -= speed * dt;
    }

    cam.target = bob.position;

    BeginDrawing();
    BeginMode2D(cam);
    ClearBackground((Color){8, 8, 8, 255});

    // Loop over map to draw tiles
    for (int row = 0; row < MAP_ROWS; row++)
    {
      for (int col = 0; col < MAP_COLS; col++)
      {
        float cx = (col - row) * TILE_WIDTH / 2 + offset_x;
        float cy = (col + row) * TILE_HEIGHT / 2 + offset_y;

        Vector2 top =
            {.x = cx, .y = cy - (float)(TILE_HEIGHT / 2)};
        Vector2 bottom =
            {.x = cx, .y = cy + (float)(TILE_HEIGHT / 2)};
        Vector2 right =
            {.x = cx + (float)(TILE_WIDTH / 2), .y = cy};
        Vector2 left =
            {.x = cx - (float)(TILE_WIDTH / 2), .y = cy};

        DrawTriangleLines(top, right, left, RAYWHITE);
        DrawTriangleLines(bottom, left, right, RAYWHITE);
      }
    }

    DrawCircle((int)(bob.position.x), (int)(bob.position.y), 10.0f, RED);
    EndMode2D();
    DrawText(TextFormat("x: %.1f  y: %.1f", bob.position.x, bob.position.y), 10, 10, 20, RED);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}