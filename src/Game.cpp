#include "Game.h"
#define DEBUG
using namespace std;
/*****************************
#	文件名：	Game.cpp 
#	日期：		2017-08-17
#	版本号：	0.3.0
#	功能：		游戏对象 
#	mpsk's game engine proj
*****************************/ 

Game::Game(SDL_Renderer *renderer, int w, int h)
{
	this->renderer = renderer;
	this->SCREEN_WIDTH = w;
	this->SCREEN_HEIGHT = h;
}

int Game::Load()
{
	//加载资源 
	//加载图像资源 	
	//****************************
	//纹理对象初始化
	//****************************
	buttons.push_back(Button(0,0,160,50,"Resource/start.png",renderer, GAME_NEXT));
	buttons.push_back(Button(0,60,160,50,"Resource/start.png",renderer, GAME_ESCAPE));
	
	background = new Background(BG_STITCH);
	background->LoadTexture("Resource/background.bmp", renderer);
	//*****************************
	//粒子系统设置
	//*****************************	 
	cout << "initiating particlesys obj..." << endl; 
	//初始化重力与速度 
	Vector2D gravity;
	gravity.x = 0.0005;
	gravity.y = 0.0005;
	//初始化粒子系统 
	//	每次压入个数	粒子寿命	初始x速度	初始y速度
	particles = new ParticleSys(10, 150, 1, 0);
	particles->LoadTexture("Resource/atom.png", renderer);
	//	设置边框	设置重力
	particles->SetKinematic(SCREEN_WIDTH, SCREEN_HEIGHT, 10, gravity);
	particles->SetAlpha(128);
	//重设渲染器 
	SDL_RenderClear(renderer);

	return 0; 
}


int Game::Loop()
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
						this->quit = true;
						return GAME_QUIT;
					}
				} 
				case SDL_MOUSEBUTTONUP:
				case SDL_MOUSEBUTTONDOWN: 
				{
					//判断事件要使用合并的处理，否则将无法分开
					if(event.type == SDL_MOUSEBUTTONDOWN)
					{
						//1代表摁下，后期会统一使用宏描述
						for(button_iter=buttons.begin();button_iter!=buttons.end();button_iter++)
						{
							(*button_iter).MouseButtonEvent(MOUSE_BUTTON_DOWN);
						}
					}	
					else
					{
						//2代表鼠标按键释放
						for(button_iter=buttons.begin();button_iter!=buttons.end();button_iter++)
						{
							if((*button_iter).is_pushed)
							{
								switch((*button_iter).id)
								{
									case GAME_NEXT:
									{
										break;
									}
									case GAME_ESCAPE:
									{
										return (*button_iter).id;
									}
								}
							}
							(*button_iter).MouseButtonEvent(MOUSE_BUTTON_UP);
						}
					}
				}
				case SDL_MOUSEMOTION:
				{
					for(button_iter=buttons.begin();button_iter!=buttons.end();button_iter++)
					{
						(*button_iter).MouseMotionEvent(event.motion.x, event.motion.y);
					}
				}
			}
		}
		
		//计算渲染顶点 
		//背景层渲染 
		background->Render(SCREEN_WIDTH, SCREEN_HEIGHT, renderer);
		
		for(button_iter=buttons.begin();button_iter!=buttons.end();button_iter++)
		{
			(*button_iter).Render();
		}
		//对象层渲染

		//粒子层渲染 
		particles->Render_Central(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, renderer);
		//渲染器渲染 
		SDL_RenderPresent(renderer);
	}
	return GAME_ESCAPE;
}

int Game::Quit()
{
	particles->Free();
	background->Free();

	for(button_iter=buttons.begin();button_iter!=buttons.end();button_iter++)
	{
		(*button_iter).Free();
	}

	return 0;
}
