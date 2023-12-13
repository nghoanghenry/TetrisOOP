#include "image.h"
ImageHandler::ImageHandler(const char* imagePath) {
    Image backgroundImage = LoadImage(imagePath);
    backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);
}

ImageHandler::~ImageHandler() {
    UnloadTexture(backgroundTexture);
}

void ImageHandler::Draw() {
    DrawTexture(backgroundTexture, 0, 0, WHITE);
}