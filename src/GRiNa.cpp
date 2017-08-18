#include "Game.h"
#include "Button.h"
#include <iostream>
//#define DEBUG

/*****************************
#	文件名：	GRiNa.cpp 
#	日期：		2017-07-20
#	版本号：	0.3.0
#	功能：		主程序 
#	mpsk's game engine proj
*****************************/ 

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
	Game game;
	//初始化游戏
	if(game.Init() != 0)
	{
		return 1;
	}	
	//载入游戏
	if(game.Load() != 0)
	{
		return 1;
	}
	std::cout << "starting rendering proc... " << std::endl;
	//执行游戏loop
	game.Loop();
	//游戏执行完毕
	//结束
	game.Quit();
	std::cout<<"Game Quit!\n"<<std::endl;
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
