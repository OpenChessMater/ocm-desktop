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

    int whitePawnCounter = -1;
    int whiteKnightCounter = -1;
    int whiteBishopCounter = -1;
    int whiteRockCounter = -1;
    int whiteQueenCounter = -1;
    int blackPawnCounter = -1;
    int blackKnightCounter = -1;
    int blackBishopCounter = -1;
    int blackRockCounter = -1;
    int blackQueenCounter = -1;

    SDL_Texture *whitePawnTextTexture{};
    SDL_Texture *whiteKnightTextTexture{};
    SDL_Texture *whiteBishopTextTexture{};
    SDL_Texture *whiteRockTextTexture{};
    SDL_Texture *whiteQueenTextTexture{};
    SDL_Texture *blackPawnTextTexture{};
    SDL_Texture *blackKnightTextTexture{};
    SDL_Texture *blackBishopTextTexture{};
    SDL_Texture *blackRockTextTexture{};
    SDL_Texture *blackQueenTextTexture{};

    SDL_Rect whitePawnTextDstRect{};
    SDL_Rect whiteKnightTextDstRect{};
    SDL_Rect whiteBishopTextDstRect{};
    SDL_Rect whiteRockTextDstRect{};
    SDL_Rect whiteQueenTextDstRect{};
    SDL_Rect blackPawnTextDstRect{};
    SDL_Rect blackKnightTextDstRect{};
    SDL_Rect blackBishopTextDstRect{};
    SDL_Rect blackRockTextDstRect{};
    SDL_Rect blackQueenTextDstRect{};

    TTF_Font *_font{};
    SDL_Renderer *_renderer{};

    int hasht{};
    int masht{};

    void checkChange();

    void drawPawnTextTexture(bool _white);
    void drawKnightTextTexture(bool _white);
    void drawBishopTextTexture(bool _white);
    void drawRockTextTexture(bool _white);
    void drawQueenTextTexture(bool _white);

public:
    void Initialize(SDL_Renderer *renderer, TTF_Font *font);

    void Render(SDL_Renderer *renderer);

    void Destroy();
};


#endif //OCM_DESKTOP_ATTACKED_BOARD_H
