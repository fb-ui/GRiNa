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

#define MENU_NEWGAME	0x0001
#define MENU_RESUME		0x0002
#define MENU_OPTION		0x0003
#define MENU_ABOUT		0x0004
#define	MENU_QUIT		0x0005

class Menu
{
	private:
		SDL_Renderer *renderer;
		SDL_Event event;
		Background *background;
		list<Button> buttons;
		list<Button>::iterator iter;
		Button *button_start;
		Button *button_help;
		float tick;
		float fps;
        
		int i;
	public:
		int SCREEN_WIDTH;		//画面分辨率 
		int SCREEN_HEIGHT;
		bool quit = 0;
		Menu(SDL_Renderer *renderer, int w, int h);
        int Init();
        int Load();
		Uint32 Loop();
		int Quit();
};


#endif