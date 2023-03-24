//
// Created by ahmad on 3/23/23.
//

#include "game.h"

#include <SDL2/SDL_image.h>
#include <iostream>


Game::Game() = default;


void Game::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        std::cout << "Error SDL2 Initialization : " << SDL_GetError();
        exit(1);
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cout << "Error SDL2_image Initialization";
        exit(2);
    }

    this->window = SDL_CreateWindow("First program", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 900, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        std::cout << "Error window creation";
        exit(3);
    }

    this->renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << "Error renderer creation";
        exit(4);
    }

    this->tempo.Initialize(this->renderer, 300, 100);
    this->tempo2.Initialize(this->renderer, 100, 100);
    this->bishop1.Initialize(this->renderer, 150, 100, false);
    this->board.Initialize(this->renderer);
    this->piece.Initialize(this->renderer);
}

void Game::Run() {

    while (true) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        SDL_RenderClear(this->renderer);

        this->board.Render(this->renderer);

//        this->tempo.Render(this->renderer);
//        this->tempo2.Render(this->renderer);
//        this->bishop1.Render(this->renderer);

//        this->piece.RenderBishop(this->renderer, 0, 0, true);
//        this->piece.RenderPawn(this->renderer, 300, 100, true);
//        this->piece.RenderPawn(this->renderer, 150, 400, false);
//        this->piece.RenderQueen(this->renderer, 0, 0, false);

        SDL_RenderPresent(this->renderer);
    }
}

void Game::Destroy() {
    this->tempo.Destroy();
    this->tempo2.Destroy();
    this->board.Destroy();
    this->bishop1.Destroy();
    this->piece.Destroy();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

Game::~Game() = default;
