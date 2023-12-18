#include "player.hpp"
#include "game.hpp"

player::player(): mesh(),
        _health(0), _attack(0),
        _speed(0), _level(0)
{
    setSpeed(2);
    setPosition((Vector2){ 128, 128 });
    setHitbox((Rectangle){ 4, 4, 24, 24});
}

player::player(Game *pG) : mesh(),
        _health(0), _attack(0),
        _speed(0), _level(0)
{
    setSpeed(2);
    setPosition((Vector2){ 128, 128 });
    setHitbox((Rectangle){ 4, 4, 24, 24});
    game = pG;
}

// kullanmazsak sil
player::player(const string &name, const Vector2 &position,
        const Rectangle &hitbox, int &health,
        const int &attack, const int &speed, const int &level):
        mesh(name, position, hitbox), _health(health), _attack(attack), _speed(speed), _level(level)
{
    _keys["w"] = false;
    _keys["a"] = false;
    _keys["s"] = false;
    _keys["d"] = false;
    _keys["space"] = false;
    setSpeed(2);
    setPosition(position);
    setHitbox((Rectangle){ 4, 4, 24, 24});
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

void player::move(vector<vector<mesh *> > &map)
{
    checkKeys();
    if (_keys["upArrow"] && isMovable('u',map))
    {
        _position.y -= _speed;
    }
    if (_keys["leftArrow"] && isMovable('l',map))
    {
        _position.x -= _speed;
    }
    if (_keys["downArrow"] && isMovable('d',map))
    {
        _position.y += _speed;
    }
    if (_keys["rightArrow"] && isMovable('r',map))
    {
        _position.x += _speed;
    }
}

bool player::isMovable(char key, vector<vector<mesh *> > &map)
{
    Vector2 lefttop = {getPosition().x + getHitbox().x, getPosition().y + getHitbox().y};
    Vector2 righttop = {getPosition().x + getHitbox().x + getHitbox().width, getPosition().y + getHitbox().y};
    Vector2 leftbottom = {getPosition().x + getHitbox().x, getPosition().y + getHitbox().y + getHitbox().height};
    Vector2 rightbottom = {getPosition().x + getHitbox().x + getHitbox().width, getPosition().y + getHitbox().y + getHitbox().height};

    switch (key)
    {
    case 'u':
        if (map[(int)(lefttop.y - _speed)/ 32][(int)lefttop.x / 32]->getName() == "Default"
            && map[(int)(righttop.y - _speed) / 32][(int)(righttop.x) / 32]->getName() == "Default")
            return true;
        break;
    case 'l':
        if (map[(int)lefttop.y / 32][(int)(lefttop.x - _speed) / 32]->getName() == "Default"
            && map[(int)leftbottom.y / 32][(int)(leftbottom.x - _speed) / 32]->getName() == "Default")
            return true;
        break;
    case 'd':
        if (map[(int)(leftbottom.y + _speed) / 32][(int)leftbottom.x / 32]->getName() == "Default"
            && map[(int)(rightbottom.y + _speed) / 32][(int)(rightbottom.x) / 32]->getName() == "Default")
            return true;
        break;
    case 'r':
        if (map[(int)righttop.y / 32][(int)(righttop.x + _speed) / 32]->getName() == "Default"
        && map[(int)rightbottom.y / 32][(int)(rightbottom.x + _speed) / 32]->getName() == "Default")
            return true;
        break;
    default:
        break;
    }
    return false;
}
