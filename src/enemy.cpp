#include "enemy.hpp"

Enemy::Enemy()
{
    _health = 100;
    _damage = 10;
    _speed = 1;
    _range = 1;
    _attackSpeed = 1;
    _attackRange = 1;
}

Enemy::Enemy(const Enemy& other)
{
    _health = other._health;
    _damage = other._damage;
    _speed = other._speed;
    _range = other._range;
    _attackSpeed = other._attackSpeed;
    _attackRange = other._attackRange;
}

Enemy& Enemy::operator=(const Enemy& other)
{
    _health = other._health;
    _damage = other._damage;
    _speed = other._speed;
    _range = other._range;
    _attackSpeed = other._attackSpeed;
    _attackRange = other._attackRange;
    return *this;
}

Enemy::~Enemy()
{
}

void Enemy::setHealth(unsigned int health)
{
    this->_health = health;
}

void Enemy::setDamage(unsigned int damage)
{
    this->_damage = damage;
}

void Enemy::setSpeed(unsigned int speed)
{
    this->_speed = speed;
}

void Enemy::setRange(unsigned int range)
{
    this->_range = range;
}

void Enemy::setAttackSpeed(unsigned int attackSpeed)
{
    this->_attackSpeed = attackSpeed;
}

void Enemy::setAttackRange(unsigned int attackRange)
{
    this->_attackRange = attackRange;
}

bool Enemy::isMovable(char key, const char map[25][25])
{
    Vector2 lefttop = {getPosition().x + getHitbox().x, getPosition().y + getHitbox().y};
    Vector2 righttop = {getPosition().x + getHitbox().x + getHitbox().width, getPosition().y + getHitbox().y};
    Vector2 leftbottom = {getPosition().x + getHitbox().x, getPosition().y + getHitbox().y + getHitbox().height};
    Vector2 rightbottom = {getPosition().x + getHitbox().x + getHitbox().width, getPosition().y + getHitbox().y + getHitbox().height};

    switch (key)
    {
    case 'u':
        if (map[(int)(lefttop.y - _speed)  / 32][(int)lefttop.x / 32] == '0' && map[(int)(righttop.y - _speed) / 32][(int)(righttop.x) / 32] == '0')
            return true;
        break;
    case 'l':
        if (map[(int)lefttop.y / 32][(int)(lefttop.x - _speed) / 32] == '0' && map[(int)leftbottom.y / 32][(int)(leftbottom.x - _speed) / 32] == '0')
            return true;
        break;
    case 'd':
        if (map[(int)(leftbottom.y + _speed) / 32][(int)leftbottom.x / 32] == '0' && map[(int)(rightbottom.y + _speed) / 32][(int)(rightbottom.x) / 32] == '0')
            return true;
        break;
    case 'r':
        if (map[(int)righttop.y / 32][(int)(righttop.x + _speed) / 32] == '0' && map[(int)rightbottom.y / 32][(int)(rightbottom.x + _speed) / 32] == '0')
            return true;
        break;
    default:
        break;
    }
    return false;
}

void Enemy::move(const player& pl, char map[25][25])
{
    if (pl.getPosition().x > _position.x)
    {
        if (isMovable('r', map))
            _position.x += _speed;
    }
    else if (pl.getPosition().x < _position.x)
    {
        if (isMovable('l', map))
            _position.x -= _speed;
    }
    if (pl.getPosition().y > _position.y)
    {
        if (isMovable('d', map))
            _position.y += _speed;
    }
    else if (pl.getPosition().y < _position.y)
    {
        if (isMovable('u', map))
            _position.y -= _speed;
    }
}

void Enemy::attack()
{

}

void Enemy::die()
{
}

void Enemy::takeDamage(unsigned int damage)
{

}
