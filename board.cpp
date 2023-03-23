//
// Created by ahmad on 3/24/23.
//

#include "board.h"

void Board::Initialize(SDL_Renderer *renderer)
{

    rect.x = 10;
    rect.y = 10;
    rect.w = 100;
    rect.h = 160;

    rect2.x = 10 + rect.x +rect.w;
    rect2.y = 10 + rect.y + rect.h;
    rect2.w = 150;
    rect2.h = 160;

}

void Board::Render(SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, 250, 0, 100, 0);
    SDL_RenderFillRect(renderer, &rect);


    SDL_SetRenderDrawColor(renderer, 0, 250, 100, 0);
    SDL_RenderFillRect(renderer, &rect2);


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

}

void Board::Destroy() {

}
