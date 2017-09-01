#include "Background.h"

/*****************************
#	文件名：	Background.cpp
#	日期：		2017-1-17
#	版本号：	0.3.2
#	功能：		背景对象实现
#	mpsk's game engine proj
*****************************/ 

Background::Background()
{
    this->type = BG_FLAT;
}

Background::Background(Uint32 type)
{
    this->type = type;
}

void Background::LoadTexture(SDL_RWops *src, SDL_Renderer *ren){this->tex.Load(src, ren);}

void Background::Render(int Screen_w, int Screen_h, SDL_Renderer *ren)
{
    if(this->type == BG_STITCH)
    {
        //要使用平铺显示背景图片
        this->dst.x = 0;
        this->dst.y = 0;
        this->dst.w = Screen_w;
        this->dst.h = Screen_h;
        this->tex.Render_dst(dst, ren);
    }
    else if(this->type == BG_FLAT)
    {
        for (int j = 0 ; Screen_w >= j; j += this->tex.GetWidth() )
        {
            for (int k = 0; Screen_h >= k; k += this->tex.GetHeight())
            {
                this->tex.Render(j, k, ren);
            } 	
        }
    }
}

void Background::Free(){this->tex.Free();}