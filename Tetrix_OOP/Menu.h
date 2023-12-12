#pragma once
#include <string>
#include "raylib.h"

class Menu
{
public:
    Menu();
    ~Menu();

    void Draw();
    void Update();
    int GetSelectedOption() const;
private:
    int selectedOption;
};