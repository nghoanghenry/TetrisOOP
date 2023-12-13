#pragma once
#include "raylib.h"

class ImageHandler {
public:
    ImageHandler(const char* imagePath);
    ~ImageHandler();

    void Draw();

private:
    Texture2D backgroundTexture;
};