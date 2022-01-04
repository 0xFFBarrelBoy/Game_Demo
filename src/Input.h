#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <map>

using std::map;

class Input
{
public:
    void refreshFrame(void);

    void keyPressEvent(const SDL_Event &keyEvent);
    void keyReleaseEvent(const SDL_Event &keyEvent);

    bool isKeyPressed(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);
    bool isKeyReleased(SDL_Scancode key);

    void execute_key(SDL_Scancode key);

private:
    map<SDL_Scancode, bool> _keyPressed;
    map<SDL_Scancode, bool> _keyHeld;
    map<SDL_Scancode, bool> _keyReleased;
};
#endif