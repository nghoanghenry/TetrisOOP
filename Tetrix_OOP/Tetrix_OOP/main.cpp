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
                game.player.getPlayerName();
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
                    sprintf_s(scoreText, "%d", game.player.getScore());
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
                    sprintf_s(scoreText, "%d", game.player.getScore());
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
            case 1: {
                BeginDrawing();
                ClearBackground(darkBlue);
                if (IsKeyPressed(KEY_ENTER))
                    break;

            }
                  break;
                // Lựa chọn "High Scores"
                // Thực hiện hành động khi xem xếp hạng

            case 2: {
                while (true)
                {
                    BeginDrawing();
                    ClearBackground(DARKBLUE);
                    // Title
                    DrawTextEx(font, "Tetris Instruction For Beginners", { 200, 10 }, 38, 2, ORANGE);

                    // Overview
                    DrawTextEx(font, "Embark on the Tetris Adventure!", { 250, 60 }, 30, 2, BLACK);
                    DrawTextEx(font, "----------------------------------------", { 210, 90 }, 30, 2, BLACK);

                    // Gameplay Basics
                    DrawTextEx(font, "1. Tetriminos: The Building Blocks", { 70, 130 }, 25, 2, BLACK);
                    DrawTextEx(font, "   Tetris is all about Tetriminos - unique geometric shapes that fall from", { 70, 160 }, 25, 2, BLACK);
                    DrawTextEx(font, "   the top of the screen. Master their twists and turns!", { 70, 190 }, 25, 2, BLACK);

                    DrawTextEx(font, "2. The Matrix: Your Puzzle Playground", { 70, 230 }, 25, 2, BLACK);
                    DrawTextEx(font, "   Tetriminos will land in the Matrix - a grid where you orchestrate", { 70, 260 }, 25, 2, BLACK);
                    DrawTextEx(font, "   your moves. Fill complete rows to make them vanish!", { 70, 290 }, 25, 2, BLACK);

                    // Strategy Tips
                    DrawTextEx(font, "3. Think Fast, Act Faster", { 70, 330 }, 25, 2, BLACK);
                    DrawTextEx(font, "   Tetris is a game of speed and precision. Anticipate where each", { 70, 360 }, 25, 2, BLACK);
                    DrawTextEx(font, "   Tetrimino will fit for maximum points!", { 70, 390 }, 25, 2, BLACK);

                    // Closing
                    DrawTextEx(font, "Ready to Stack the Blocks?", { 250, 430 }, 30, 2, BLACK);

                    EndDrawing();
                    if (IsKeyPressed(KEY_ENTER))
                        break;
                }
                
            }
                  break;
                // Lựa chọn "Instructions"
                // Thực hiện hành động khi xem hướng dẫn
            case 3:
                // Lựa chọn "Exit"
                CloseWindow();
                return 0;
            }
        }

        BeginDrawing();
        menu.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}



