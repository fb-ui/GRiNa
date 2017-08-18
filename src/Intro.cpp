#include "Intro.h"
Intro::Intro()
{

}
Intro::Intro(const std::string &file, SDL_Renderer *ren)
{

}
//  载入对象
void Intro::Init(const std::string &file, SDL_Renderer *ren)
{

}
//  渲染
void Intro::Loop()
{
    while(true)
    {
        //清理渲染器 
		SDL_RenderClear(this->renderer);

		while (SDL_PollEvent(&event))
		{	
			switch(event.type)
			{
				case SDL_QUIT: return;
				case SDL_KEYDOWN:
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						return;
					}
				} 
			}
		}
		
		//计算渲染顶点 
		//背景层渲染 
		Logo->Render(Screen_w/2-Logo->GetWidth()/2, Screen_h/2-Logo->GetWidth()/2, renderer);
		
	}
	
}
//释放SDL_Texture对象
void Intro::Free()
{

}