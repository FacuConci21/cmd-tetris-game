#include "Menu.h"


Menu::Menu(vector<SItem<void>*> _items, __utils::SPoint _ptTopLeft = { 0, 0 })
    : szpItems(_items),
    ptTopLeft(_ptTopLeft),
    cursor({ _ptTopLeft }),
    itTarget(szpItems.begin())
{
    height = szpItems.size();
    width = LongestTextItem();
};

void Menu::AppendItem(SItem<void>* _item)
{
    szpItems.push_back(_item);
}

bool Menu::MoveCursor()
{
    cursor.PutCursorInConsole();

    switch (_getch())
    {
    case 72:
        cursor.ClearCursorCurrentPosition();
        cursor.MoveUp();
        itTarget--;
        break;
    case 80:
        cursor.ClearCursorCurrentPosition();
        cursor.MoveDown(szpItems.size() - 1);
        itTarget++;
        break;
    case 13:
        return false;
    default:
        return true;
    }

    if (itTarget < szpItems.begin())
        itTarget = szpItems.begin();
    else if (itTarget == szpItems.end())
        itTarget = szpItems.end() - 1;

    return true;
}

vector<SItem<void>*>::iterator Menu::Loop()
{
    bool inLoop;
    system("cls");

    ShowItems();

    do
    {
        inLoop = MoveCursor();
    } while (inLoop);

    return itTarget;
}