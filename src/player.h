#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

typedef struct {
  Vector2 position;
} Player;

Player init_player(float x, float y);
void update_player(Player *p, float dt);

#endif
