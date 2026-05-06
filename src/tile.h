#ifndef TILE_H
#define TILE_H

#include "game.h"

typedef enum { TILE_GRASS = 0, TILE_STONE } Tile_type;

typedef struct {
  Tile_type type;
} Tile;

extern Tile Map[MAP_ROWS][MAP_COLS];
extern int offset_x;
extern int offset_y;

void init_map(void);

#endif
