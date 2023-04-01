//
// Created by ahmad on 3/30/23.
//

#include "attacked_board.h"

#include "colors.h"
#include "logic.h"

void AttackedBoard::Initialize(SDL_Renderer *renderer, TTF_Font *font) {
    this->piece.Initialize(renderer);

    this->_font = font;
    this->_renderer = renderer;

    this->hasht = 820;
    this->masht = 1010;

    // White pieces
    this->drawPawnTextTexture(true);
    this->drawKnightTextTexture(true);
    this->drawBishopTextTexture(true);
    this->drawRockTextTexture(true);
    this->drawQueenTextTexture(true);

    // Black pieces
    this->drawPawnTextTexture(false);
    this->drawKnightTextTexture(false);
    this->drawBishopTextTexture(false);
    this->drawRockTextTexture(false);
    this->drawQueenTextTexture(false);
//
//    SDL_QueryTexture(textTexture, NULL, NULL, &texW, &texH);
//    textDstRect = {hasht, 10, texW, texH};
//    textDstRect.y = (BOARD_CELL_SIZE - texH) / 2;
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

    this->checkChange();
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

void AttackedBoard::checkChange() {
    auto logic = Logic::GetInstance();

    if (whitePawnCounter != logic->PawnAttackedCount(true)) {
        whitePawnCounter = logic->PawnAttackedCount(true);
        this->drawPawnTextTexture(true);
    }

    if (whiteKnightCounter != logic->KnightAttackedCount(true)) {
        whiteKnightCounter = logic->KnightAttackedCount(true);
        this->drawKnightTextTexture(true);
    }

    if (whiteBishopCounter != logic->BishopAttackedCount(true)) {
        whiteBishopCounter = logic->BishopAttackedCount(true);
        this->drawBishopTextTexture(true);
    }

    if (whiteRockCounter != logic->RockAttackedCount(true)) {
        whiteRockCounter = logic->RockAttackedCount(true);
        this->drawRockTextTexture(true);
    }

    if (whiteQueenCounter != logic->QueenAttackedCount(true)) {
        whiteQueenCounter = logic->QueenAttackedCount(true);
        this->drawQueenTextTexture(true);
    }


    if (blackPawnCounter != logic->PawnAttackedCount(false)) {
        blackPawnCounter = logic->PawnAttackedCount(false);
        this->drawPawnTextTexture(false);
    }

    if (blackKnightCounter != logic->KnightAttackedCount(false)) {
        blackKnightCounter = logic->KnightAttackedCount(false);
        this->drawKnightTextTexture(false);
    }

    if (blackBishopCounter != logic->BishopAttackedCount(false)) {
        blackBishopCounter = logic->BishopAttackedCount(false);
        this->drawBishopTextTexture(false);
    }

    if (blackRockCounter != logic->RockAttackedCount(false)) {
        blackRockCounter = logic->RockAttackedCount(false);
        this->drawRockTextTexture(false);
    }

    if (blackQueenCounter != logic->QueenAttackedCount(false)) {
        blackQueenCounter = logic->QueenAttackedCount(false);
        this->drawQueenTextTexture(false);
    }
}

void AttackedBoard::drawPawnTextTexture(bool _white) {
    SDL_Surface *surface;

    int texW = 0;
    int texH = 0;

    if (_white) {
        surface = TTF_RenderText_Solid(this->_font, (std::to_string(whitePawnCounter) + "x").c_str(), color1);
        whitePawnTextTexture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(whitePawnTextTexture, NULL, NULL, &texW, &texH);
        whitePawnTextDstRect = {hasht, 10, texW, texH};
        whitePawnTextDstRect.y = (BOARD_CELL_SIZE - texH) / 2;
    } else {
        surface = TTF_RenderText_Solid(this->_font, ("x" + std::to_string(blackPawnCounter)).c_str(), color1);
        blackPawnTextTexture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(blackPawnTextTexture, NULL, NULL, &texW, &texH);
        blackPawnTextDstRect = {masht, 10, texW, texH};
        blackPawnTextDstRect.y = 0 * BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;
    }
}

void AttackedBoard::drawKnightTextTexture(bool _white) {
    SDL_Surface *surface;

    int texW = 0;
    int texH = 0;

    if (_white) {
        surface = TTF_RenderText_Solid(this->_font, (std::to_string(whiteKnightCounter) + "x").c_str(), color1);
        whiteKnightTextTexture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(whiteKnightTextTexture, NULL, NULL, &texW, &texH);
        whiteKnightTextDstRect = {hasht, 10, texW, texH};
        whiteKnightTextDstRect.y = BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;
    } else {
        surface = TTF_RenderText_Solid(this->_font, ("x" + std::to_string(blackKnightCounter)).c_str(), color1);
        blackKnightTextTexture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(blackKnightTextTexture, NULL, NULL, &texW, &texH);
        blackKnightTextDstRect = {masht, 10, texW, texH};
        blackKnightTextDstRect.y = 1 * BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;
    }
}

void AttackedBoard::drawBishopTextTexture(bool _white) {
    SDL_Surface *surface;

    int texW = 0;
    int texH = 0;

    if (_white) {
        surface = TTF_RenderText_Solid(this->_font, (std::to_string(whiteBishopCounter) + "x").c_str(), color1);
        whiteBishopTextTexture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(whiteBishopTextTexture, NULL, NULL, &texW, &texH);
        whiteBishopTextDstRect = {hasht, 10, texW, texH};
        whiteBishopTextDstRect.y = 2 * BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;
    } else {
        surface = TTF_RenderText_Solid(this->_font, ("x" + std::to_string(blackBishopCounter)).c_str(), color1);
        blackBishopTextTexture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(blackBishopTextTexture, NULL, NULL, &texW, &texH);
        blackBishopTextDstRect = {masht, 10, texW, texH};
        blackBishopTextDstRect.y = 2 * BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;
    }
}

void AttackedBoard::drawRockTextTexture(bool _white) {
    SDL_Surface *surface;

    int texW = 0;
    int texH = 0;

    if (_white) {
        surface = TTF_RenderText_Solid(this->_font, (std::to_string(whiteRockCounter) + "x").c_str(), color1);
        whiteRockTextTexture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(whiteRockTextTexture, NULL, NULL, &texW, &texH);
        whiteRockTextDstRect = {hasht, 10, texW, texH};
        whiteRockTextDstRect.y = 3 * BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;
    } else {
        surface = TTF_RenderText_Solid(this->_font, ("x" + std::to_string(blackRockCounter)).c_str(), color1);
        blackRockTextTexture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(blackRockTextTexture, NULL, NULL, &texW, &texH);
        blackRockTextDstRect = {masht, 10, texW, texH};
        blackRockTextDstRect.y = 3 * BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;
    }
}

void AttackedBoard::drawQueenTextTexture(bool _white) {
    SDL_Surface *surface;

    int texW = 0;
    int texH = 0;

    if (_white) {
        surface = TTF_RenderText_Solid(this->_font, (std::to_string(whiteQueenCounter) + "x").c_str(), color1);
        whiteQueenTextTexture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(whiteQueenTextTexture, NULL, NULL, &texW, &texH);
        whiteQueenTextDstRect = {hasht, 10, texW, texH};
        whiteQueenTextDstRect.y = 4 * BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;
    } else {
        surface = TTF_RenderText_Solid(this->_font, ("x" + std::to_string(blackQueenCounter)).c_str(), color1);
        blackQueenTextTexture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(blackQueenTextTexture, NULL, NULL, &texW, &texH);
        blackQueenTextDstRect = {masht, 10, texW, texH};
        blackQueenTextDstRect.y = 4 * BOARD_CELL_SIZE + (BOARD_CELL_SIZE - texH) / 2;
    }
}
