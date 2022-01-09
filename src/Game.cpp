/*
 * Game 
 * Defines the information for the core gameplay loop
 */

#include <SDL2/SDL.h>
#include "GameWindow.h"
#include "Game.h"
#include "Input.h"

namespace
{
    const int SET_FRAME_RATE = 60;
    const int MAX_FRAME_LIFETIME_MS = 1000 / SET_FRAME_RATE;
}

Game::Game(void)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game(void)
{
}

void Game::gameLoop(void)
{
    GameWindow gameWindow;
    Input input;
    SDL_Event eventHandler;

    this->_player = Sprite(gameWindow, "content/sprites/NpcMiza.png", 0, 0, 16, 16, 100, 100);

    int LAST_FRAME_UPDATE = SDL_GetTicks();

    while (true)
    {
        input.refreshFrame();

        if (SDL_PollEvent(&eventHandler))
        {
            switch (eventHandler.type)
            {
            case SDL_QUIT:
                return;

            case SDL_KEYDOWN:
                if (eventHandler.key.repeat == false)
                {
                    input.keyPressEvent(eventHandler);
                    input.execute_key(eventHandler.key.keysym.scancode);
                }
                return;

            case SDL_KEYUP:
                input.keyReleaseEvent(eventHandler);
                return;
            }
        }
        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_FRAME_UPDATE;
        this->gameTick(std::min(ELAPSED_TIME_MS, MAX_FRAME_LIFETIME_MS));
        LAST_FRAME_UPDATE = CURRENT_TIME_MS;

        this->draw(gameWindow);
    }
}

void Game::draw(GameWindow &gameWindow)
{
    gameWindow.clearGameWindow();

    this->_player.draw(gameWindow, 100, 100);
    gameWindow.flip();
}

void Game::gameTick(float elapsedTime)
{
}