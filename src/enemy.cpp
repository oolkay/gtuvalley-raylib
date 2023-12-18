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

    mesh *uptop = map[(int)(lefttop.y - _speed) / 32][(int)lefttop.x / 32];
    mesh *upbottom = map[(int)(leftbottom.y - _speed) / 32][(int)leftbottom.x / 32];
    mesh *lefttopm = map[(int)lefttop.y / 32][(int)(lefttop.x - _speed) / 32];
    mesh *leftbottomm = map[(int)leftbottom.y / 32][(int)(leftbottom.x - _speed) / 32];
    mesh *righttopm = map[(int)righttop.y / 32][(int)(righttop.x + _speed) / 32];
    mesh *rightbottomm = map[(int)rightbottom.y / 32][(int)(rightbottom.x + _speed) / 32];
    mesh *downbottom = map[(int)(leftbottom.y + _speed) / 32][(int)leftbottom.x / 32];
    mesh *downtop = map[(int)(rightbottom.y + _speed) / 32][(int)(rightbottom.x) / 32];
    switch (key)
    {
    case 'u':
        if (uptop->getName() == "Default" && upbottom->getName() == "Default")
            return true;
        else if (uptop->getName() == "enemy" && uptop->getPositionX() == getPositionX()
                                && uptop->getPositionY() == getPositionY())
            return true;
        else if (upbottom->getName() == "enemy" && upbottom->getPositionX() == getPositionX()
                                && upbottom->getPositionY() == getPositionY())
            return true;
        break;
    case 'l':
        if (lefttopm->getName() == "Default" && leftbottomm->getName() == "Default")
            return true;
        else if (lefttopm->getName() == "enemy" && lefttopm->getPositionX() == getPositionX()
                                && lefttopm->getPositionY() == getPositionY())
            return true;
        else if (leftbottomm->getName() == "enemy" && leftbottomm->getPositionX() == getPositionX()
                                && leftbottomm->getPositionY() == getPositionY())
            return true;
        break;
    case 'r':
        if (righttopm->getName() == "Default" && rightbottomm->getName() == "Default")
            return true;
        else if (righttopm->getName() == "enemy" && righttopm->getPositionX() == getPositionX()
                                && righttopm->getPositionY() == getPositionY())
            return true;
        else if (rightbottomm->getName() == "enemy" && rightbottomm->getPositionX() == getPositionX()
                                && rightbottomm->getPositionY() == getPositionY())
            return true;
        break;
    case 'd':
        if (downbottom->getName() == "Default" && downtop->getName() == "Default")
            return true;
        else if (downbottom->getName() == "enemy" && downbottom->getPositionX() == getPositionX()
                                && downbottom->getPositionY() == getPositionY())
            return true;
        else if (downtop->getName() == "enemy" && downtop->getPositionX() == getPositionX()
                                && downtop->getPositionY() == getPositionY())
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
