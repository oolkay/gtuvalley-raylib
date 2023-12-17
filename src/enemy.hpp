#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "mesh.hpp"
#include "player.hpp"

class Enemy : public mesh
{
    public:
        Enemy();
        Enemy(const Enemy& other);
        Enemy& operator=(const Enemy& other);
        ~Enemy();
        void setHealth(unsigned int health);
        void setDamage(unsigned int damage);
        void setSpeed(unsigned int speed);
        void setRange(unsigned int range);
        void setAttackSpeed(unsigned int attackSpeed);
        void setAttackRange(unsigned int attackRange);
        unsigned int getHealth() const { return _health; };
        unsigned int getDamage() const { return _damage; };
        unsigned int getSpeed() const { return _speed; };
        unsigned int getRange() const { return _range; };
        unsigned int getAttackSpeed() const { return _attackSpeed; };
        unsigned int getAttackRange() const { return _attackRange; };
        void move(const player& pl, char map[25][25]);
        bool isMovable(char key, const char map[25][25]);
        void attack();
        void die();
        void takeDamage(unsigned int damage);

    private:
        unsigned int _health;
        unsigned int _damage;
        unsigned int _speed;
        unsigned int _range;
        unsigned int _attackSpeed;
        unsigned int _attackRange;

};

#endif