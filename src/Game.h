#if !defined GAME_H
#define GAME_H

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
};

#endif