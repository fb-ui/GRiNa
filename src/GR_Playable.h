#ifndef GR_Playable_H
#define GR_Playable_H

#include <list>

#include "GR_Particle.h"
#include "GR_Button.h"
#include "GR_Background.h"

class GR_Playable
{
	protected:
		SDL_Renderer *renderer;
		SDL_Event event;
		GR_Background *background;
		list<GR_Button*> buttons;
		list<GR_Button*>::iterator button_iter;
		list<GR_Texture*> layer;
		list<GR_Texture*>::iterator layer_iter;
		vector<SDL_RWops*> resources;
	public:
		int SCREEN_WIDTH;		//画面分辨率 
		int SCREEN_HEIGHT;
		bool quit = false;
		GR_Playable(SDL_Renderer *renderer, int w, int h);
		~GR_Playable();
        int Init();
        int Load();
		Uint32 Loop();
		int Quit();
};


#endif