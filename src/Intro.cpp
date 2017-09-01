#include "../include/SDL.h"
#include "Intro.h"

Intro::Intro(SDL_Renderer *ren, int Screen_w, int Screen_h)
{
	this->ren = ren;
	this->Screen_w = Screen_w;
	this->Screen_h = Screen_h;
}
//  载入对象
void Intro::Load()
{
	this->logo = new Texture();
	this->logo->Load(SDL_RWFromFile("Resource/logo.jpg","rb"), this->ren);
	this->logo->SetBlendMode(SDL_BLENDMODE_BLEND);
}
//  渲染
void Intro::Loop()
{
	SDL_Event event;
	//this->logo->SetAlpha(10);
    for(int alpha=0; alpha<255; alpha+=2)
    {
        //清理渲染器 
		SDL_RenderClear(this->ren);
		while (SDL_PollEvent(&event))
		{	
			switch(event.type)
			{
				case SDL_QUIT: return;
				case SDL_KEYDOWN:
				{
					if (event.key.keysym.sym == SDLK_SPACE)
					{
						return;
					}
				} 
			}
		}
		this->logo->SetAlpha(alpha);
		this->logo->Render(Screen_w/2-logo->GetWidth()/2, Screen_h/2-logo->GetWidth()/2, this->ren);
		SDL_RenderPresent(this->ren);
	}
	SDL_Delay(200);
	for(int alpha=255; alpha>0; alpha-=2)
    {
        //清理渲染器 
		SDL_RenderClear(this->ren);

		while (SDL_PollEvent(&event))
		{	
			switch(event.type)
			{
				case SDL_QUIT: return;
				case SDL_KEYDOWN:
				{
					if (event.key.keysym.sym == SDLK_SPACE)
					{
						return;
					}
				} 
			}
		}
		this->logo->SetAlpha(alpha);
		this->logo->Render(Screen_w/2-logo->GetWidth()/2, Screen_h/2-logo->GetWidth()/2, this->ren);
		SDL_RenderPresent(this->ren);
	}
	return;
	
}
//释放SDL_Texture对象
void Intro::Quit()
{
	this->logo->Free();
}