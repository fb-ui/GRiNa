#ifndef INTRO_H
#define INTRO_H

#include <stdlib.h>
#include <iostream> 
#include <thread>

#include "Texture.h"

#include "Log.h"
#include "Vector2D.h"

/*****************************
#	文件名：	Intro.h
#	日期：		2017-8-17
#	版本号：	0.3.2
#	功能：	    游戏logo
#	mpsk's game engine proj
*****************************/ 

class Intro
{
public:
    Intro(SDL_Renderer *ren, int Screen_w, int Screen_h);
    //  载入对象
    void Load();
    //  渲染
    void Loop();
    //释放SDL_Texture对象
    void Quit();
private:
    //  Logo
    int Screen_w, Screen_h;
    Texture *logo;
    SDL_Renderer *ren;
};


#endif