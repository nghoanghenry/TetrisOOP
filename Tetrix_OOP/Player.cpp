#include "Player.h"
#include "image.h"

Player::Player() {
    score = 0;
    name = "";
    letterCount = 0;
}

Player::Player(const std::string& playerName, int playerScore) : name(playerName), score(playerScore) {}

int Player::getScore() {
    return score;
}
void Player::setScore(int s) {
    score += s;
}
void Player::reset() {
    score = 0;
}

void Player::getPlayerName() {
    char name[MAX_INPUT_CHARS + 1] = "\0";
    bool mouseOnText = false;
    int framesCounter = 0;
    Rectangle textBox = { 800 / 2.0f, 280, 225, 50 };
    ImageHandler backgroundinner("backgroundinner.png");
    while (!WindowShouldClose()) {
        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText) {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            int key = GetCharPressed();

            // Check if more characters have been pressed on the same frame
            while (key > 0) {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
                    name[letterCount] = (char)key;
                    name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
                    letterCount++;
                }

                key = GetCharPressed();  // Check next character in the queue
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }
        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText)
            framesCounter++;
        else
            framesCounter = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        backgroundinner.Draw();


        DrawText("PLACE MOUSE OVER INPUT BOX!", 200, 230, 40, WHITE);

        DrawRectangleRec(textBox, WHITE);
        if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
        else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, WHITE);

        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);
        
        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 800 / 2.0f + 10, 350, 20, WHITE);

        if (mouseOnText)
        {   
            if (letterCount < MAX_INPUT_CHARS)
            {
                // Draw blinking underscore char
                if (((framesCounter / 20) % 2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
            }
            else DrawText("Press BACKSPACE to delete chars...", 330, 400, 20, RED);
        }
        this->name = std::string(name);
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER)) break;
        //----------------------------------------------------------------------------------
    }
    memset(name, '\0', sizeof(name));
    letterCount = 0;

    // De-Initialization
    //--------------------------------------------------------------------------------------
}

string Player::getName() {
    return name;
}
