//
// Created by ahmad on 3/30/23.
//

#ifndef OCM_DESKTOP_ATTACKED_BOARD_H
#define OCM_DESKTOP_ATTACKED_BOARD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "piece.h"

class AttackedBoard {
    Piece piece;

    SDL_Texture *textTexture;
    SDL_Rect textDstRect;

    int whitePawnCounter = 1;
    int whiteKnightCounter = 4;
    int whiteBishopCounter = 3;
    int whiteRockCounter = 2;
    int whiteQueenCounter = 5;
    int blackPawnCounter = 1;
    int blackKnightCounter = 2;
    int blackBishopCounter = 3;
    int blackRockCounter = 5;
    int blackQueenCounter = 1;

    SDL_Texture *whitePawnTextTexture;
    SDL_Texture *whiteKnightTextTexture;
    SDL_Texture *whiteBishopTextTexture;
    SDL_Texture *whiteRockTextTexture;
    SDL_Texture *whiteQueenTextTexture;
    SDL_Texture *blackPawnTextTexture;
    SDL_Texture *blackKnightTextTexture;
    SDL_Texture *blackBishopTextTexture;
    SDL_Texture *blackRockTextTexture;
    SDL_Texture *blackQueenTextTexture;

    SDL_Rect whitePawnTextDstRect;
    SDL_Rect whiteKnightTextDstRect;
    SDL_Rect whiteBishopTextDstRect;
    SDL_Rect whiteRockTextDstRect;
    SDL_Rect whiteQueenTextDstRect;
    SDL_Rect blackPawnTextDstRect;
    SDL_Rect blackKnightTextDstRect;
    SDL_Rect blackBishopTextDstRect;
    SDL_Rect blackRockTextDstRect;
    SDL_Rect blackQueenTextDstRect;

public:
    void Initialize(SDL_Renderer *renderer, TTF_Font *font);

    void Render(SDL_Renderer *renderer);

    void Destroy();
};


#endif //OCM_DESKTOP_ATTACKED_BOARD_H
