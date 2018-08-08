#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <iostream> 
#include <thread>
#include <vector>

#include "../include/SDL.h"
#include "../include/SDL_image.h"

#include "GR_Particle.h"
#include "GR_Button.h"
#include "GR_Background.h"
#include "GR_Log.h"
#include "Vector2D.h"


#define GAME_BUTTON_START		0xF001
#define GAME_BUTTON_PAUSE		0xF002
#define GAME_BUTTON_OPTION		0xF003
#define GAME_BUTTON_SAVE		0xF004
#define GAME_BUTTON_ESCAPE		0xF005
#define	GAME_BUTTON_QUIT		0xFFFF
#define GAME_START				GAME_BUTTON_START
#define GAME_PAUSE				GAME_BUTTON_PAUSE
#define GAME_OPTION				GAME_BUTTON_OPTION
#define GAME_SAVE				GAME_BUTTON_SAVE
#define GAME_ESCAPE				GAME_BUTTON_ESCAPE
#define GAME_QUIT				GAME_BUTTON_QUIT
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
		GR_ParticleSys *particles;
		GR_Background *background;
		vector<GR_Button*> buttons;
		vector<GR_Button*>::iterator button_iter;
	public:
		bool quit = 0;
		Game(SDL_Renderer *ren, int w, int h);
		int Load();
		int Loop();
		int Quit();
};


#endif
