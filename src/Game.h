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
//#include "Timer.h"
//#include "lua_Script.h"
//#include "Script.h"
//#include "windows.h"

/*****************************
#	文件名：	Game.h
#	日期：		2017-1-15
#	版本号：	0.3.2
#	功能：		游戏对象 
#	mpsk's game engine proj
*****************************/ 

class Game
{
	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Event event;
		int SCREEN_WIDTH  = 1280;		//画面分辨率 
		int SCREEN_HEIGHT = 720;
		ParticleSys particles;
		Background background;
		Button *button_start;
		Button *button_help;
		//Timer timer;
		float tick;
		float fps;


		int i;
	public:
		bool quit = 0;
		int Init();
		int Load();
		int Loop();
		int Quit();
};


#endif
