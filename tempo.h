//
// Created by ahmad on 3/24/23.
//

#ifndef OCM_DESKTOP_TEMPO_H
#define OCM_DESKTOP_TEMPO_H


#include <SDL2/SDL.h>

class Tempo {
private:
    SDL_Surface* sur;
    SDL_Texture* tex;

    SDL_Rect destrect;
public:
    Tempo();

    void Initialize(SDL_Renderer *renderer, int x, int y);
    void Render(SDL_Renderer *renderer);
    void Destroy();

    ~Tempo();
};


#endif //OCM_DESKTOP_TEMPO_H
