﻿#include <raylib.h>
#include "game.h"
#include "colors.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include "image.h"
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
    InitWindow(1000, 667, "Tetris OOP");
    SetTargetFPS(60);
    srand((unsigned)time(0));
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    ImageHandler background("background.png");
    ImageHandler backgroundinner("backgroundinner.png");


    Game game = Game();
    Menu menu;
    while (!WindowShouldClose())
    {
        background.Draw();
        menu.Update();
       
        if (IsKeyPressed(KEY_ENTER))
        {
            // Thực hiện hành động tương ứng với lựa chọn được chọn
            switch (menu.GetSelectedOption())
            {
            case 0: {
                int hardstage = 1;
                int cnt = 0;
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
                    string hardstageText = to_string(hardstage);
                    if (EventTriggered(max(1-hardstage*0.1,0.2)))
                    {
                        game.MoveBlockDown();
                    }
                    cnt++;
                    if (cnt == 1000) {
                        hardstage++;
                        hardstage = min(hardstage, 10);
                        cnt = 0;
                    }
                    BeginDrawing();
                    backgroundinner.Draw();
                    DrawTextEx(font, "Score", { 465, 65 }, 38, 2, WHITE);
                    DrawTextEx(font, "Next", { 465, 200 }, 38, 2, WHITE);
                    DrawTextEx(font, "Stage", { 465, 450 }, 38, 2, WHITE);
                    DrawRectangleRounded({ 450, 115, 170, 60 }, 0.3, 6, lightBlue);

                    char scoreText[10];
                    sprintf_s(scoreText, "%d", game.player.getScore());
                    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
                    Vector2 textSizeHardStage = MeasureTextEx(font, hardstageText.c_str(), 50, 6);
                    DrawTextEx(font, hardstageText.c_str(), {350 + (300 - textSizeHardStage.x) / 2, 500}, 45, 6, WHITE);
                    DrawTextEx(font, scoreText, { 450 + (170 - textSize.x) / 2, 125 }, 38, 2, WHITE);
                    DrawRectangleRounded({ 450 , 240, 170, 180 }, 0.3, 6, lightBlue);
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
                    backgroundinner.Draw();
                    DrawTextEx(font, "Score: ", { 370, 330 }, 38, 2, WHITE);
                    
                    char scoreText[10];
                    sprintf_s(scoreText, "%d", game.player.getScore());
                    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

                    DrawTextEx(font, scoreText, { 550, 330 }, 38, 2, WHITE);
                    DrawTextEx(font, "GAME OVER", { 320, 220 }, 70, 2, WHITE);
                    DrawTextEx(font, "_Press Enter To Continue_", { 250, 400 }, 38, 2, WHITE);
                    EndDrawing();

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
                    background.Draw();
                    DrawTextEx(font, "Tetris for Beginners", { 300, 130 }, 38, 2, ORANGE);

                    // Updated Description
                    DrawTextEx(font, "Objective:", { 100, 170 }, 28, 1, YELLOW);
                    DrawTextEx(font, "Arrange falling blocks to complete horizontal lines efficiently.", { 100, 200 }, 22, 1, WHITE);

                    DrawTextEx(font, "Controls:", { 100, 260 }, 28, 1, YELLOW);
                    DrawTextEx(font, "Left Arrow: Move left, Right Arrow: Move right, Down Arrow: Accelerate descent,", { 100, 290 }, 22, 1, WHITE);
                    DrawTextEx(font, "Up Arrow or Space Bar: Rotate block.", { 100, 315 }, 22, 1, WHITE);

                    DrawTextEx(font, "Tips:", { 100, 360 }, 28, 1, YELLOW);
                    DrawTextEx(font, "1. Plan ahead for efficient line clears.", { 100, 390 }, 22, 1, WHITE);
                    DrawTextEx(font, "2. Use down arrow to drop blocks quickly and fill gaps.", { 100, 415 }, 22, 1, WHITE);
                    DrawTextEx(font, "3. Be mindful of upcoming blocks and strategize placements.", { 100, 440 }, 22, 1, WHITE);
                    DrawTextEx(font, "4. Aim for Tetris clears to maximize your score.", { 100, 465 }, 22, 1, WHITE);

                    DrawTextEx(font, "22127185 - 22127128 - 22127157", { 350, 505 }, 22, 1, WHITE);


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



