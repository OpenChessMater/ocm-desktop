//
// Created by ahmad on 3/24/23.
//

#include "logic.h"


Logic *Logic::instance_{nullptr};

Logic::Logic() {
    this->pieceLogic[0][0] = new PieceLogic(PieceLogic::ROCK, false);
    this->pieceLogic[0][1] = new PieceLogic(PieceLogic::KNIGHT, false);
    this->pieceLogic[0][2] = new PieceLogic(PieceLogic::BISHOP, false);
    this->pieceLogic[0][3] = new PieceLogic(PieceLogic::QUEEN, false);
    this->pieceLogic[0][4] = new PieceLogic(PieceLogic::KING, false);
    this->pieceLogic[0][5] = new PieceLogic(PieceLogic::BISHOP, false);
    this->pieceLogic[0][6] = new PieceLogic(PieceLogic::KNIGHT, false);
    this->pieceLogic[0][7] = new PieceLogic(PieceLogic::ROCK, false);
    for (int i = 0; i < 8; ++i) {
        this->pieceLogic[1][i] = new PieceLogic(PieceLogic::PAWN, false);
    }

    this->pieceLogic[7][0] = new PieceLogic(PieceLogic::ROCK, true);
    this->pieceLogic[7][1] = new PieceLogic(PieceLogic::KNIGHT, true);
    this->pieceLogic[7][2] = new PieceLogic(PieceLogic::BISHOP, true);
    this->pieceLogic[7][3] = new PieceLogic(PieceLogic::QUEEN, true);
    this->pieceLogic[7][4] = new PieceLogic(PieceLogic::KING, true);
    this->pieceLogic[7][5] = new PieceLogic(PieceLogic::BISHOP, true);
    this->pieceLogic[7][6] = new PieceLogic(PieceLogic::KNIGHT, true);
    this->pieceLogic[7][7] = new PieceLogic(PieceLogic::ROCK, true);
    for (int i = 0; i < 8; ++i) {
        this->pieceLogic[6][i] = new PieceLogic(PieceLogic::PAWN, true);
    }
}

Logic *Logic::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new Logic();
    }

    return instance_;
}

PieceLogic *Logic::PieceAt(int i, int j) {
    return this->pieceLogic[j][i];
}

void Logic::Move(int fromI, int fromJ, int toI, int toJ) {
    this->pieceLogic[toJ][toI] = this->pieceLogic[fromJ][fromI];
    this->pieceLogic[fromJ][fromI] = nullptr;
}

std::vector<std::pair<int, int>> Logic::AvailableMoves(int i, int j) {
    std::vector<std::pair<int, int>> result;

    if (pieceLogic[j][i] == nullptr) {
        return result;
    }

    auto p = pieceLogic[j][i];
    switch (p->role) {
        case PieceLogic::PAWN:
            return this->pawnAvailableMoves(i, j, p->white);
        case PieceLogic::KNIGHT:
            return this->knightAvailableMoves(i, j, p->white);
        case PieceLogic::BISHOP:
            return this->bishopAvailableMoves(i, j, p->white);
        case PieceLogic::ROCK:
            return this->rockAvailableMoves(i, j, p->white);
        case PieceLogic::QUEEN:
            return this->queenAvailableMoves(i, j, p->white);
        case PieceLogic::KING:
            return this->kingAvailableMoves(i, j, p->white);
    }

    return result;
}

std::vector<std::pair<int, int>> Logic::pawnAvailableMoves(int i, int j, bool side) {
    std::vector<std::pair<int, int>> result;

    if (side == white) {
        if (j - 1 >= 0) {
            auto p = this->pieceLogic[j - 1][i];
            if (p == nullptr) {
                result.emplace_back(i, j - 1);
                if (j - 2 >= 0){
                    p = this->pieceLogic[j - 2][i];
                    if (p == nullptr || p->white != side)
                        result.emplace_back(i, j - 2);
                }
            } else if (p->white != side) {
                result.emplace_back(i, j - 1);
            }
        }
    } else /* if (side != white) */ {
        if (j + 1 < 8) {
            auto p = this->pieceLogic[j + 1][i];
            if (p == nullptr) {
                result.emplace_back(i, j + 1);
                if (j + 2 < 8) {
                    p = this->pieceLogic[j + 2][i];
                    if (p == nullptr || p->white != side)
                        result.emplace_back(i, j + 2);
                }
            } else if (p->white != side) {
                result.emplace_back(i, j + 1);
            }
        }
    }

    return result;
}

std::vector<std::pair<int, int>> Logic::knightAvailableMoves(int i, int j, bool side) {
    return std::vector<std::pair<int, int>>();
}

std::vector<std::pair<int, int>> Logic::bishopAvailableMoves(int i, int j, bool side) {
    return std::vector<std::pair<int, int>>();
}

std::vector<std::pair<int, int>> Logic::rockAvailableMoves(int i, int j, bool side) {
    return std::vector<std::pair<int, int>>();
}

std::vector<std::pair<int, int>> Logic::queenAvailableMoves(int i, int j, bool side) {
    return std::vector<std::pair<int, int>>();
}

std::vector<std::pair<int, int>> Logic::kingAvailableMoves(int i, int j, bool side) {
    return std::vector<std::pair<int, int>>();
}


Logic::~Logic() = default;

PieceLogic::PieceLogic(PieceLogic::Role r, bool w) {
    this->role = r;
    this->white = w;
}
