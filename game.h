//
// Created by ahmad on 3/23/23.
//

#ifndef OCM_DESKTOP_GAME_H
#define OCM_DESKTOP_GAME_H

#include <SDL2/SDL.h>

class Game
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface* lettuce_sur;
    SDL_Texture* lettuce_tex;
public:
    Game();
    void Initialize();
    void run();
    void Destroy();

    ~Game();
};

#endif //OCM_DESKTOP_GAME_H
