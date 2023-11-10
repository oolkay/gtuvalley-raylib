#ifndef MESHHPP
#define MESHHPP

#include <string>
#include <map>
#include "myTexture.hpp"
#include "raylib-cpp.hpp"

using namespace std;


class mesh
{
    protected:
        string _name;
        Vector2 _position;
        Rectangle _hitbox;
        map<string, myTexture> _textures;
        string _currentTexture;
    public:
        mesh();
        mesh(const string& name, const Vector2& position, const Rectangle& hitbox);
        void addTexture(string name, Vector2 frameMatrix, Texture2D texture, int height, int width);//const vars?
        void removeTexture(const string& name);
        void setPosition(const Vector2& position);
        void setPositionX(const float& x);
        void setPositionY(const float& y);
        void setName(const string& name);
        void setHitbox(const Rectangle& hitbox);
        void setCurrentTexture(const string& name) {_currentTexture = name;}
        Rectangle getHitbox() const {return _hitbox;}
        Vector2 getPosition() const {return _position;}
        float getPositionX() const {return _position.x;}
        float getPositionY() const {return _position.y;}
        string getName() const {return _name;}
        string getCurrentTexture() const {return _currentTexture;}
        map<string, myTexture> getTextures() const {return _textures;}
        void drawRec(const string& key);
};

#endif
