#include "mesh.hpp"

mesh::mesh(): _name("Default"), _position(), _textures(), _hitbox(){}

mesh::mesh(const string& name, const Vector2& position, const Rectangle& hitbox)
{
    _name = name;
    _position = position;
    _hitbox = hitbox;
}

void mesh::addTexture(string name, Vector2 frameMatrix, Texture2D texture, int height, int width)
{
    _textures[name] = myTexture(name, frameMatrix, texture);
    _textures[name].setTextureHeight(texture.height);
    _textures[name].setTextureWidth(texture.width);
}

void mesh::removeTexture(const string& name)
{
    _textures.erase(name);
}

void mesh::setPosition(const Vector2 &position)
{
    _position = position;
}

void mesh::setPositionX(const float &x)
{
    _position.x = x;
}

void mesh::setPositionY(const float &y)
{
    _position.y = y;
}

void mesh::setName(const string &name)
{
    _name = name;
}

void mesh::setHitbox(const Rectangle &hitbox)
{
    _hitbox = hitbox;
}

void mesh::drawRec(const string &key)
{
    DrawTextureRec(_textures[key].getTexture(), _textures[key].getFrame(), _position, WHITE);
}
