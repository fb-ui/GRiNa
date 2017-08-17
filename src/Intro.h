#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <iostream> 
#include <thread>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Particle.h"
#include "Button.h"
#include "Background.h"

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
    //  载入对象
    void Load(const std::string &file, SDL_Renderer *ren);
    //  渲染
    void Render()
    //释放SDL_Texture对象
    void Free();
private:
    Texture particle_tex;
};


#endif