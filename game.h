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

class Game
{
private:
    SDL_Window *window{};
    SDL_Renderer *renderer{};
    SDL_Surface* lettuce_sur{};
    SDL_Texture* lettuce_tex{};

    Tempo tempo;
    Tempo tempo2;
    Board board;
    Bishop bishop1;
    Piece piece;

public:
    Game();
    void Initialize();
    void Run();
    void Destroy();

    ~Game();
};

#endif //OCM_DESKTOP_GAME_H
