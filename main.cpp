#include "game.h"

int main(int argc, char* argv[]) {
    Game g;
    g.Initialize();
    g.Run();
    g.Destroy();

    return 0;
}
