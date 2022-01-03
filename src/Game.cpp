/*
 * Game 
 * Defines the information for the core gameplay loop
 */

#include <SDL2/SDL.h>
#include "GameWindow.h"
#include "Game.h"

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game()
{
}

void Game::gameLoop()
{
    GameWindow gameWindow;
    SDL_Event eventHandler;

    while (true)
    {
        if (SDL_PollEvent(&eventHandler))
        {
            switch (eventHandler.type)
            {
            case SDL_QUIT:
                return;
            }
        }
    }
}

void Game::draw(GameWindow &gameWindow)
{
}

void Game::gameTick(float elapsedTime)
{
}