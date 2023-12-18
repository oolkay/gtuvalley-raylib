#include "fence.hpp"

fence::fence()
{
}

fence::~fence()
{
}

fence::fence(const string &name, const Vector2 &position, const Rectangle &hitbox)
{
    _name = name;
    _position = position;
    _hitbox = hitbox;
}

// void    fence::drawRec(const string &key) {
//     if (_textures[key].getCurrentFrame() % 10 == 0)
//         _textures[key].updateRect();
//     DrawTextureRec(_textures[key].getTexture(), _textures[key].getRect(), _position, WHITE);
// }
