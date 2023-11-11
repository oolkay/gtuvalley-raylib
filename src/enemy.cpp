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

void Enemy::move(const player& pl)
{
    if (pl.getPosition().x > _position.x + _speed*20)
        _position.x += _speed;
    else if (pl.getPosition().x < _position.x - _speed*20)
        _position.x -= _speed;
    if (pl.getPosition().y > _position.y + _speed*20)
        _position.y += _speed;
    else if (pl.getPosition().y < _position.y - _speed*20)
        _position.y -= _speed;
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
