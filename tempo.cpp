//
// Created by ahmad on 3/24/23.
//

#include <SDL2/SDL_image.h>
#include <iostream>
#include "tempo.h"

Tempo::Tempo() {
    this->sur = nullptr;
    this->tex = nullptr;
}

void Tempo::Initialize(SDL_Renderer *renderer, int x, int y) {

    this->sur = IMG_Load("../resources/chess-bishop.153x256.png");
    if (this->sur == NULL) {
        std::cout << "Error loading image: " << IMG_GetError();
        exit(5);
    }

    this->tex = SDL_CreateTextureFromSurface(renderer, this->sur);
    if (this->tex == NULL) {
        std::cout << "Error creating texture";
        exit(6);
    }

    SDL_FreeSurface(this->sur);

    this->destrect.x = x;
    this->destrect.y = y;
    this->destrect.w = 153;
    this->destrect.h = 256;

}

void Tempo::Render(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, this->tex, NULL, &this->destrect);
}

void Tempo::Destroy() {
    SDL_DestroyTexture(this->tex);
}

Tempo::~Tempo() = default;
