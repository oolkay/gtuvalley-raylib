#include "fence.hpp"

fence::fence()
{

}

fence::fence(const string &name, const Vector2 &position, const Rectangle &hitbox)
{
    _name = name;
    _position = position;
    _hitbox = hitbox;
}
