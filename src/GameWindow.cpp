/* Game Window 
 * Handles the game window and renderer  
 */

#include "GameWindow.h"
#include "GlobalDefs.h"

GameWindow::GameWindow(void)
{
    SDL_CreateWindowAndRenderer(globalDefs::WINDOW_H, globalDefs::WINDOW_W, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "0xFFBarrelBoy");
}

GameWindow::~GameWindow(void)
{
    SDL_DestroyWindow(this->_window);
}

SDL_Surface *GameWindow::loadImage(const std::string &path)
{
    if (this->_spriteSheets.count(path) == 0)
    {
        this->_spriteSheets[path] = IMG_Load(path.c_str());
    }
    return this->_spriteSheets[path];
}

void GameWindow::blitSurfacer(SDL_Texture *srcTexture, SDL_Rect *srcRectange, SDL_Rect *destRect)
{
    SDL_RenderCopy(this->_renderer, srcTexture, srcRectange, destRect);
}

void GameWindow::flip()
{
    SDL_RenderPresent(this->_renderer);
}

void GameWindow::clearGameWindow()
{
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer *GameWindow::getRenderer() const
{
    return this->_renderer;
}
