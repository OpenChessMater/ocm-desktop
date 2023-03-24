//
// Created by ahmad on 3/24/23.
//

#ifndef OCM_DESKTOP_PIECE_H
#define OCM_DESKTOP_PIECE_H

#include <SDL2/SDL.h>
#include <string>

class Piece {
private:
    SDL_Rect destrect = {};

    const char *whitePawnImagePath = "../resources/w-pawn.209x256.png";
//    SDL_Rect whitePawnRect = {0, 0, 209, 256};
    SDL_Rect whitePawnRect = {0, 0, 209, 256};
    SDL_Texture *whitePawnTexture;
    const char *blackPawnImagePath = "../resources/b-pawn.178x256.png";
//    SDL_Rect blackPawnRect = {0, 0, 178, 256};
    SDL_Rect blackPawnRect = {0, 0, 178, 256};
    SDL_Texture *blackPawnTexture;

    const char *whiteKnightImagePath = "../resources/w-knight.196x256.png";
//    SDL_Rect whiteKnightRect = {0, 0, 196, 256};
    SDL_Rect whiteKnightRect = {0, 0, 196, 256};
    SDL_Texture *whiteKnightTexture;
    const char *blackKnightImagePath = "../resources/b-knight.197x256.png";
//    SDL_Rect blackKnightRect = {0, 0, 197, 256};
    SDL_Rect blackKnightRect = {0, 0, 197, 256};
    SDL_Texture *blackKnightTexture;

    const char *whiteBishopImagePath = "../resources/w-bishop.188x256.png";
//    SDL_Rect whiteBishopRect = {0, 0, 188, 256};
    SDL_Rect whiteBishopRect = {0, 0, 188, 256};
    SDL_Texture *whiteBishopTexture;
    const char *blackBishopImagePath = "../resources/b-bishop.178x256.png";
//    SDL_Rect blackBishopRect = {0, 0, 178, 256};
    SDL_Rect blackBishopRect = {0, 0, 178, 256};
    SDL_Texture *blackBishopTexture;

    const char *whiteRockImagePath = "../resources/w-rook.198x256.png";
//    SDL_Rect whiteRockRect = {0, 0, 198, 256};
    SDL_Rect whiteRockRect = {0, 0, 198, 256};
    SDL_Texture *whiteRockTexture;
    const char *blackRockImagePath = "../resources/b-rook.204x256.png";
//    SDL_Rect blackRockRect = {0, 0, 204, 256};
    SDL_Rect blackRockRect = {0, 0, 204, 256};
    SDL_Texture *blackRockTexture;

    const char *whiteQueenImagePath = "../resources/w-queen.215x256.png";
//    SDL_Rect whiteQueenRect = {0, 0, 215, 256};
    SDL_Rect whiteQueenRect = {0, 0, 215, 256};
    SDL_Texture *whiteQueenTexture;
    const char *blackQueenImagePath = "../resources/b-queen.204x256.png";
//    SDL_Rect blackQueenRect = {0, 0, 204, 256};
    SDL_Rect blackQueenRect = {0, 0, 51, 64};
    SDL_Texture *blackQueenTexture;

    const char *whiteKingImagePath = "../resources/w-king.215x256.png";
//    SDL_Rect whiteKingRect = {0, 0, 215, 256};
    SDL_Rect whiteKingRect = {0, 0, 215, 256};
    SDL_Texture *whiteKingTexture;
    const char *blackKingImagePath = "../resources/b-king.230x256.png";
//    SDL_Rect blackKingRect = {0, 0, 230, 256};
    SDL_Rect blackKingRect = {0, 0, 230, 256};
    SDL_Texture *blackKingTexture;

    static SDL_Texture *initializeTexture(SDL_Renderer *renderer, const char *path);
public:
    void Initialize(SDL_Renderer *renderer);

    void RenderPawn(SDL_Renderer *renderer, int x, int y, bool white);

    void RenderKnight(SDL_Renderer *renderer, int x, int y, bool white);

    void RenderBishop(SDL_Renderer *renderer, int x, int y, bool white);

    void RenderRock(SDL_Renderer *renderer, int x, int y, bool white);

    void RenderQueen(SDL_Renderer *renderer, int x, int y, bool white);

    void RenderKing(SDL_Renderer *renderer, int x, int y, bool white);

    void Destroy();
};


#endif //OCM_DESKTOP_PIECE_H
