//
// Created by ahmad on 3/24/23.
//

#include "piece.h"
#include <SDL2/SDL_image.h>
#include <iostream>

void Piece::Initialize(SDL_Renderer *renderer) {
    this->whitePawnTexture = initializeTexture(renderer, this->whitePawnImagePath);
    this->blackPawnTexture = initializeTexture(renderer, this->blackPawnImagePath);

    this->whiteKnightTexture = initializeTexture(renderer, this->whiteKnightImagePath);
    this->blackKnightTexture = initializeTexture(renderer, this->blackKnightImagePath);

    this->whiteBishopTexture = initializeTexture(renderer, this->whiteBishopImagePath);
    this->blackBishopTexture = initializeTexture(renderer, this->blackBishopImagePath);

    this->whiteRockTexture = initializeTexture(renderer, this->whiteRockImagePath);
    this->blackRockTexture = initializeTexture(renderer, this->blackRockImagePath);

    this->whiteQueenTexture = initializeTexture(renderer, this->whiteQueenImagePath);
    this->blackQueenTexture = initializeTexture(renderer, this->blackQueenImagePath);

    this->whiteKingTexture = initializeTexture(renderer, this->whiteKingImagePath);
    this->blackKingTexture = initializeTexture(renderer, this->blackKingImagePath);
}

SDL_Texture *Piece::initializeTexture(SDL_Renderer *renderer, const char *path) {
    SDL_Surface *sur;
    SDL_Texture *tex;

    sur = IMG_Load(path);
    if (sur == NULL) {
        std::cout << "Error loading image: " << IMG_GetError();
        exit(5);
    }

    tex = SDL_CreateTextureFromSurface(renderer, sur);
    if (tex == NULL) {
        std::cout << "Error creating texture";
        exit(6);
    }

    SDL_FreeSurface(sur);

    return tex;
}

void Piece::RenderPawn(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whitePawnRect.x = x + (this->board_tile - whitePawnRect.w) / 2;
        this->whitePawnRect.y = y + (this->board_tile - whitePawnRect.h) / 2;
        SDL_RenderCopy(renderer, this->whitePawnTexture, NULL, &this->whitePawnRect);
    } else {
        this->blackPawnRect.x = x + (this->board_tile - blackPawnRect.w) / 2;
        this->blackPawnRect.y = y + (this->board_tile - blackPawnRect.h) / 2;
        SDL_RenderCopy(renderer, this->blackPawnTexture, NULL, &this->blackPawnRect);
    }
}

void Piece::RenderKnight(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whiteKnightRect.x = x + (this->board_tile - whiteKnightRect.w) / 2;
        this->whiteKnightRect.y = y + (this->board_tile - whiteKnightRect.h) / 2;
        SDL_RenderCopy(renderer, this->whiteKnightTexture, NULL, &this->whiteKnightRect);
    } else {
        this->blackKnightRect.x = x + (this->board_tile - blackKnightRect.w) / 2;
        this->blackKnightRect.y = y + (this->board_tile - blackKnightRect.h) / 2;
        SDL_RenderCopy(renderer, this->blackKnightTexture, NULL, &this->blackKnightRect);
    }
}

void Piece::RenderBishop(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whiteBishopRect.x = x + (this->board_tile - whiteBishopRect.w) / 2;
        this->whiteBishopRect.y = y + (this->board_tile - whiteBishopRect.h) / 2;
        SDL_RenderCopy(renderer, this->whiteBishopTexture, NULL, &this->whiteBishopRect);
    } else {
        this->blackBishopRect.x = x + (this->board_tile - blackBishopRect.w) / 2;
        this->blackBishopRect.y = y + (this->board_tile - blackBishopRect.h) / 2;
        SDL_RenderCopy(renderer, this->blackBishopTexture, NULL, &this->blackBishopRect);
    }
}

void Piece::RenderRock(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whiteRockRect.x = x + (this->board_tile - whiteRockRect.w) / 2;
        this->whiteRockRect.y = y + (this->board_tile - whiteRockRect.h) / 2;
        SDL_RenderCopy(renderer, this->whiteRockTexture, NULL, &this->whiteRockRect);
    } else {
        this->blackRockRect.x = x + (this->board_tile - blackRockRect.w) / 2;
        this->blackRockRect.y = y + (this->board_tile - blackRockRect.h) / 2;
        SDL_RenderCopy(renderer, this->blackRockTexture, NULL, &this->blackRockRect);
    }
}

void Piece::RenderQueen(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whiteQueenRect.x = x + (this->board_tile - whiteQueenRect.w) / 2;
        this->whiteQueenRect.y = y + (this->board_tile - whiteQueenRect.h) / 2;
        SDL_RenderCopy(renderer, this->whiteQueenTexture, NULL, &this->whiteQueenRect);
    } else {
        this->blackQueenRect.x = x + (this->board_tile - blackQueenRect.w) / 2;
        this->blackQueenRect.y = y + (this->board_tile - blackQueenRect.h) / 2;
        SDL_RenderCopy(renderer, this->blackQueenTexture, NULL, &this->blackQueenRect);
    }
}

void Piece::RenderKing(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whiteKingRect.x = x + (this->board_tile - whiteKingRect.w) / 2;
        this->whiteKingRect.y = y + (this->board_tile - whiteKingRect.h) / 2;
        SDL_RenderCopy(renderer, this->whiteKingTexture, NULL, &this->whiteKingRect);
    } else {
        this->blackKingRect.x = x + (this->board_tile - blackKingRect.w) / 2;
        this->blackKingRect.y = y + (this->board_tile - blackKingRect.h) / 2;
        SDL_RenderCopy(renderer, this->blackKingTexture, NULL, &this->blackKingRect);
    }
}

void Piece::Destroy() {
    SDL_DestroyTexture(this->whitePawnTexture);
    SDL_DestroyTexture(this->whiteKnightTexture);
    SDL_DestroyTexture(this->whiteBishopTexture);
    SDL_DestroyTexture(this->whiteRockTexture);
    SDL_DestroyTexture(this->whiteQueenTexture);
    SDL_DestroyTexture(this->whiteKingTexture);

    SDL_DestroyTexture(this->blackPawnTexture);
    SDL_DestroyTexture(this->blackKnightTexture);
    SDL_DestroyTexture(this->blackBishopTexture);
    SDL_DestroyTexture(this->blackRockTexture);
    SDL_DestroyTexture(this->blackQueenTexture);
    SDL_DestroyTexture(this->blackKingTexture);
}
