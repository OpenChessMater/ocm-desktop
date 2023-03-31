//
// Created by ahmad on 3/30/23.
//

#include "attacked_board.h"

#include "colors.h"

void AttackedBoard::Initialize(SDL_Renderer *renderer, TTF_Font *font) {
    this->piece.Initialize(renderer);
    SDL_Surface *surface;
    surface = TTF_RenderText_Solid(font, "2x", color1);

    textTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    int hasht = 820;
    int masht = 1010;

    int texW = 0;
    int texH = 0;

    // White pieces
    // Pawn
    surface = TTF_RenderText_Solid(font, (std::to_string(whitePawnCounter) + "x").c_str(), color1);
    whitePawnTextTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(whitePawnTextTexture, NULL, NULL, &texW, &texH);
    whitePawnTextDstRect = {hasht, 10, texW, texH};
    whitePawnTextDstRect.y = (BOARD_CELL_SIZE - texH) / 2;

    // Knight
    surface = TTF_RenderText_Solid(font, (std::to_string(whiteKnightCounter) + "x").c_str(), color1);
    whiteKnightTextTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(whiteKnightTextTexture, NULL, NULL, &texW, &texH);
    whiteKnightTextDstRect = {hasht, 10, texW, texH};
    whiteKnightTextDstRect.y = BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;

    // Bishop
    surface = TTF_RenderText_Solid(font, (std::to_string(whiteBishopCounter) + "x").c_str(), color1);
    whiteBishopTextTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(whiteBishopTextTexture, NULL, NULL, &texW, &texH);
    whiteBishopTextDstRect = {hasht, 10, texW, texH};
    whiteBishopTextDstRect.y = 2* BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;

    // Rock
    surface = TTF_RenderText_Solid(font, (std::to_string(whiteRockCounter) + "x").c_str(), color1);
    whiteRockTextTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(whiteRockTextTexture, NULL, NULL, &texW, &texH);
    whiteRockTextDstRect = {hasht, 10, texW, texH};
    whiteRockTextDstRect.y = 3* BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;

    // Queen
    surface = TTF_RenderText_Solid(font, (std::to_string(whiteQueenCounter) + "x").c_str(), color1);
    whiteQueenTextTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(whiteQueenTextTexture, NULL, NULL, &texW, &texH);
    whiteQueenTextDstRect = {hasht, 10, texW, texH};
    whiteQueenTextDstRect.y = 4* BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;

    // Black pieces
    // Pawn
    surface = TTF_RenderText_Solid(font, ("x" + std::to_string(blackPawnCounter)).c_str(), color1);
    blackPawnTextTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(blackPawnTextTexture, NULL, NULL, &texW, &texH);
    blackPawnTextDstRect = {masht, 10, texW, texH};
    blackPawnTextDstRect.y = (BOARD_CELL_SIZE - texH) / 2;

    // Knight
    surface = TTF_RenderText_Solid(font, ("x" + std::to_string(blackKnightCounter)).c_str(), color1);
    blackKnightTextTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(blackKnightTextTexture, NULL, NULL, &texW, &texH);
    blackKnightTextDstRect = {masht, 10, texW, texH};
    blackKnightTextDstRect.y = BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;

    // Bishop
    surface = TTF_RenderText_Solid(font, ("x" + std::to_string(blackBishopCounter)).c_str(), color1);
    blackBishopTextTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(blackBishopTextTexture, NULL, NULL, &texW, &texH);
    blackBishopTextDstRect = {masht, 10, texW, texH};
    blackBishopTextDstRect.y = 2* BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;

    // Rock
    surface = TTF_RenderText_Solid(font, ("x" + std::to_string(blackRockCounter)).c_str(), color1);
    blackRockTextTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(blackRockTextTexture, NULL, NULL, &texW, &texH);
    blackRockTextDstRect = {masht, 10, texW, texH};
    blackRockTextDstRect.y = 3* BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;

    // Queen
    surface = TTF_RenderText_Solid(font, ("x" + std::to_string(blackQueenCounter)).c_str(), color1);
    blackQueenTextTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(blackQueenTextTexture, NULL, NULL, &texW, &texH);
    blackQueenTextDstRect = {masht, 10, texW, texH};
    blackQueenTextDstRect.y = 4* BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;



    SDL_QueryTexture(textTexture, NULL, NULL, &texW, &texH);
    textDstRect = {hasht, 10, texW, texH};
    textDstRect.y = (BOARD_CELL_SIZE - texH) / 2;
}

void AttackedBoard::Render(SDL_Renderer *renderer) {
    SDL_Rect r;
    r.x = 810;
    r.y = 0;
    r.w = 390;
    r.h = 500;

    SDL_SetRenderDrawColor(renderer, color2.r, color2.g, color2.b, color2.a);

    SDL_RenderFillRect(renderer, &r);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

//    SDL_RenderCopy(renderer, textTexture, NULL, &textDstRect);
    SDL_RenderCopy(renderer, whitePawnTextTexture, NULL, &whitePawnTextDstRect);
    SDL_RenderCopy(renderer, whiteKnightTextTexture, NULL, &whiteKnightTextDstRect);
    SDL_RenderCopy(renderer, whiteBishopTextTexture, NULL, &whiteBishopTextDstRect);
    SDL_RenderCopy(renderer, whiteRockTextTexture, NULL, &whiteRockTextDstRect);
    SDL_RenderCopy(renderer, whiteQueenTextTexture, NULL, &whiteQueenTextDstRect);

    SDL_RenderCopy(renderer, blackPawnTextTexture, NULL, &blackPawnTextDstRect);
    SDL_RenderCopy(renderer, blackKnightTextTexture, NULL, &blackKnightTextDstRect);
    SDL_RenderCopy(renderer, blackBishopTextTexture, NULL, &blackBishopTextDstRect);
    SDL_RenderCopy(renderer, blackRockTextTexture, NULL, &blackRockTextDstRect);
    SDL_RenderCopy(renderer, blackQueenTextTexture, NULL, &blackQueenTextDstRect);

    this->piece.RenderPawn(renderer, 840, 0, true);
    this->piece.RenderKnight(renderer, 840, 100, true);
    this->piece.RenderBishop(renderer, 840, 200, true);
    this->piece.RenderRock(renderer, 840, 300, true);
    this->piece.RenderQueen(renderer, 840, 400, true);

    this->piece.RenderPawn(renderer, 940, 0, false);
    this->piece.RenderKnight(renderer, 940, 100, false);
    this->piece.RenderBishop(renderer, 940, 200, false);
    this->piece.RenderRock(renderer, 940, 300, false);
    this->piece.RenderQueen(renderer, 940, 400, false);
}

void AttackedBoard::Destroy() {
    this->piece.Destroy();
}
