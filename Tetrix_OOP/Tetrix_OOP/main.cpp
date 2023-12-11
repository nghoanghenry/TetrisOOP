#include <raylib.h>
#include "game.h"
#include "colors.h"
#include "Menu.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(1000, 800, "Tetris OOP");
    SetTargetFPS(60);
    srand((unsigned)time(0));
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();
    Menu menu;
    while (!WindowShouldClose())
    {
        menu.Update();
       
        if (IsKeyPressed(KEY_ENTER))
        {
            // Thực hiện hành động tương ứng với lựa chọn được chọn
            switch (menu.GetSelectedOption())
            {
            case 0: {
                if (game.gameOver == true) {
                    game.Reset();
                }
                while (game.gameOver == false) {
                    // Lựa chọn "Play"
                    // Thực hiện hành động khi chơi
                    if (WindowShouldClose() == true) {
                        CloseWindow();
                        return 0;
                    }
                    UpdateMusicStream(game.music);
                    game.HandleInput();
                    if (EventTriggered(0.2))
                    {
                        game.MoveBlockDown();
                    }

                    BeginDrawing();
                    ClearBackground(darkBlue);
                    DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
                    DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
                    DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);

                    char scoreText[10];
                    sprintf_s(scoreText, "%d", game.score);
                    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

                    DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);
                    DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
                    game.Draw();
                    EndDrawing();
                    if (game.gameOver)
                    {
                        DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
                    }
                }
                while(true)
                {
                    UpdateMusicStream(game.music);
                    BeginDrawing();
                    ClearBackground(darkBlue);
                    DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
                    DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
                    DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);

                    char scoreText[10];
                    sprintf_s(scoreText, "%d", game.score);
                    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

                    DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);
                    DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
                    game.Draw();
                    EndDrawing();
                    DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
                    if (IsKeyPressed(KEY_ENTER)) break;
                }
                break;
            }
            case 1:
                // Lựa chọn "High Scores"
                // Thực hiện hành động khi xem xếp hạng
                break;
            case 2:
                // Lựa chọn "Instructions"
                // Thực hiện hành động khi xem hướng dẫn
                break;
            case 3:
                // Lựa chọn "Exit"
                CloseWindow();
                return 0;
                break;
            }
        }

        BeginDrawing();
        menu.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}



