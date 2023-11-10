#include "player.hpp"

player::player(): mesh(), _health(0), _attack(0), _speed(0), _level(0){}

player::player(const string &name, const Vector2 &position, const Rectangle &hitbox, int &health, const int &attack, const int &speed, const int &level): mesh(name, position, hitbox), _health(health), _attack(attack), _speed(speed), _level(level)
{
    _keys["w"] = false;
    _keys["a"] = false;
    _keys["s"] = false;
    _keys["d"] = false;
    _keys["space"] = false;
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

void player::checkKeys()
{
    setCurrentTexture("stand");
    if (IsKeyDown(KEY_UP)){
        _keys["upArrow"] = true;
        setCurrentTexture("walkU");
    }
    else{
        _keys["upArrow"] = false;
    }
    if (IsKeyDown(KEY_LEFT)){
        _keys["leftArrow"] = true;
        setCurrentTexture("walkL");
    }
    else{
        _keys["leftArrow"] = false;
    }
    if (IsKeyDown(KEY_DOWN)){
        _keys["downArrow"] = true;
        setCurrentTexture("walkD");
    }
    else{
        _keys["downArrow"] = false;
    }
    if (IsKeyDown(KEY_RIGHT)){
        _keys["rightArrow"] = true;
        setCurrentTexture("walkR");
    }
    else{
        _keys["rightArrow"] = false;
    }
    if (IsKeyDown(KEY_SPACE)){
        _keys["space"] = true;
    }
    else{
        _keys["space"] = false;    
    }
}

void player::move()
{
    checkKeys();
    if (_keys["upArrow"])
        _position.y -= _speed;
    if (_keys["leftArrow"])
        _position.x -= _speed;
    if (_keys["downArrow"])
        _position.y += _speed;
    if (_keys["rightArrow"])
        _position.x += _speed;
    if (_keys["space"])
        _speed *= 2;
    _hitbox.x = _position.x;
    _hitbox.y = _position.y;
}
