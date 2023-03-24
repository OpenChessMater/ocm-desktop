//
// Created by ahmad on 3/24/23.
//

#ifndef OCM_DESKTOP_BOARD_H
#define OCM_DESKTOP_BOARD_H

#include <SDL2/SDL.h>
#include "piece.h"

class Board {

    SDL_Rect rect;

    // For color pallet refer to: https://colorswall.com/palette/generate/o/43946
    SDL_Color blackCellFillColor{87, 57, 46, 0};        // Hex: #573a2e
    SDL_Color whiteCellFillColor{138, 120, 93, 0};      // Hex: #8a785d
    SDL_Color cellBorderColor{252, 204, 116, 0};        // Hex: #fccc74
    SDL_Color cellHoverBorderColor{23, 23, 140, 0};     // Hex: #17178c

    Piece piece;
public:
    void Initialize(SDL_Renderer *renderer);

    void Render(SDL_Renderer *renderer);

    void Destroy();
};


#endif //OCM_DESKTOP_BOARD_H
