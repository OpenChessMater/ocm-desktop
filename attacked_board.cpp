//
// Created by ahmad on 3/30/23.
//

#include "attacked_board.h"

#include "colors.h"

void AttackedBoard::Initialize(SDL_Renderer *renderer, TTF_Font *font) {
//    this->piece.Initialize(renderer);
    SDL_Surface *surface = TTF_RenderText_Solid(font, "1x", color1);

    textTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(textTexture, NULL, NULL, &texW, &texH);
    textDstRect = {890, 10, texW, texH};
}

void AttackedBoard::Render(SDL_Renderer *renderer) {
    SDL_Rect r;
    r.x = 860;
    r.y = 0;
    r.w = 200;
    r.h = 400;

    SDL_SetRenderDrawColor(renderer, color2.r, color2.g, color2.b, color2.a);

    SDL_RenderFillRect(renderer, &r);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_RenderCopy(renderer, textTexture, NULL, &textDstRect);
}

void AttackedBoard::Destroy() {

}
