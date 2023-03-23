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

    rect.x = 0;
    rect.y = 0;
    rect.w = 67;
    rect.h = 67;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            SDL_Rect r;
            r.x = i * rect.w + rect.x;
            r.y = j * rect.h + rect.y;
            r.w = rect.w;
            r.h = rect.h;

            if ( (i + j) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, color1.r, color1.g, color1.b, color1.a);
            } else {
                SDL_SetRenderDrawColor(renderer, color2.r, color2.g, color2.b, color2.a);
            }


            SDL_RenderFillRect(renderer, &r);
        }
    }

//
//    SDL_RenderFillRect(renderer, &rect);
//
//
//    rect.x = rect.x + rect.w;
//    rect.y = rect.y + rect.h;
//
//
//    rect.x = rect.x + rect.w;
//    rect.y = rect.y + rect.h;
//    SDL_SetRenderDrawColor(renderer, color1.r, color1.g, color1.b, color1.a);
//    SDL_RenderFillRect(renderer, &rect);


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Board::Destroy() {

}
