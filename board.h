//
// Created by ahmad on 3/24/23.
//

#ifndef OCM_DESKTOP_BOARD_H
#define OCM_DESKTOP_BOARD_H

#include <SDL2/SDL.h>

class Board {

    SDL_Rect destrect;

    SDL_Rect rect;
    SDL_Rect rect2;
public:
//    Board();

    void Initialize(SDL_Renderer *renderer);
    void Render(SDL_Renderer *renderer);
    void Destroy();

//    ~Board();
};


#endif //OCM_DESKTOP_BOARD_H
