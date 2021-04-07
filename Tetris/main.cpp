#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

#include "Menu.h"
#include "Game.h"

using namespace std;

int nGameExit = 0;

void NewGame();

void LoadGame();

void QuitGame();

void Loading();

int main()
{
    SItem<void> ng = { "new game", NewGame };
    SItem<void> lg = { "load game", LoadGame };
    SItem<void> qg = { "quit game", QuitGame };

    Menu menu({ &ng, &lg, &qg }, { 30, 15 });

    do
    {
        auto it = *menu.Loop(true);
        system("cls");
        (it->toDo)();

    } while (nGameExit >=0);
    
	return 0;
}

void NewGame()
{
    nGameExit = Game::Main();
    //_getch();
}

void LoadGame()
{
    cout << "nothing to do ..." << endl;
    if (_getch() == 27)
        nGameExit = 1;
}

void QuitGame()
{
    nGameExit = -1;
}