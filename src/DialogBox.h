#ifndef DIALOGBOX_H
#define DIALOGBOX_H

#include <string>

#include "../include/SDL.h"
#include "../include/SDL_image.h"
#include "../include/SDL_ttf.h"
#include "Texture.h"

class DialogBox
{
public:
    DialogBox(int w, int h);
    int Load(const std::string file);
    int Render(int x, int y);
    int Free();
private:
    int w, h;
};

#endif