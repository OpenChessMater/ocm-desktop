//
// Created by ahmad on 3/30/23.
//

#ifndef OCM_DESKTOP_ATTACKED_BOARD_H
#define OCM_DESKTOP_ATTACKED_BOARD_H

#include <SDL2/SDL.h>
#include "piece.h"

class AttackedBoard {
    Piece piece;
public:
    void Initialize(SDL_Renderer *renderer);

    void Render(SDL_Renderer *renderer);

    void Destroy();
};


#endif //OCM_DESKTOP_ATTACKED_BOARD_H
