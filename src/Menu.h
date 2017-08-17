#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <iostream> 
#include <thread>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Particle.h"
#include "Button.h"
#include "Background.h"

#include "Log.h"
#include "Vector2D.h"

/*****************************
#	文件名：	Menu.h
#	日期：		2017-8-17
#	版本号：	0.4.0
#	功能：		菜单对象 
#	mpsk's game engine proj
*****************************/ 

class Menu
{
	private:
		SDL_Renderer *renderer;
		SDL_Event event;
		Background *background;
		vector<Button> buttons;
		Button *button_start;
		Button *button_help;
		float tick;
		float fps;
		int Loop();
        
		int i;
	public:
		int SCREEN_WIDTH;		//画面分辨率 
		int SCREEN_HEIGHT;
		bool quit = 0;
        int Menu::Init(int w, int h, SDL_Renderer *renderer);
        int Load();
        int Run();
		int Quit();
};


#endif