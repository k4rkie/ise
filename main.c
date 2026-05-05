#include <raylib.h>

#define WIN_WIDTH 1200
#define WIN_HEIGHT 1000

#define RAYBLACK (Color){8, 8, 8, 255}
#define TILE_SIZE 32
#define MAP_COLS 30
#define MAP_ROWS 20
#define MAP_WIDTH (MAP_COLS * TILE_SIZE)
#define MAP_HEIGHT (MAP_ROWS * TILE_SIZE)

typedef struct
{
  int type;
} Tile;
Tile map[MAP_ROWS][MAP_COLS];

typedef struct
{
  Vector2 position;
} Player;

int main()
{
  InitWindow(WIN_WIDTH, WIN_HEIGHT, "Isometic Map Editor");
  SetTargetFPS(60);
  float speed = 300.0f;

  // Initialize map
  for (int i = 0; i < MAP_ROWS; i++)
  {
    for (int j = 0; j < MAP_COLS; j++)
    {
      map[i][j] = (Tile){.type = 0};
    }
  }

  map[2][3].type = 1;
  map[5][7].type = 1;
  map[1][9].type = 1;
  map[12][5].type = 1;

  // Initialize player
  Player bob = {
      .position = (Vector2){
          .x = (float)(MAP_WIDTH / 2),
          .y = (float)(MAP_HEIGHT / 2)}};

  while (!WindowShouldClose())
  {
    float dt = GetFrameTime();
    BeginDrawing();

    ClearBackground(RAYBLACK);

    int offset_x = (WIN_WIDTH - MAP_WIDTH) / 2;
    int offset_y = (WIN_HEIGHT - MAP_HEIGHT) / 2;

    for (int row = 0; row < MAP_ROWS; row++)
    {
      for (int col = 0; col < MAP_COLS; col++)
      {
        if (map[row][col].type == 0)
        {
          DrawRectangleLines(col * TILE_SIZE + offset_x, row * TILE_SIZE + offset_y, TILE_SIZE, TILE_SIZE, RAYWHITE);
        }
        else
        {
          DrawRectangle(col * TILE_SIZE + offset_x, row * TILE_SIZE + offset_y, TILE_SIZE, TILE_SIZE, GREEN);
        }
      }
    }

    if (IsKeyDown(KEY_W))
    {
      if (bob.position.y - 10.0f >= 0.0f + offset_y)
      {
        bob.position.y -= speed * dt;
      }
    }
    if (IsKeyDown(KEY_S))
    {
      if (bob.position.y + 10.0f <= MAP_HEIGHT + offset_y)
      {
        bob.position.y += speed * dt;
      }
    }
    if (IsKeyDown(KEY_D))
    {
      if (bob.position.x + 10.0f <= MAP_WIDTH + offset_x)
      {
        bob.position.x += speed * dt;
      }
    }
    if (IsKeyDown(KEY_A))
    {
      if (bob.position.x - 10.0f >= 0.0f + offset_x)
      {
        bob.position.x -= speed * dt;
      }
    }

    DrawCircle((int)(bob.position.x), (int)(bob.position.y), 10.0f, RED);

    DrawText(TextFormat("x: %.1f  y: %.1f", bob.position.x, bob.position.y), 10, 10, 20, RED);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
