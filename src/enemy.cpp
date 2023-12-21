#include "enemy.hpp"

Enemy::Enemy() : mesh()
{
    _health = 100;
    _damage = 10;
    _speed = 1;
    _range = 1;
    _attackSpeed = 1;
    _attackRange = 1;
}

Enemy::Enemy(const string &name, const Vector2 &position,
               const Rectangle &hitbox) : mesh(name, position, hitbox)
{
    _health = 100;
    _damage = 10;
    _speed = 1;
    _range = 1;
    _attackSpeed = 1;
    _attackRange = 1;
    setCurrentTexture("stand");
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

bool Enemy::isMovable(char key, vector<vector<mesh *>> &map)
{
    Vector2 lefttop = {getPosition().x + getHitbox().x, getPosition().y + getHitbox().y};
    Vector2 righttop = {getPosition().x + getHitbox().x + getHitbox().width, getPosition().y + getHitbox().y};
    Vector2 leftbottom = {getPosition().x + getHitbox().x, getPosition().y + getHitbox().y + getHitbox().height};
    Vector2 rightbottom = {getPosition().x + getHitbox().x + getHitbox().width, getPosition().y + getHitbox().y + getHitbox().height};


    mesh *leftCorner;
    mesh *rightCorner;
    mesh *upCorner;
    mesh *downCorner;

    switch (key)
    {
    case 'u':
        leftCorner = map[(int)(lefttop.y - _speed)/ 32][(int)lefttop.x / 32];
        rightCorner = map[(int)(righttop.y - _speed) / 32][(int)(righttop.x) / 32];
        if (leftCorner->getName() == "Default" && rightCorner->getName() == "Default")
            return true;
        else if (leftCorner->getName() == "enemy" && leftCorner->getPositionX() == getPositionX()
                                && leftCorner->getPositionY() == getPositionY())
            return true;
        else if (rightCorner->getName() == "enemy" && rightCorner->getPositionX() == getPositionX()
                                && rightCorner->getPositionY() == getPositionY())
            return true;
        break;
    case 'l':
        upCorner = map[(int)lefttop.y / 32][(int)(lefttop.x - _speed) / 32];
        downCorner = map[(int)leftbottom.y / 32][(int)(leftbottom.x - _speed) / 32];
        if (upCorner->getName() == "Default" && downCorner->getName() == "Default")
            return true;
        else if (upCorner->getName() == "enemy" && upCorner->getPositionX() == getPositionX()
                                && upCorner->getPositionY() == getPositionY())
            return true;
        else if  (downCorner->getName() == "enemy" && downCorner->getPositionX() == getPositionX()
                                && downCorner->getPositionY() == getPositionY())
            return true;
        break;
    case 'r':
        upCorner = map[(int)righttop.y / 32][(int)(righttop.x + _speed) / 32];
        downCorner = map[(int)rightbottom.y / 32][(int)(rightbottom.x + _speed) / 32];
        if (upCorner->getName() == "Default" && downCorner->getName() == "Default")
            return true;
        else if (upCorner->getName() == "enemy" && upCorner->getPositionX() == getPositionX()
                                && upCorner->getPositionY() == getPositionY())
            return true;
        else if (downCorner->getName() == "enemy" && downCorner->getPositionX() == getPositionX()
                                && downCorner->getPositionY() == getPositionY())
            return true;
        break;
    case 'd':
        leftCorner = map[(int)(leftbottom.y + _speed) / 32][(int)leftbottom.x / 32];
        rightCorner = map[(int)(rightbottom.y + _speed) / 32][(int)(rightbottom.x) / 32];
        if (leftCorner->getName() == "Default" && rightCorner->getName() == "Default")
            return true;
        else if (leftCorner->getName() == "enemy" && leftCorner->getPositionX() == getPositionX()
                                && leftCorner->getPositionY() == getPositionY())
            return true;
        else if (rightCorner->getName() == "enemy" && rightCorner->getPositionX() == getPositionX()
                                && rightCorner->getPositionY() == getPositionY())
            return true;
        break;
    default:
        break;
    }
    return false;
}

void Enemy::move(const player &pl, vector<vector<mesh *>> &map)
{
    if (pl.getPosition().x > _position.x)
    {
        if (isMovable('r', map)){
            //exit(31);
            _position.x += _speed;
        }
    }
    else if (pl.getPosition().x < _position.x)
    {
        if (isMovable('l', map)){
            //exit(33);
            _position.x -= _speed;
        }
    }
    if (pl.getPosition().y > _position.y)
    {
        if (isMovable('d', map)){
            //exit(32);
            _position.y += _speed;
        }
    }
    else if (pl.getPosition().y < _position.y)
    {
        if (isMovable('u', map)){
            //exit(35);
            _position.y -= _speed;
        }
    }
    DrawRectangle((int)((_position.x + 16) / 32) * 32, (int)((_position.y + 16) / 32)*32, 32, 32, Fade(LIGHTGRAY, 0.5f));
    // DrawRectangleLines((int)(_position.x / 32) * 32 + 32, (int)(_position.y / 32)*32, 32, 32, BLACK);
    // DrawRectangleLines((int)(_position.x / 32) * 32, (int)(_position.y / 32)*32 + 32, 32, 32, BLACK);
    // DrawRectangleLines((int)(_position.x / 32) * 32 + 32, (int)(_position.y / 32)*32 + 32, 32, 32, BLACK);

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
