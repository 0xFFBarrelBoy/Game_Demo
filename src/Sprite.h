#if !defined SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include "GameWindow.h"
#include <string>


/**
 * @brief  Retains information for all sprites 
 * 
 * 
 */

class Sprite
{
public:
    Sprite();
    Sprite(GameWindow &gameWindow, const std::string &filePath, int srcX, int srcY, int spriteHeight,
           int spriteWidth, float posX, float posY);
    virtual ~Sprite();
    virtual void update();

    void draw(GameWindow &gameWindow, int x, int y);

private:
    SDL_Rect _srcRect;
    SDL_Texture *_spriteSheet;

    float _x, _y;
};

#endif