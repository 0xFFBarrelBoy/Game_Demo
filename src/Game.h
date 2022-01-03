#if !defined GAME_H
#define GAME_H

class GameWindow;

class Game
{
public:
    Game();
    ~Game();

private:
    void gameLoop();
    void draw(GameWindow &gameWindow);
    void gameTick(float elapsedTime);
};

#endif