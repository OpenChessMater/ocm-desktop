//
// Created by ahmad on 3/23/23.
//

#include "game.h"

#include <SDL2/SDL_image.h>
#include <iostream>


Game::Game()
{

}


void Game::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        std::cout << "Error SDL2 Initialization : " << SDL_GetError();
        exit(1);
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cout << "Error SDL2_image Initialization";
        exit(2);
    }

    window = SDL_CreateWindow("First program", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        std::cout << "Error window creation";
        exit(3);
    }

    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << "Error renderer creation";
        exit(4);
    }

    lettuce_sur = IMG_Load("../resources/chess-bishop.153x256.png");
    if (lettuce_sur == NULL) {
        std::cout << "Error loading image: " << IMG_GetError();
        exit(5);
    }

    lettuce_tex = SDL_CreateTextureFromSurface(renderer, lettuce_sur);
    if (lettuce_tex == NULL) {
        std::cout << "Error creating texture";
        exit(6);
    }

    SDL_FreeSurface(lettuce_sur);

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

        SDL_RenderClear(renderer);


        SDL_SetRenderDrawColor(renderer, 250, 0, 100, 0);
        SDL_RenderFillRect(renderer, &rect);


        SDL_SetRenderDrawColor(renderer, 0, 250, 100, 0);
        SDL_RenderFillRect(renderer, &rect2);


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

        SDL_RenderCopy(renderer, lettuce_tex, NULL, &destrect);

        SDL_RenderPresent(renderer);
    }

}

void Game::run() {

}

void Game::Destroy() {
    SDL_DestroyTexture(lettuce_tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

Game::~Game() = default;
