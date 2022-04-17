#include <iostream>
#include <Windows.h>
#include "Game/Window.h"
#include "Game/SDL.h"

using namespace RubtidDungeon;

int main(int argc, char* args[])
{
    if (SDL::Instance()->Init()) {
        auto window = RubtidDungeon::Window("Rubtid Dungeon", 144);
        
        while (true) {
            window.HandleEvents();
            window.Frame();
        }
    }

    return 0;
}
