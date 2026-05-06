#ifndef RENDER_H
#define RENDER_H

#include "game.h"
#include "player.h"
#include "raylib.h"
#include "tile.h"

void render_map(Texture2D *textures);
void render_player(Player p);

#endif
