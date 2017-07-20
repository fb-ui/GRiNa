#include <cstdlib>
#include <vector>
#include "Texture.h"

#define BOMB_COST		10			//	How many score does bomb cost

#define SPD_MAX_X		5			//	Maxium Speed in X axis
#define SPD_MAX_Y		5			//	Maxium Speed in Y axis
#define SPD_DEC			0.05		//	Step value (Constant accelerate rate in abstract game time)
#define SPD_MIN			0.3			//	Minimal Speed
#define SPD_RATIO		1			//	Time Ratio (to enbalance the difficulty)
#define SPD_CHASE		0.2			//	Ratio describing the chasing speed
#define SPD_EVADE		0.1			//	Ratio describing the evading speed
#define SPD_INIT_RAND_Y	

#define SPEED_RATIO		1

#define HURT            -1
#define SCORE           1
#define ZERO            0

#define BUFFSIZE 		25		//	buffsize for string
#define RES_FISHES 		4		//	Amount of the npc fishes
#define TIME			3
//#define GAME_TIME		99		//	sec
#define LOCK_RATE		10		//	ms
#define GOD_TIME		50		//	ms
#define FISH_FREQ		10		//	Triggered every XX ms
#define FISH_QUAT		2		//	Push XX fishes every time


struct fish
{
	float x;				//	Node fish's position in X
	float y;				//	Node fish's position in Y
	float s_x;				//	Node fish's speed in X
	float s_y;				//	Node fish's speed in Y
	float level;			//	Node fish's level(judge score or hurt)

	int res_num;			//	Alternate texture amount
	int flag;				//	From Left or Right
};

class Fishes
{
    private:
        std::vector<fish> FishList;
        std::vector<fish>::iterator iter;
        Texture npc_fishes[RES_FISHES];		//	NPC Texture Array

        SDL_Renderer *ren;

        int SCREEN_W, SCREEN_H;
        int Init();
    public:
        Fishes(int SCREEN_W, int SCREEN_H, SDL_Renderer *ren)
        {
            this->SCREEN_W = SCREEN_W;
            this->SCREEN_H = SCREEN_H;
            this->ren = ren;
            this->npc_fishes[0].Load("Resource/fish.png", this->ren);
            this->npc_fishes[1].Load("Resource/fish.png", this->ren);
            this->npc_fishes[2].Load("Resource/fish.png", this->ren);
            this->npc_fishes[3].Load("Resource/fish.png", this->ren);
        }
        int Add(float level);
        int fish_judge(int mouse_x, int mouse_y, float level);
        int Render(int mouse_x, int mouse_y);
        int Clear();
};
