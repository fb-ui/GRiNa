#include "Game.h"
#define DEBUG
/*****************************
#	文件名：	Game.cpp 
#	日期：		2017-01-17
#	版本号：	0.3.0
#	功能：		游戏对象 
#	mpsk's game engine proj
*****************************/ 

 int Game::Init()
{
	//初始化 
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
	{
		logError(std::cout, "SDL_Init");
		return 1;
	}
	
	//创建会话窗口 
	window = SDL_CreateWindow("Test", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
	if (window == NULL) 
	{
		logError(std::cout, "SDL_CreateWindow");
		SDL_Quit();
		return 1;
	}
	//创建渲染器 
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		logError(std::cout, "SDL_CreateRenderer");
		SDL_Quit();
		return 1;
	}
	return 0; 
}

int Game::Load()
{
	//加载资源 
	//加载图像资源 	
	//****************************
	//纹理对象初始化
	//****************************
	button_start = new Button(0,0,160,50,"Resource/start.png",renderer);
	button_help = new Button(0,60,160,50,"Resource/help.png",renderer);
	background.LoadTexture("Resource/background.jpg", renderer);
	//button_start.LoadTexture("Resource/start.png", renderer);
	//button_help.LoadTexture("Resource/help.png", renderer);
	//*****************************
	//粒子系统设置
	//*****************************	 
	std::cout << "initiating particlesys obj..." << std::endl; 
	//初始化重力与速度 
	Vector2D gravity;
	gravity.x = 0;
	gravity.y = 0.0005;
	//初始化粒子系统 
	//particles.SetRenderer(renderer);
	particles.LoadTexture("Resource/atom.png", renderer);
	particles.SetKinematic(SCREEN_WIDTH, SCREEN_HEIGHT, 10, gravity);
	particles.SetAlpha(128);
	//重设渲染器 
	SDL_RenderClear(renderer);
	//获得图像长高 

	return 0;
}


int Game::Loop()
{

	//计时器开始计时
	//timer.start();
		 
	//清理渲染器 
	SDL_RenderClear(renderer);
	
	//设定粒子速度
	Vector2D speed;
	speed.x = 0;
	speed.y = 0; 
	
	//粒子系统压入粒子 
	particles.Push(10,150,speed); 


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
					button_start->MouseButtonEvent(MOUSEBUTTONDOWN);
					button_help->MouseButtonEvent(MOUSEBUTTONDOWN);
				}	
				else
				{
					//2代表鼠标按键释放
					button_start->MouseButtonEvent(MOUSEBUTTONUP);
					button_help->MouseButtonEvent(MOUSEBUTTONUP);
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
	/*旧版本背景渲染
	for (int j = 0 ; SCREEN_WIDTH >= j; j += background.GetWidth() )
	{
		for (int k = 0; SCREEN_HEIGHT >= k; k += background.GetHeight())
		{
			background.Render(j, k, renderer);
		} 	
	}
	*/
	background.Render(SCREEN_WIDTH, SCREEN_HEIGHT, renderer);

	button_help->Render();
	button_start->Render();
	//对象层渲染

	//粒子层渲染 
	particles.Render_Central(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, renderer);
	//渲染器渲染 
	SDL_RenderPresent(renderer);
	//SDL_Delay(100);
	

	//计算帧数
	/*
	timer.queryfreq();
	timer.stop();
	tick = timer.ticks()/float(1000);
	fps = 1/tick;
	std::cout << tick << " ms" <<std::endl;
	std::cout << fps*1000 << " fps" <<std::endl;
	*/
	return 0;
}

int Game::Quit()
{
	particles.Free();
	background.Free();
	button_help->Free();
	button_start->Free();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
