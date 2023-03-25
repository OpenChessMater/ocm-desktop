//
// Created by ahmad on 3/24/23.
//

#ifndef OCM_DESKTOP_LOGIC_H
#define OCM_DESKTOP_LOGIC_H

#include <vector>

class PieceLogic {

public:
    enum Role {
        PAWN,
        KNIGHT,
        BISHOP,
        ROCK,
        QUEEN,
        KING
    } role;

    bool white;

    PieceLogic(Role role, bool white);
};

class Logic {

private:
    static Logic *instance_;

    PieceLogic *pieceLogic[8][8] = {nullptr};

    bool white = true; // If true shows that white pieces are down of the board and they move upward (y index will decrease)

protected:
    Logic();

    ~Logic();

    std::vector<std::pair<int, int>> pawnAvailableMoves(int i, int j, bool side);
    std::vector<std::pair<int, int>> knightAvailableMoves(int i, int j, bool side);
    std::vector<std::pair<int, int>> bishopAvailableMoves(int i, int j, bool side);
    std::vector<std::pair<int, int>> rockAvailableMoves(int i, int j, bool side);
    std::vector<std::pair<int, int>> queenAvailableMoves(int i, int j, bool side);
    std::vector<std::pair<int, int>> kingAvailableMoves(int i, int j, bool side);
public:
    Logic(Logic &other) = delete;

    void operator=(const Logic &) = delete;

    static Logic *GetInstance();

    PieceLogic *PieceAt(int i, int j);

    std::vector<std::pair<int, int>> AvailableMoves(int i, int j);

    void Move(int fromI, int fromJ, int toI, int toJ);
};


#endif //OCM_DESKTOP_LOGIC_H
