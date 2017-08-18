#include "Menu.h"
#define DEBUG
using namespace std;
/*****************************
#	文件名：	Menu.cpp 
#	日期：		2017-08-17
#	版本号：	0.3.0
#	功能：		游戏对象 
#	mpsk's game engine proj
*****************************/ 

Menu::Menu(SDL_Renderer *renderer, int w, int h)
{
    this->renderer = renderer;
    this->SCREEN_WIDTH = w;
    this->SCREEN_HEIGHT = h;
}

int Menu::Load()
{
	//加载资源 
	//加载图像资源 	
	//****************************
	//纹理对象初始化
	//****************************
	buttons.push_back(Button(0,0,160,50,"Resource/start.png",renderer, MENU_NEWGAME));
	buttons.push_back(Button(0,60,160,50,"Resource/start.png",renderer, MENU_RESUME));
	buttons.push_back(Button(0,120,160,50,"Resource/start.png",renderer, MENU_OPTION));
	buttons.push_back(Button(0,180,160,50,"Resource/start.png",renderer, MENU_ABOUT));
	buttons.push_back(Button(0,240,160,50,"Resource/start.png",renderer, MENU_QUIT));
	
	background = new Background();
	background->LoadTexture("Resource/background.bmp", renderer);
	//重设渲染器 
	SDL_RenderClear(renderer);

	return 0;
}


Uint32 Menu::Loop()
{
	while(true)
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
						return MENU_QUIT;
					}
				} 
				case SDL_MOUSEBUTTONUP:
				case SDL_MOUSEBUTTONDOWN: 
				{
					//判断事件要使用合并的处理，否则将无法分开
					if(event.type == SDL_MOUSEBUTTONDOWN)
					{
						//1代表摁下，后期会统一使用宏描述
						for(iter=buttons.begin();iter!=buttons.end();iter++)
						{
							(*iter).MouseButtonEvent(MOUSE_BUTTON_DOWN);
						}
					}	
					else
					{
						//2代表鼠标按键释放
						for(iter=buttons.begin();iter!=buttons.end();iter++)
						{
							if((*iter).is_pushed)
							{
								return (*iter).id;
							}
							(*iter).MouseButtonEvent(MOUSE_BUTTON_UP);
						}
					}
				}
				case SDL_MOUSEMOTION:
				{
					for(iter=buttons.begin();iter!=buttons.end();iter++)
					{
						(*iter).MouseMotionEvent(event.motion.x, event.motion.y);
					}
				}
			}
		}
		
		//计算渲染顶点 
		//背景层渲染 
		background->Render(SCREEN_WIDTH, SCREEN_HEIGHT, renderer);
		
		for(iter=buttons.begin();iter!=buttons.end();iter++)
		{
			(*iter).Render();
		}
		//对象层渲染
		
		//渲染器渲染 
		SDL_RenderPresent(renderer);
	}
}

int Menu::Quit()
{
	background->Free();
	for(iter=buttons.begin();iter!=buttons.end();iter++)
	{
		(*iter).Free();
	}
    
	return 0;
}
