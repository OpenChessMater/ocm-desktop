//
// Created by ahmad on 3/24/23.
//

#ifndef OCM_DESKTOP_LOGIC_H
#define OCM_DESKTOP_LOGIC_H

class PieceLogic {

public:
    enum Role {
        PAWN,
        KNIGHT,
        BISHOP,
        ROCK,
        QUEEN,
        KING
    }role;

    bool white;

    PieceLogic(Role role, bool white);
};

class Logic {

private:
    static Logic * instance_;

    PieceLogic *pieceLogic[8][8] = {nullptr};

protected:
    Logic();
    ~Logic();

public:
    Logic(Logic &other) = delete;
    void operator=(const Logic &) = delete;

    static Logic *GetInstance();

    PieceLogic *PieceAt(int i, int j);
};


#endif //OCM_DESKTOP_LOGIC_H
