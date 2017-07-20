#ifndef BACKGROUND_H
#define BACKGROUND
#include "Texture.h"
//#include "Image.h"

/*****************************
#	文件名：	Background.h
#	日期：		2017-1-17
#	版本号：	0.3.2
#	功能：		背景对象 
#	mpsk's game engine proj
*****************************/ 

class Background
{
    public:
        void LoadTexture(const std::string &file, SDL_Renderer *ren);
        void Render(int Screen_w, int Screen_h, SDL_Renderer *ren);
        void Free();
    private:
        Texture tex;
        SDL_Rect dst;
};

#endif