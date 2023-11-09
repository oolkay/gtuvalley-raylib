#include "myTexture.hpp"

myTexture::myTexture(): _name("Default"), _frameMatrix(), _texture(){}

myTexture::myTexture(const string &name, const Vector2 &frameMatrix, const Texture2D &texture): _name(name), _frameMatrix(frameMatrix), _texture(texture)
{
    _frame.width = _texture.width / _frameMatrix.x;
    _frame.height = _texture.height / _frameMatrix.y;
}

void myTexture::setName(const string &name)
{
    _name = name;
}

void myTexture::setFrameMatrix(const Vector2 &frameMatrix)
{
    _frameMatrix = frameMatrix;
}

void myTexture::setTexture(const Texture2D &texture)
{
    _texture = texture;
}

void myTexture::setTextureHeight(const int &height)
{
    _texture.height = height;
}

void myTexture::setTextureWidth(const int &width)
{
    _texture.width = width;
}
