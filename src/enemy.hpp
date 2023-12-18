#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "mesh.hpp"
#include "player.hpp"

class Enemy : public mesh
{
    public:
        Enemy();
        Enemy(const string &name, const Vector2 &position, const Rectangle &hitbox);
        Enemy(const Enemy &other);
        Enemy& operator=(const Enemy& other);
        virtual ~Enemy();
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
        void move(const player &pl, vector<vector<mesh *>> &map);
        bool isMovable(char key, vector<vector<mesh *>> &map);
        void attack();
        void die();
        void takeDamage(unsigned int damage);
        bool    operator==(const Enemy &rhs) const {
            return (rhs.getPositionX() == getPositionX() && rhs.getPositionY() == getPositionY());
        }
    private:
        unsigned int _health;
        unsigned int _damage;
        unsigned int _speed;
        unsigned int _range;
        unsigned int _attackSpeed;
        unsigned int _attackRange;

};

#endif
