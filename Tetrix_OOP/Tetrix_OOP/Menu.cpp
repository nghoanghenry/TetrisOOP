#include "menu.h"

Menu::Menu() : selectedOption(0) {}

Menu::~Menu() {}

void Menu::Draw()
{
    ClearBackground(RAYWHITE);

    DrawText("Simple Menu", 150, 80, 40, DARKGRAY);
    DrawText("1. Play", 200, 180, 30, selectedOption == 0 ? RED : DARKGRAY);
    DrawText("2. High Scores", 200, 230, 30, selectedOption == 1 ? RED : DARKGRAY);
    DrawText("3. Instructions", 200, 280, 30, selectedOption == 2 ? RED : DARKGRAY);
    DrawText("4. Exit", 200, 330, 30, selectedOption == 3 ? RED : DARKGRAY);
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
