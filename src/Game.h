#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <iostream> 
#include <thread>
#include <vector>

#include "../include/SDL.h"
#include "../include/SDL_image.h"

#include "Particle.h"
#include "Button.h"
#include "Background.h"

#include "Log.h"
#include "Vector2D.h"
#include "Script.h"


#define GAME_NEXT		0x0001
#define GAME_PAUSE		0x0002
#define GAME_OPTION		0x0003
#define GAME_SAVE		0x0004
#define GAME_ESCAPE		0x0005
#define	GAME_QUIT		0xFFFF
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
		SDL_Renderer *renderer;
		SDL_Window *window;
		SDL_Event event;
		int SCREEN_WIDTH;		//画面分辨率 
		int SCREEN_HEIGHT;
		ParticleSys *particles;
		Background *background;
		vector<Button> buttons;
		vector<Button>::iterator button_iter;
		//Timer timer;
		float tick;
		float fps;

		int i;
	public:
		bool quit = 0;
		Game(SDL_Renderer *ren, int w, int h);
		int Load();
		int Loop();
		int Quit();
};


#endif
