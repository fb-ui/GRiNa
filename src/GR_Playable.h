#ifndef GR_Playable_H
#define GR_Playable_H

#include <vector>

#include "GR_Particle.h"
#include "GR_Button.h"
#include "GR_Background.h"

class GR_Playable
{
	protected:
		SDL_Renderer *renderer;
		SDL_Event event;

		//	Background (we only need one)
		GR_Background *background;

		//	Sprites Vectors
		vector<GR_Button*> buttons;
		vector<GR_Button*>::iterator button_iter;
		vector<GR_Texture*> layer;
		vector<GR_Texture*>::iterator layer_iter;
		vector<GR_ParticleSys*> particles;
		vector<GR_ParticleSys*>::iterator particles_iter;
		//	Resource Vectors
		vector<SDL_RWops*> resources;
	public:
		int SCREEN_WIDTH;		//画面分辨率 
		int SCREEN_HEIGHT;
		bool quit = false;
        int Init();
        int Load();
		Uint32 Loop();
		int Quit();
};


#endif