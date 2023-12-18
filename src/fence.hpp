#ifndef FENCE_HPP
#define FENCE_HPP

#include "mesh.hpp"

class fence : public mesh
{
    public:
        fence();
        ~fence();
        fence(const string& name, const Vector2& position, const Rectangle& hitbox);
        //virtual void            drawRec(const string& key) override;
};


#endif
