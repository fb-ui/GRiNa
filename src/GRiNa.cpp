#include "Game.h"
#include "Intro.h"
#include "Menu.h"
#include <iostream>
using namespace std;
//#define DEBUG

/*****************************
#	文件名：	GRiNa.cpp 
#	日期：		2017-07-20
#	版本号：	0.3.0
#	功能：		主程序 
#	mpsk's game engine proj
*****************************/ 

SDL_Window *window;
SDL_Renderer *renderer;
int SCREEN_WIDTH=1280, SCREEN_HEIGHT=720;

int Init()
{
	//初始化 
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
	{
		logError(cout, "SDL_Init");
		return 1;
	}
	
	//创建会话窗口 
	window = SDL_CreateWindow("GRiNa", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 
								SDL_WINDOW_FULLSCREEN_DESKTOP|SDL_WINDOW_ALLOW_HIGHDPI|SDL_WINDOW_OPENGL);
	if (window == NULL) 
	{
		logError(cout, "SDL_CreateWindow");
		SDL_Quit();
		return 1;
	}
	SDL_GL_GetDrawableSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
	cout << "Screen width is:" << SCREEN_WIDTH << endl;
	cout << "Screen height is:" << SCREEN_HEIGHT << endl;
	//创建渲染器 
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		logError(cout, "SDL_CreateRenderer");
		SDL_Quit();
		return 1;
	}
	return 0; 
}

int Quit()
{
	cout<<"Game Quit!\n"<<endl;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}


int main(int argc, char *argv[] )
{
//测试代码	
#ifdef DEBUG
	LuaScript script;
	script.Init();
	script.Load("main.lua");
	script.Docode();
	script.Free();
	return 0;
#else
	//正式代码
	Init();

	Intro *intro = new Intro(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	intro->Load();
	intro->Loop();
	intro->Quit();

	SDL_RenderClear(renderer);
	while(true)
	{
		Menu *menu = new Menu(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
		//初始化游戏
		if(menu->Load() != 0)
		{
			return 1;
		}	
		cout << "starting rendering proc... " << endl;
		Uint32 _return = menu->Loop();
		menu->Quit();
		cout << _return << endl;
		//执行游戏loop
		switch(_return)
		{
			case MENU_NEWGAME:
			{
				Game *game = new Game(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
				game->Load();
				if(game->Loop()==GAME_QUIT)
				{
					game->Quit();
					Quit();
					return 0;
				}
				game->Quit();
				break;
			}
			case MENU_QUIT:
			{
				Quit();
				return 0;
			}
			default:
			{
				break;
			}
		}
	}
	Quit();
	return 0;
#endif
}


/*

//switch case in keyboard event
			switch(event.type)
			{
				case SDL_QUIT: quit = true;
				case SDL_KEYDOWN:
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						quit = true;
					}	
					
					if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP)
					{
						y -= 10;
					}
					if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
					{
						y += 10;
					}
					if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT)
					{
						x -= 10;
					}
					if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
					{
						x += 10;
					}
					

				} 
				case SDL_MOUSEBUTTONDOWN: 
					//renderTexture(atom, renderer, 100, 100);
				case SDL_MOUSEMOTION:
				{
					ix = event.motion.x - iW/2;
					iy = event.motion.y - iH/2;
				}
			}
	*/
