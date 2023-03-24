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
        this->whitePawnRect.x = x;
        this->whitePawnRect.y = y;
        SDL_RenderCopy(renderer, this->whitePawnTexture, NULL, &this->whitePawnRect);
    } else {
        this->blackPawnRect.x = x;
        this->blackPawnRect.y = y;
        SDL_RenderCopy(renderer, this->blackPawnTexture, NULL, &this->blackPawnRect);
    }
}

void Piece::RenderKnight(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whiteKnightRect.x = x;
        this->whiteKnightRect.y = y;
        SDL_RenderCopy(renderer, this->whiteKnightTexture, NULL, &this->whiteKnightRect);
    } else {
        this->blackKnightRect.x = x;
        this->blackKnightRect.y = y;
        SDL_RenderCopy(renderer, this->blackKnightTexture, NULL, &this->blackKnightRect);
    }
}

void Piece::RenderBishop(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whiteBishopRect.x = x;
        this->whiteBishopRect.y = y;
        SDL_RenderCopy(renderer, this->whiteBishopTexture, NULL, &this->whiteBishopRect);
    } else {
        this->blackBishopRect.x = x;
        this->blackBishopRect.y = y;
        SDL_RenderCopy(renderer, this->blackBishopTexture, NULL, &this->blackBishopRect);
    }
}

void Piece::RenderRock(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whiteRockRect.x = x;
        this->whiteRockRect.y = y;
        SDL_RenderCopy(renderer, this->whiteRockTexture, NULL, &this->whiteRockRect);
    } else {
        this->blackRockRect.x = x;
        this->blackRockRect.y = y;
        SDL_RenderCopy(renderer, this->blackRockTexture, NULL, &this->blackRockRect);
    }
}

void Piece::RenderQueen(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whiteQueenRect.x = x;
        this->whiteQueenRect.y = y;
        SDL_RenderCopy(renderer, this->whiteQueenTexture, NULL, &this->whiteQueenRect);
    } else {
        this->blackQueenRect.x = x;
        this->blackQueenRect.y = y;
        SDL_RenderCopy(renderer, this->blackQueenTexture, NULL, &this->blackQueenRect);
    }
}

void Piece::RenderKing(SDL_Renderer *renderer, int x, int y, bool white) {
    if (white) {
        this->whiteKingRect.x = x;
        this->whiteKingRect.y = y;
        SDL_RenderCopy(renderer, this->whiteKingTexture, NULL, &this->whiteKingRect);
    } else {
        this->blackKingRect.x = x;
        this->blackKingRect.y = y;
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
