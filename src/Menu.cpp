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
	this->plain_list = new GR_ElementList("plain");
	this->button_list = new GR_ElementList("button");
	this->res_manager = nullptr;
}

Menu::~Menu()
{
	this->Quit();
}

int Menu::Load(std::string filename)
{
	//加载资源 
	//加载图像资源 	
	//****************************
	//纹理对象初始化
	//****************************

	this->res_manager = new GR_ResourceManager(filename);

	this->button_list->Push(
		new GR_Button(this->SCREEN_WIDTH - MENU_MARGIN - MENU_BUTTON_W,
			this->SCREEN_HEIGHT - 5*MENU_BUTTON_H - MENU_MARGIN,
			MENU_BUTTON_W, MENU_BUTTON_H,
			this->res_manager->GetResource("button", "button_start"),
			this->renderer, 
			MENU_NEWGAME), "button_start");
	this->button_list->Push(
		new GR_Button(this->SCREEN_WIDTH - MENU_MARGIN - MENU_BUTTON_W,
			this->SCREEN_HEIGHT - 3*MENU_BUTTON_H - MENU_MARGIN,
			MENU_BUTTON_W, MENU_BUTTON_H,
			this->res_manager->GetResource("button", "button_option"),
			this->renderer, 
			MENU_OPTION), "button_option");
	this->button_list->Push(
		new GR_Button(this->SCREEN_WIDTH - MENU_MARGIN - MENU_BUTTON_W,
			this->SCREEN_HEIGHT - 2*MENU_BUTTON_H - MENU_MARGIN,
			MENU_BUTTON_W, MENU_BUTTON_H,
			this->res_manager->GetResource("button", "button_about"),
			this->renderer, 
			MENU_ABOUT), "button_about");
	this->button_list->Push(
		new GR_Button(this->SCREEN_WIDTH - MENU_MARGIN - MENU_BUTTON_W,
			this->SCREEN_HEIGHT - 1*MENU_BUTTON_H - MENU_MARGIN,
			MENU_BUTTON_W, MENU_BUTTON_H,
			this->res_manager->GetResource("button", "button_quit"),
			this->renderer, 
			MENU_QUIT), "button_quit");

	this->plain_list->Push(
		new GR_Element(
			this->res_manager->GetResource("plain", "plain_city1"),
			this->renderer,
			"city1")
	);
	this->plain_list->Push(
		new GR_Element(
			this->res_manager->GetResource("plain", "plain_city2"),
			this->renderer,
			"city2")
	);
	this->plain_list->Push(
		new GR_Element(
			this->res_manager->GetResource("plain", "plain_city3"),
			this->renderer,
			"city3")
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
						for(this->button_list->CursorReset();!this->button_list->CursorEnd();this->button_list->CursorNext())
						{
							((GR_Button*)this->button_list->GetCursor())->MouseButtonEvent(MOUSE_BUTTON_DOWN);
						}
					}	
					else
					{
						//2代表鼠标按键释放
						for(this->button_list->CursorReset();!this->button_list->CursorEnd();this->button_list->CursorNext())
						{
							if(((GR_Button*)this->button_list->GetCursor())->is_pushed)
							{
								return ((GR_Button*)this->button_list->GetCursor())->id;
							}
							((GR_Button*)this->button_list->GetCursor())->MouseButtonEvent(MOUSE_BUTTON_UP);
						}
					}
				}
				case SDL_MOUSEMOTION:
				{
					for(this->button_list->CursorReset();!this->button_list->CursorEnd();this->button_list->CursorNext())
					{
						((GR_Button*)this->button_list->GetCursor())->MouseMotionEvent(event.motion.x, event.motion.y);
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
		for(this->plain_list->CursorReset();!this->plain_list->CursorEnd();this->plain_list->CursorNext())
		{
			GR_Element *ptr = this->plain_list->GetCursor();
			ptr->Render_clip(
				-MENU_MARGIN - 0.1*(fx-this->SCREEN_WIDTH/2)-0.1*level*(fx-this->SCREEN_WIDTH/2), 
				this->SCREEN_HEIGHT - ptr->GetHeight() - 0.5*level*MENU_MARGIN - level*0.1*(fy-this->SCREEN_HEIGHT/2),
				this->SCREEN_WIDTH+2*MENU_MARGIN,
				ptr->GetHeight(),
				0, 0,
				ptr->GetWidth(), ptr->GetHeight(),
				this->renderer
				);
			level--;
		}

		for(this->button_list->CursorReset();!this->button_list->CursorEnd();this->button_list->CursorNext())
		{
			((GR_Button*)this->button_list->GetCursor())->Render();
		}
		//对象层渲染
		
		//渲染器渲染 
		SDL_RenderPresent(this->renderer);
	}
}

int Menu::Quit()
{
	delete this->background;
	delete this->button_list;
	delete this->plain_list;
	return 0;
}
