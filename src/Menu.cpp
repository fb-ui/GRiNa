#include "Menu.h"
#define DEBUG
using namespace std;
/*****************************
#	文件名：	Game.cpp 
#	日期：		2017-08-17
#	版本号：	0.3.0
#	功能：		游戏对象 
#	mpsk's game engine proj
*****************************/ 

int Menu::Init(int w, int h, SDL_Renderer *renderer)
{
    this->renderer = renderer;
    this->SCREEN_WIDTH = w;
    this->SCREEN_HEIGHT = h;
	return 0; 
}

int Menu::Load()
{
	//加载资源 
	//加载图像资源 	
	//****************************
	//纹理对象初始化
	//****************************
	button_start = new Button(0,0,160,50,"Resource/start.png",renderer);
	button_help = new Button(0,60,160,50,"Resource/start.png",renderer);
	
	background = new Background();
	background->LoadTexture("Resource/background.bmp", renderer);
	//重设渲染器 
	SDL_RenderClear(renderer);

	return 0;
}


int Menu::Loop()
{		 
	//清理渲染器 
	SDL_RenderClear(renderer);

	while (SDL_PollEvent(&event))
	{	
		switch(event.type)
		{
			case SDL_QUIT: quit = true;
			case SDL_KEYDOWN:
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			} 
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEBUTTONDOWN: 
			{
				//判断事件要使用合并的处理，否则将无法分开
				if(event.type == SDL_MOUSEBUTTONDOWN)
				{
					//1代表摁下，后期会统一使用宏描述
					button_start->MouseButtonEvent(MOUSE_BUTTON_DOWN);
					button_help->MouseButtonEvent(MOUSE_BUTTON_DOWN);
				}	
				else
				{
					//2代表鼠标按键释放
					button_start->MouseButtonEvent(MOUSE_BUTTON_UP);
					button_help->MouseButtonEvent(MOUSE_BUTTON_UP);
				}
			}
			case SDL_MOUSEMOTION:
			{
				button_start->MouseMotionEvent(event.motion.x, event.motion.y);
				button_help->MouseMotionEvent(event.motion.x, event.motion.y);
			}
		}
	}
	
	//计算渲染顶点 
	//背景层渲染 
	background->Render(SCREEN_WIDTH, SCREEN_HEIGHT, renderer);
	
	button_help->Render();
	button_start->Render();
    //对象层渲染
    
	//渲染器渲染 
	SDL_RenderPresent(renderer);
	return 0;
}

int Menu::Quit()
{
	background->Free();
	button_help->Free();
    button_start->Free();
    
	return 0;
}
