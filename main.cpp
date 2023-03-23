//#include "game.h"
//
//int main(int argc, char *argv[])
//{
//    Game g;
//    g.Run();
//
//    return 0;
//}

#include "game.h"

int main(int argc, char* argv[]) {
    Game g;
    g.Initialize();
    g.Run();
    g.Destroy();

    return 0;
}
