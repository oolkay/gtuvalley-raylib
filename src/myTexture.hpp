#ifndef MYTEXTURE_HPP
#define MYTEXTURE_HPP

#include <string>
#include "raylib-cpp.hpp"

using namespace std;

class myTexture{
    private:
        static size_t _currentFrame;
        string _name;
        Vector2 _frameMatrix;
        Texture2D _texture;
        Rectangle _frame;
    public:
        myTexture();
        myTexture(const string& name, const Vector2& frameMatrix, const Texture2D& texture);
        void setName(const string& name);
        void setFrameMatrix(const Vector2& frameMatrix);
        void setTexture(const Texture2D& texture);
        void setTextureHeight(const int& height);
        void setTextureWidth(const int& width);
        void updateRect();
        size_t getCurrentFrame();
        string getName() const {return _name;}
        Vector2 getFrameMatrix() const {return _frameMatrix;}
        Texture2D getTexture() const {return _texture;}
        Rectangle getRect() const {return _frame;}
};

#endif