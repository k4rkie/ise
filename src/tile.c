#include "tile.h"

Tile Map[MAP_ROWS][MAP_COLS];

int offset_x = (WIN_WIDTH / 2);
int offset_y = (WIN_HEIGHT / 2) - (MAP_HEIGHT / 2);

void init_map(void) {
  for (int row = 0; row < MAP_ROWS; row++) {
    for (int col = 0; col < MAP_COLS; col++) {
      Map[row][col] = (Tile){.type = TILE_GRASS};
    }
  }

  // island
  for (int row = 5; row < 10; row++) {
    for (int col = 5; col < 10; col++) {
      Map[row][col].type = TILE_STONE;
    }
  }
}
