#include "../include/SDL.h"
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
	this->resources.push_back(SDL_RWFromFile("Resource/start.png","rb"));
	this->resources.push_back(SDL_RWFromFile("Resource/pause.png","rb"));
	this->resources.push_back(SDL_RWFromFile("Resource/option.png","rb"));
	this->resources.push_back(SDL_RWFromFile("Resource/about.png","rb"));
	this->resources.push_back(SDL_RWFromFile("Resource/quit.png","rb"));
	this->resources.push_back(SDL_RWFromFile("Resource/city1.png", "rb"));
	this->resources.push_back(SDL_RWFromFile("Resource/city2.png", "rb"));
	this->resources.push_back(SDL_RWFromFile("Resource/city3.png", "rb"));

	this->buttons.push_back(
		new GR_Button(this->SCREEN_WIDTH - MENU_MARGIN - MENU_BUTTON_W,
			this->SCREEN_HEIGHT - 5*MENU_BUTTON_H - MENU_MARGIN,
			MENU_BUTTON_W, MENU_BUTTON_H,
			//SDL_RWFromFile("Resource/start.png","rb"),
			this->resources[0],
			this->renderer, 
			MENU_NEWGAME));
	/*
	this->buttons.push_back(
		new GR_Button(this->SCREEN_WIDTH - MENU_MARGIN - MENU_BUTTON_W,
			this->SCREEN_HEIGHT - 4*MENU_BUTTON_H - MENU_MARGIN,
			MENU_BUTTON_W, MENU_BUTTON_H,
			//SDL_RWFromFile("Resource/pause.png","rb"),
			this->resources[1],
			this->renderer, 
			MENU_RESUME));
	*/
	this->buttons.push_back(
		new GR_Button(this->SCREEN_WIDTH - MENU_MARGIN - MENU_BUTTON_W,
			this->SCREEN_HEIGHT - 3*MENU_BUTTON_H - MENU_MARGIN,
			MENU_BUTTON_W, MENU_BUTTON_H,
			//SDL_RWFromFile("Resource/option.png","rb"),
			this->resources[2],
			this->renderer, 
			MENU_OPTION));
	this->buttons.push_back(
		new GR_Button(this->SCREEN_WIDTH - MENU_MARGIN - MENU_BUTTON_W,
			this->SCREEN_HEIGHT - 2*MENU_BUTTON_H - MENU_MARGIN,
			MENU_BUTTON_W, MENU_BUTTON_H,
			//SDL_RWFromFile("Resource/about.png","rb"),
			this->resources[3],
			this->renderer, 
			MENU_ABOUT));
	this->buttons.push_back(
		new GR_Button(this->SCREEN_WIDTH - MENU_MARGIN - MENU_BUTTON_W,
			this->SCREEN_HEIGHT - 1*MENU_BUTTON_H - MENU_MARGIN,
			MENU_BUTTON_W, MENU_BUTTON_H,
			//SDL_RWFromFile("Resource/quit.png","rb"),
			this->resources[4],
			this->renderer, 
			MENU_QUIT));

	this->layer.push_back(
		new GR_Texture(
			//SDL_RWFromFile("Resource/city1.png", "rb"),
			this->resources[5],
			this->renderer,
			MENU_CITY1)
	);
	this->layer.push_back(
		new GR_Texture(
			//SDL_RWFromFile("Resource/city2.png", "rb"),
			this->resources[6],
			this->renderer,
			MENU_CITY2)
	);
	this->layer.push_back(
		new GR_Texture(
			//SDL_RWFromFile("Resource/city3.png", "rb"),
			this->resources[7],
			this->renderer,
			MENU_CITY3)
	);
	
	this->background = new GR_Background();
	this->background->LoadTexture(SDL_RWFromFile("Resource/background.bmp","rb"), this->renderer);
	//重设渲染器 
	SDL_RenderClear(this->renderer);
	return 0;
}


Uint32 Menu::Loop()
{
	int fx = this->SCREEN_WIDTH/2, fy = this->SCREEN_HEIGHT/2;
	while(true)
	{ 
		//重设渲染器 
		SDL_RenderClear(this->renderer);
		while(SDL_PollEvent(&event))
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
						for(button_iter=this->buttons.begin();button_iter!=this->buttons.end();button_iter++)
						{
							(*this->button_iter)->MouseButtonEvent(MOUSE_BUTTON_DOWN);
						}
					}	
					else
					{
						//2代表鼠标按键释放
						for(button_iter=this->buttons.begin();button_iter!=this->buttons.end();button_iter++)
						{
							if((*this->button_iter)->is_pushed)
							{
								return (*this->button_iter)->id;
							}
							(*this->button_iter)->MouseButtonEvent(MOUSE_BUTTON_UP);
						}
					}
				}
				case SDL_MOUSEMOTION:
				{
					for(button_iter=this->buttons.begin();button_iter!=this->buttons.end();button_iter++)
					{
						(*this->button_iter)->MouseMotionEvent(event.motion.x, event.motion.y);
					}
					fx = event.motion.x;
					fy = event.motion.y;
				}
			}
		}
		
		//计算渲染顶点 
		//背景层渲染 
		this->background->Render(SCREEN_WIDTH, SCREEN_HEIGHT, this->renderer);
		
		int level = 2;
		for(this->layer_iter=this->layer.begin();this->layer_iter!=this->layer.end();this->layer_iter++)
		{
			(*this->layer_iter)->Render_clip(
				-MENU_MARGIN - 0.1*(fx-this->SCREEN_WIDTH/2)-0.1*level*(fx-this->SCREEN_WIDTH/2), 
				this->SCREEN_HEIGHT-(*this->layer_iter)->GetHeight()-0.5*level*MENU_MARGIN - level*0.1*(fy-this->SCREEN_HEIGHT/2),
				this->SCREEN_WIDTH+2*MENU_MARGIN,
				(*this->layer_iter)->GetHeight(),
				0, 0,
				(*this->layer_iter)->GetWidth(), (*this->layer_iter)->GetHeight(),
				this->renderer
				);
			level--;
		}

		for(button_iter=this->buttons.begin();button_iter!=this->buttons.end();button_iter++)
		{
			(*this->button_iter)->Render();
		}
		//对象层渲染
		
		//渲染器渲染 
		SDL_RenderPresent(this->renderer);
	}
}

int Menu::Quit()
{
	this->background->Free();
	for(button_iter=this->buttons.begin();button_iter!=this->buttons.end();button_iter++)
	{
		delete (*this->button_iter);
	}
    for(this->layer_iter=this->layer.begin();this->layer_iter!=this->layer.end();this->layer_iter++)
	{
		delete (*this->layer_iter);
	}
	return 0;
}
