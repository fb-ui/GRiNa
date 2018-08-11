#include "Game.h"
#include "Intro.h"
#include "Menu.h"
#include "GR_Script.h"
#include "GR_Resource.h"
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
		GR_LogError(cout, "SDL_Init");
		return 1;
	}
	
	//创建会话窗口 
	window = SDL_CreateWindow("GRiNa", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 
								SDL_WINDOW_FULLSCREEN_DESKTOP|SDL_WINDOW_ALLOW_HIGHDPI|SDL_WINDOW_OPENGL);
	if (window == NULL) 
	{
		GR_LogError(cout, "SDL_CreateWindow");
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
		GR_LogError(cout, "SDL_CreateRenderer");
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
/*
	GR_Script script;
	if(script.Load("Resource/script.grs")!=0)
	{
		cout << "Error Reading file!" << endl;
		return -1;
	}
	int i = 0;
	while(1)
	{
		string s;
		if(script.Docode(s)==-1)
		{
			break;
		}
		cout << i++ << " " << s << endl;
	}
	return 0;
	*/
	std::cout << "Here~" << std::endl;
	GR_ResourceManager *res = new GR_ResourceManager("Resource/menu.grconf");


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
		if(menu->Load("Resource/menu.grconf") != 0)
		{
			return 1;
		}	
		Uint32 _return = menu->Loop();
		delete menu;
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
					delete game;
					Quit();
					return 0;
				}
				delete game;
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

