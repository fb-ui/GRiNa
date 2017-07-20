#include "Fish.h"

int Fishes::Add(float level)
{
    fish f;
    f.s_x = 0;
	if (rand() % 2)
	{
		f.s_y = (rand() % SPD_MAX_Y) / 2;
	}
	else
	{
		f.s_y = -(rand() % SPD_MAX_Y) / 2;
	}
	f.y = (int)rand() % SCREEN_H;
	f.level = rand() % 10 / 7 + level - (0.5 / level);
	f.res_num = rand() % RES_FISHES;
	if (rand() % 2)
	{
		f.x = SCREEN_W - level * this->npc_fishes[f.res_num].GetWidth() / 4;
		f.flag = 1;
	}
	else
	{
		f.x = -level * this->npc_fishes[f.res_num].GetWidth() / 4;
		f.flag = 2;
	}
    this->FishList.push_back(f);
    return 0;
}

int Fishes::fish_judge(int mouse_x, int mouse_y, float level)
{
    std::vector<fish>::iterator p;
    for(p=FishList.begin();p!=FishList.end();p++)
    {
        if	  ((p->x + ((p->level)* this->npc_fishes[p->res_num].GetWidth() / 4) <= mouse_x + (3 * level * this->npc_fishes[p->res_num].GetWidth() / 16) &&
				p->x + ((p->level)* this->npc_fishes[p->res_num].GetWidth() / 4) >= mouse_x - (3 * level * this->npc_fishes[p->res_num].GetWidth() / 16) &&
				p->y + ((p->level)* this->npc_fishes[p->res_num].GetHeight() / 2) <= mouse_y + (3 * level * this->npc_fishes[p->res_num].GetHeight() / 8) &&
				p->y + ((p->level)* this->npc_fishes[p->res_num].GetHeight() / 2) >= mouse_y - (3 * level * this->npc_fishes[p->res_num].GetHeight() / 8)))
		{
			if (p->level > level)
			{
                return HURT;
			}
			else
			{
                return SCORE;
			}
		}
		else if (p->x > SCREEN_W + ((p->level)* this->npc_fishes[p->res_num].GetWidth()) || p->x < -((p->level)* this->npc_fishes[p->res_num].GetWidth()) || 
				p->y > SCREEN_H + p->y + ((p->level)* this->npc_fishes[p->res_num].GetHeight()) || p->y < -p->y  -((p->level)* this->npc_fishes[p->res_num].GetHeight()))
		{
			p = this->FishList.erase(p);
		}
    }
    return ZERO;
}

int Fishes::Render(int mouse_x, int mouse_y)
{
    std::vector<fish>::iterator p;
    int tx = 0;
	if (p->flag == 1)
	{
	    tx = 0;
	}
	else
	{
		tx = this->npc_fishes[0].GetWidth() / 2;
	}
    for(p=FishList.begin();p!=FishList.end();p++)
    {
        npc_fishes[p->res_num].Render(p->x, p->y, this->ren);
        p->y += p->s_y;
		if (p->flag == 1)
		{
			p->x -= p->s_x;
			if (p->s_x <= 0)
			{
				p->s_x += rand() % (SPD_MAX_X + 1) / ((float)SPEED_RATIO / 10);
			}
			else
			{
				p->s_x -= SPD_DEC / ((float)SPEED_RATIO / 10);
			}
		}
		else if (p->flag == 2)
		{
			p->x += p->s_x;
			if (p->s_x <= 0)
			{
				p->s_x += rand() % (SPD_MAX_X + 1) / ((float)SPEED_RATIO / 10);
			}
			else
			{
				p->s_x -= SPD_DEC / ((float)SPEED_RATIO / 10);
			}
		}
		{
			if (p->s_y > SPD_MIN)
			{
				p->s_y -= SPD_DEC / ((float)SPEED_RATIO / 10);
			}
			else if (p->s_y < -SPD_MIN)
			{
				p->s_y += SPD_DEC / ((float)SPEED_RATIO / 10);
			}
			else
			{
				if (rand() % 2)
				{
					p->s_y = -(rand() % SPD_MAX_Y) / ((float)SPEED_RATIO / 10);
				}
				else
				{
					p->s_y = (rand() % SPD_MAX_Y) / ((float)SPEED_RATIO / 10);
				}
			}
		}
		/*{	
			if (p->level > game.level)
			{
				p->s_x += SPD_CHASE * 0.001 * (mouse_x - p->x);
				p->s_y += SPD_CHASE * 0.001 * (mouse_y - p->y);
			}	
			if (p->level <= game.level)
			{
				if ((mouse_x - p->x) > game.player_fish.getwidth() / 2 + 10 || (mouse_x - p->x) < game.player_fish.getwidth() / 2 - 10)
					p->s_x -= SPD_EVADE * 15 / (2 * (mouse_x - p->x));
				else
					p->s_x -= SPD_EVADE * 15 / (game.player_fish.getwidth());
				if ((mouse_y - p->y) > game.player_fish.getheight() / 2 + 10 || (mouse_y - p->y) < -game.player_fish.getheight() / 2 - 10)
					p->s_y -= SPD_EVADE * 15 / (2 * (mouse_y - p->y));
				else
					p->s_y -= SPD_EVADE * 15 / (game.player_fish.getheight());
			}
		}*/
    }
    return 0;
}

int Fishes::Clear()
{
    FishList.clear();
    return 0;
}

