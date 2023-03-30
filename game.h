//
// Created by ahmad on 3/23/23.
//

#ifndef OCM_DESKTOP_GAME_H
#define OCM_DESKTOP_GAME_H

#include <SDL2/SDL.h>
#include "tempo.h"
#include "board.h"
#include "bishop.h"
#include "piece.h"
#include "attacked_board.h"

class Game
{
private:
    SDL_Window *window{};
    SDL_Renderer *renderer{};

    Tempo tempo;
    Tempo tempo2;
    Board board;
    Bishop bishop1;
    Piece piece;
    AttackedBoard attack_board;

    bool runningState = true;

    void handleEvent();
    void render();

public:
    Game();
    void Initialize();
    void Run();
    void Destroy();

    ~Game();
};

#endif //OCM_DESKTOP_GAME_H
