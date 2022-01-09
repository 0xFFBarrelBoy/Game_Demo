#if !defined GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

/* Forward Declaration */
struct SDL_Window;
struct SDL_Renderer;

class GameWindow
{
public:
   GameWindow(void);
   ~GameWindow(void);

   /**
     * @brief Loads a sprite, if the sprite is not already in memory loads it
     * @param path Filepath of the sprite
     * 
     * @return image from the sprite sheet map
     * 
     */

   SDL_Surface *loadImage(const std::string &path);

   /**
 * @brief Draws texture to a defined segment of the screen
 * 
 * @param src 
 * @param srcRectange 
 * @param destRect 
 */

   void blitSurfacer(SDL_Texture *srcTexture, SDL_Rect *srcRectange, SDL_Rect *destRect);

   /**
 * @brief Renders the textures to the game window
 * 
 */
   void flip();

   /**
 * @brief Clears all rendered textures from the game window
 * 
 */
   void clearGameWindow();

   /**
     * @brief 
     * @return Handle to the Game Window's renderer object
     */
   SDL_Renderer *getRenderer() const;

private:
   SDL_Window *_window;
   SDL_Renderer *_renderer;

   std::map<std::string, SDL_Surface *> _spriteSheets;
};

#endif