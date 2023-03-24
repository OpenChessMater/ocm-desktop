//
// Created by ahmad on 3/24/23.
//

#include "logic.h"


Logic* Logic::instance_{nullptr};

Logic::Logic()
{
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

Logic *Logic::GetInstance()
{
    if (instance_ == nullptr)
    {
        instance_ = new Logic();
    }

    return instance_;
}

PieceLogic *Logic::PieceAt(int i, int j) {
    return this->pieceLogic[i][j];
}


Logic::~Logic() = default;

PieceLogic::PieceLogic(PieceLogic::Role r, bool w)
{
    this->role = r;
    this->white = w;
}
