//
// Created by ahmad on 3/30/23.
//

#include "attacked_board.h"

void AttackedBoard::Initialize(SDL_Renderer *renderer) {
    this->piece.Initialize(renderer);
}

void AttackedBoard::Render(SDL_Renderer *renderer) {
    SDL_Rect r;
    r.x = 860;
    r.y = 0;
    r.w = 200;
    r.h = 400;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255,0);

    SDL_RenderFillRect(renderer, &r);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0,0);
}

void AttackedBoard::Destroy() {

}
