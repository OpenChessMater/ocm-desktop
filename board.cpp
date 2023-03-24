//
// Created by ahmad on 3/24/23.
//

#include "board.h"

void Board::Initialize(SDL_Renderer *renderer)
{

//    rect.x = 10;
//    rect.y = 10;
//    rect.w = 100;
//    rect.h = 160;
//
//    rect2.x = 10 + rect.x +rect.w;
//    rect2.y = 10 + rect.y + rect.h;
//    rect2.w = 150;
//    rect2.h = 160;

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
                SDL_SetRenderDrawColor(renderer, blackCellFillColor.r, blackCellFillColor.g, blackCellFillColor.b, blackCellFillColor.a);
            } else {
                SDL_SetRenderDrawColor(renderer, whiteCellFillColor.r, whiteCellFillColor.g, whiteCellFillColor.b, whiteCellFillColor.a);
            }

            SDL_RenderFillRect(renderer, &r);

            if (i == 6 && j == 6){
                SDL_SetRenderDrawColor(renderer, cellHoverBorderColor.r, cellHoverBorderColor.g, cellHoverBorderColor.b, cellHoverBorderColor.a);
            } else {
                SDL_SetRenderDrawColor(renderer, cellBorderColor.r, cellBorderColor.g, cellBorderColor.b, cellBorderColor.a);
            }

            SDL_RenderDrawRect(renderer, &r);
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Board::Destroy() {

}
