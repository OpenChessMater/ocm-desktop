//
// Created by ahmad on 3/24/23.
//

#include "board.h"
#include "logic.h"
#include "const.h"

void Board::Initialize(SDL_Renderer *renderer) {
    this->piece.Initialize(renderer);
}

void Board::Render(SDL_Renderer *renderer) {
    rect.x = 0;
    rect.y = 0;
    rect.w = BOARD_CELL_SIZE;
    rect.h = BOARD_CELL_SIZE;


    auto logic = Logic::GetInstance();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            SDL_Rect r;
            r.x = i * rect.w + rect.x;
            r.y = j * rect.h + rect.y;
            r.w = rect.w;
            r.h = rect.h;

            if ((i + j) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, blackCellFillColor.r, blackCellFillColor.g, blackCellFillColor.b,
                                       blackCellFillColor.a);
            } else {
                SDL_SetRenderDrawColor(renderer, whiteCellFillColor.r, whiteCellFillColor.g, whiteCellFillColor.b,
                                       whiteCellFillColor.a);
            }

            SDL_RenderFillRect(renderer, &r);

            if (i == 6 && j == 6) {
                SDL_SetRenderDrawColor(renderer, cellHoverBorderColor.r, cellHoverBorderColor.g, cellHoverBorderColor.b,
                                       cellHoverBorderColor.a);
            } else {
                SDL_SetRenderDrawColor(renderer, cellBorderColor.r, cellBorderColor.g, cellBorderColor.b,
                                       cellBorderColor.a);
            }

            SDL_RenderDrawRect(renderer, &r);
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);


    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            auto p = logic->PieceAt(i, j);
            if (p != nullptr) {
                switch (p->role) {
                    case PieceLogic::PAWN:
                        this->piece.RenderPawn(renderer, j * BOARD_CELL_SIZE, i *  BOARD_CELL_SIZE, p->white);
                        break;
                    case PieceLogic::KNIGHT:
                        this->piece.RenderKnight(renderer, j * BOARD_CELL_SIZE, i *  BOARD_CELL_SIZE, p->white);
                        break;
                    case PieceLogic::BISHOP:
                        this->piece.RenderBishop(renderer, j * BOARD_CELL_SIZE, i *  BOARD_CELL_SIZE, p->white);
                        break;
                    case PieceLogic::ROCK:
                        this->piece.RenderRock(renderer, j * BOARD_CELL_SIZE, i *  BOARD_CELL_SIZE, p->white);
                        break;
                    case PieceLogic::QUEEN:
                        this->piece.RenderQueen(renderer, j * BOARD_CELL_SIZE, i *  BOARD_CELL_SIZE, p->white);
                        break;
                    case PieceLogic::KING:
                        this->piece.RenderKing(renderer, j * BOARD_CELL_SIZE, i *  BOARD_CELL_SIZE, p->white);
                        break;
                }
            }
        }
    }

//    this->piece.RenderPawn(renderer, 300, 100, false);
//    this->piece.RenderKnight(renderer, 200, 100, false);
//    this->piece.RenderBishop(renderer, 0, 0, false);
//    this->piece.RenderRock(renderer, 0, 0, true);
//    this->piece.RenderQueen(renderer, 100, 100, false);
//    this->piece.RenderQueen(renderer, 100, 0, false);
//    this->piece.RenderKing(renderer, 170, 0, true);
//    this->piece.RenderKing(renderer, 290, 0, false);

}

void Board::Destroy() {
    this->piece.Destroy();
}
