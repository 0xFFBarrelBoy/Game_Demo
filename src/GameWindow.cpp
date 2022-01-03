/* Game Window 
 * Handles the game window and renderer  
 */

#include <SDL2/SDL.h>
#include "GameWindow.h"

GameWindow::GameWindow()
{
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "0xFFBarrelBoy");
}

GameWindow::~GameWindow()
{
    SDL_DestroyWindow(this->_window);
}
