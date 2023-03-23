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

    this->window = SDL_CreateWindow("First program", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
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
    this->board.Initialize(this->renderer);
}

void Game::Run() {

    this->lettuce_sur = IMG_Load("../resources/chess-bishop.153x256.png");
    if (this->lettuce_sur == NULL) {
        std::cout << "Error loading image: " << IMG_GetError();
        exit(5);
    }

    this->lettuce_tex = SDL_CreateTextureFromSurface(this->renderer, this->lettuce_sur);
    if (this->lettuce_tex == NULL) {
        std::cout << "Error creating texture";
        exit(6);
    }

    SDL_FreeSurface(this->lettuce_sur);
    SDL_Rect destrect;
    destrect.w = 153;
    destrect.h = 256;

    SDL_Rect rect;
    rect.x = 10;
    rect.y = 10;
    rect.w = 100;
    rect.h = 160;


    SDL_Rect rect2;
    rect2.x = 10 + rect.x +rect.w;
    rect2.y = 10 + rect.y + rect.h;
    rect2.w = 150;
    rect2.h = 160;

    while (true) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        SDL_RenderClear(this->renderer);

//
//        SDL_SetRenderDrawColor(this->renderer, 250, 0, 100, 0);
//        SDL_RenderFillRect(this->renderer, &rect);
//
//
//        SDL_SetRenderDrawColor(this->renderer, 0, 250, 100, 0);
//        SDL_RenderFillRect(this->renderer, &rect2);
//
//
//        SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);

        this->board.Render(this->renderer);

        SDL_RenderCopy(this->renderer, this->lettuce_tex, NULL, &rect2);

        this->tempo.Render(this->renderer);
        this->tempo2.Render(this->renderer);

        SDL_RenderPresent(this->renderer);
    }
}

void Game::Destroy() {
    this->tempo.Destroy();
    this->tempo2.Destroy();
    this->board.Destroy();

    SDL_DestroyTexture(lettuce_tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

Game::~Game() = default;
