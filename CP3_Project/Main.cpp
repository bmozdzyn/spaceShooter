#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define new new
#endif

#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <time.h>
#include "Game.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    srand(time(0));

    Game game;
    game.run();

    //_CrtDumpMemoryLeaks();


    //int* ptr = new int(5);

    return 0;
}

