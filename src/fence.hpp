#ifndef FENCE_HPP
#define FENCE_HPP

#include "mesh.hpp"

class fence : public mesh
{
    public:
        fence();
        fence(const string& name, const Vector2& position, const Rectangle& hitbox);
};


#endif