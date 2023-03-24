//
// Created by ahmad on 3/24/23.
//

#include "bishop.h"
#include <SDL2/SDL_image.h>
#include <iostream>

void Bishop::Initialize(SDL_Renderer *renderer, int x, int y, bool white)
{
    if (white) {
        this->sur = IMG_Load("../resources/w-bishop.188x256.png");
    } else {
        this->sur = IMG_Load("../resources/b-bishop.178x256.png");
    }

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
    this->destrect.h = 256;
    if (white) {
        this->destrect.w = 188;
    } else {
        this->destrect.w = 178;
    }

}

void Bishop::Render(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, this->tex, NULL, &this->destrect);
}

void Bishop::Destroy()
{
    SDL_DestroyTexture(this->tex);
}
