#include "Sprite.h"
#include "GlobalDefs.h"

Sprite::Sprite()
{
}

Sprite::Sprite(GameWindow &gameWindow, const std::string &filePath, int srcX, int srcY, int spriteHeight,
               int spriteWidth, float posX, float posY) : _x(posX),
                                                          _y(posY)
{
    this->_srcRect.x = srcX;
    this->_srcRect.y = srcY;
    this->_srcRect.w = spriteWidth;
    this->_srcRect.h = spriteHeight;

    this->_spriteSheet = SDL_CreateTextureFromSurface(gameWindow.getRenderer(), gameWindow.loadImage(filePath));
    if (this->_spriteSheet == NULL)
    {
        printf("\n Unable to load image");
    }
};

Sprite::~Sprite(){};

void Sprite::draw(GameWindow &gameWindow, int x, int y)
{
    SDL_Rect destRect = {x, y, this->_srcRect.w * globalDefs::SPRITE_SCALE, this->_srcRect.h * globalDefs::SPRITE_SCALE};
    gameWindow.blitSurfacer(this->_spriteSheet, &this->_srcRect, &destRect);
}

void Sprite::update() {}