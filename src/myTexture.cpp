#include "myTexture.hpp"

size_t myTexture::_currentFrame = 0;

myTexture::myTexture(): _name("Default"), _frameMatrix(), _texture(){}

myTexture::myTexture(const string &name, const Vector2 &frameMatrix, const Texture2D &texture): _name(name), _frameMatrix(frameMatrix), _texture(texture)
{
    _frame.width = _texture.width / _frameMatrix.x;
    _frame.height = _texture.height / _frameMatrix.y;
    _frame.x = 0;
    _frame.y = 0;
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

void myTexture::updateRect()
{
    if (_frame.x + _frame.width >= _texture.width)
        _frame.x = 0;
    else
        _frame.x += _frame.width;
    if (_frame.y + _frame.height >= _texture.height)
        _frame.y = 0;
    else
        _frame.y += _frame.height;
}

size_t myTexture::getCurrentFrame()
{
    _currentFrame==60?_currentFrame=0:_currentFrame++;
    return _currentFrame;
}