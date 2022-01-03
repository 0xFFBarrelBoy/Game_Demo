#if !defined GAMEWINDOW_H
#define GAMEWINDOW_H

/* Forward Declaration */
struct SDL_Window;
struct SDL_Renderer;

class GameWindow
{
public:
    GameWindow();
    ~GameWindow();

private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;
};

#endif