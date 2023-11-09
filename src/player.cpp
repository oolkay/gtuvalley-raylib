#include "player.hpp"

player::player(): mesh(), _health(0), _attack(0), _speed(0), _level(0){}

player::player(const string &name, const Vector2 &position, const Rectangle &hitbox, int &health, const int &attack, const int &speed, const int &level): mesh(name, position, hitbox), _health(health), _attack(attack), _speed(speed), _level(level)
{
}


void player::setHealth(const int &health)
{
    _health = health;
}

void player::setAttack(const int &attack)
{
    _attack = attack;
}

void player::setSpeed(const int &speed)
{
    _speed = speed;
}

void player::setLevel(const int &level)
{
    _level = level;
}

void player::move()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        if (CheckCollisionRecs(_hitbox, (Rectangle){ 480, 360, 40, 40 }) == 0)
            _position.x += _speed;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        // if (CheckCollisionRecs(_hitbox, (Rectangle){ 480, 360, 40, 40 }) == 0)
            _position.x -= _speed;
    }
    else if (IsKeyDown(KEY_UP))
    {
        if (CheckCollisionRecs(_hitbox, (Rectangle){ 480, 360, 40, 40 }) == 0)
            _position.y -= _speed;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        // if (CheckCollisionRecs(_hitbox, (Rectangle){ 480, 360, 40, 40 }) == 0)
            _position.y += _speed;
    }
    _hitbox.x = _position.x;
    _hitbox.y = _position.y;
}
