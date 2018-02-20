#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <iostream> 
#include <thread>
#include <list>

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

#define MENU_NEWGAME	0xF001
#define MENU_RESUME		0xF002
#define MENU_OPTION		0xF003
#define MENU_ABOUT		0xF004
#define	MENU_QUIT		0xFFFF

#define MENU_CITY1		0xE001
#define MENU_CITY2		0xE002
#define MENU_CITY3		0xE003

#define MENU_MARGIN		60
#define MENU_BUTTON_W	160
#define MENU_BUTTON_H	50


class Menu
{
	private:
		SDL_Renderer *renderer;
		SDL_Event event;
		Background *background;
		list<Button> buttons;
		list<Button>::iterator button_iter;
		list<Texture> layer;
		list<Texture>::iterator layer_iter;
		Button *button_start;
		Button *button_help;
		//float tick;
		//float fps;
		//int i;
	public:
		int SCREEN_WIDTH;		//画面分辨率 
		int SCREEN_HEIGHT;
		bool quit = false;
		Menu(SDL_Renderer *renderer, int w, int h);
        int Init();
        int Load();
		Uint32 Loop();
		int Quit();
};


#endif