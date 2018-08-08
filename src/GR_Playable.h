#ifndef GR_Playable_H
#define GR_Playable_H

#include <list>

#include "GR_Particle.h"
#include "GR_Button.h"
#include "GR_Background.h"

class GR_Playable
{
	private:
		SDL_Renderer *renderer;
		SDL_Event event;
		GR_Background *background;
		std::list<GR_Button> buttons;
		std::list<GR_Button>::iterator button_iter;
		//float tick;
		//float fps;
		//int i;
	public:
		int SCREEN_WIDTH;		//画面分辨率 
		int SCREEN_HEIGHT;
		bool quit = false;
		GR_Playable(SDL_Renderer *renderer, int w, int h);
        int Init();
        int Load();
		Uint32 Loop();
		int Quit();
};

#endif