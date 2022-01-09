#if !defined GAME_H
#define GAME_H

#include "Sprite.h"

class GameWindow;

class Game
{
public:
    Game(void);
    ~Game(void);

private:
    void gameLoop(void);
    void draw(GameWindow &gameWindow);
    void gameTick(float elapsedTime);

    Sprite _player;
};

#endif