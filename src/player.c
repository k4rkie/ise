#include "player.h"
#include "game.h"

Player init_player(float x, float y)
{
    Player p;
    p.position = (Vector2){x, y};
    return p;
}

void update_player(Player *p, float dt)
{
    float speed = 200.0f;

    if (IsKeyDown(KEY_W)) p->position.y -= speed * dt;
    if (IsKeyDown(KEY_S)) p->position.y += speed * dt;
    if (IsKeyDown(KEY_D)) p->position.x += speed * dt;
    if (IsKeyDown(KEY_A)) p->position.x -= speed * dt;
}
