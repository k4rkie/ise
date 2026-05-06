#include "game.h"
#include "player.h"
#include "raylib.h"
#include "render.h"
#include "tile.h"

int main(void) {
  InitWindow(WIN_WIDTH, WIN_HEIGHT, "GRID TEST");
  SetTargetFPS(60);

  // Initialize Map
  init_map();

  // Initialize Player
  Player bob = init_player((float)(WIN_WIDTH / 2), (float)(WIN_HEIGHT / 2));

  Camera2D cam = {0};
  cam.offset = (Vector2){WIN_WIDTH / 2, WIN_HEIGHT / 2};
  cam.target = bob.position;
  cam.zoom = 1.0f;

  Texture2D textures[2];
  textures[TILE_GRASS] = LoadTexture("assets/grass.png");
  textures[TILE_STONE] = LoadTexture("assets/stone.png");

  Vector2 mouse_position;

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    // Update
    update_player(&bob, dt);
    cam.target = bob.position;

    // Draw
    BeginDrawing();
    BeginMode2D(cam);
    ClearBackground((Color){8, 8, 8, 255});

    render_map(textures);
    render_player(bob);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      mouse_position = GetWorldToScreen2D(GetMousePosition(), cam);
    }

    EndMode2D();

    DrawText(TextFormat("Mouse pressed at x: %.1f  y: %.1f", mouse_position.x,
                        mouse_position.y),
             200, 200, 20, RED);
    DrawText(TextFormat("x: %.1f  y: %.1f", bob.position.x, bob.position.y), 10,
             10, 20, RED);
    EndDrawing();
  }

  UnloadTexture(textures[TILE_GRASS]);
  UnloadTexture(textures[TILE_STONE]);
  CloseWindow();
  return 0;
}
