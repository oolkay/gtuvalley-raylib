#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "mesh.hpp"



class player : public mesh
{
    private:
        int _health;
        int _attack;
        int _speed;
        int _level;
        map<string, bool> _keys;
    public:
        player();
        player(const string& name, const Vector2& position, const Rectangle& hitbox, int& health, const int& attack, const int& speed, const int& level);
        void setHealth(const int& health);
        void setAttack(const int& attack);
        void setSpeed(const int& speed);
        void setLevel(const int& level);
        int getHealth() const {return _health;}
        int getAttack() const {return _attack;}
        int getSpeed() const {return _speed;}
        int getLevel() const {return _level;}
        bool getKey(const string &key) const {return _keys.at(key);}
        void checkKeys();
        void move();
        /*
        TODO:
                TAKE DAMAGE
                ATTACK
                DIE
                ...
        */
};

#endif