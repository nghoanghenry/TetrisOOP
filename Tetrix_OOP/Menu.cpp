#include "menu.h"

Menu::Menu() : selectedOption(0) {}

Menu::~Menu() {}

void Menu::Draw()
{
    ClearBackground(RAYWHITE);

    DrawText("__Tetrix Menu__", 310, 180, 45, YELLOW);
    DrawText("1. Play", 400, 270, 35, selectedOption == 0 ? RED : WHITE);
    DrawText("2. Scores", 400, 320, 35, selectedOption == 1 ? RED : WHITE);
    DrawText("3. Help", 400, 370, 35, selectedOption == 2 ? RED : WHITE);
    DrawText("4. Exit", 400, 420, 35, selectedOption == 3 ? RED : WHITE);
}

void Menu::Update()
{
    if (IsKeyPressed(KEY_UP))
    {
        selectedOption = (selectedOption - 1 + 4) % 4;
    }
    else if (IsKeyPressed(KEY_DOWN))
    {
        selectedOption = (selectedOption + 1) % 4;
    }
}

int Menu::GetSelectedOption() const
{
    return selectedOption;
}
