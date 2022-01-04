/* Input
 * Handles Input states and events
 */

#include "Input.h"

void Input::refreshFrame(void)
{
    // Clear states of non-held keys
    this->_keyReleased.clear();
    this->_keyPressed.clear();
};

void Input::keyPressEvent(const SDL_Event &keyEvent)
{
    this->_keyPressed[keyEvent.key.keysym.scancode] = true;
    this->_keyHeld[keyEvent.key.keysym.scancode] = true;
};
void Input::keyReleaseEvent(const SDL_Event &keyEvent)
{
    this->_keyReleased[keyEvent.key.keysym.scancode] = true;
    this->_keyHeld[keyEvent.key.keysym.scancode] = false;
};

bool Input::isKeyPressed(SDL_Scancode key)
{
    return this->_keyPressed[key];
};

bool Input::isKeyHeld(SDL_Scancode key)
{
    return this->_keyHeld[key];
};

bool Input::isKeyReleased(SDL_Scancode key)
{
    return this->_keyReleased[key];
};

void Input::execute_key(SDL_Scancode key)
{
    switch (key)
    {
    case SDL_SCANCODE_ESCAPE:
        exit(0);
    }
};
