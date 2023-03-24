//
// Created by ahmad on 3/24/23.
//

#ifndef OCM_DESKTOP_BISHOP_H
#define OCM_DESKTOP_BISHOP_H

#include <SDL2/SDL.h>

class Bishop {
private:
    SDL_Surface* sur;
    SDL_Texture* tex;

    SDL_Rect destrect;
public:
    void Initialize(SDL_Renderer *renderer, int x, int y, bool white);
    void Render(SDL_Renderer *renderer);
    void Destroy();
};


#endif //OCM_DESKTOP_BISHOP_H
