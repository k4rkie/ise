#include "render.h"
#include "game.h"
#include "raylib.h"
#include "tile.h"

void render_map(Texture2D *textures) {
  for (int row = 0; row < MAP_ROWS; row++) {
    for (int col = 0; col < MAP_COLS; col++) {
      float cx = (col - row) * TILE_WIDTH / 2 + offset_x;
      float cy = (col + row) * TILE_HEIGHT / 2 + offset_y;

      Vector2 top = {.x = cx, .y = cy - (float)(TILE_HEIGHT / 2)};
      Vector2 bottom = {.x = cx, .y = cy + (float)(TILE_HEIGHT / 2)};
      Vector2 right = {.x = cx + (float)(TILE_WIDTH / 2), .y = cy};
      Vector2 left = {.x = cx - (float)(TILE_WIDTH / 2), .y = cy};

      DrawTriangleLines(top, right, left, RAYWHITE);
      DrawTriangleLines(bottom, left, right, RAYWHITE);
      // float draw_x = cx - TILE_WIDTH / 2;
      // float draw_y = cy - TILE_HEIGHT / 2;
      //
      // DrawTexture(textures[Map[row][col].type], (int)draw_x, (int)draw_y,
      //             RAYWHITE);
    }
  }
}

void render_player(Player p) {
  DrawCircle((int)(p.position.x), (int)(p.position.y), 10.0f, RED);
}
