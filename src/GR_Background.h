#ifndef GR_Background_H
#define GR_Background_H

#include "GR_Texture.h"
#include "GR_Element.h"

/*****************************
#	文件名：	GR_Background.h
#	日期：		2017-1-17
#	版本号：	0.3.2
#	功能：		背景对象 
#	mpsk's game engine proj
*****************************/ 

//  拉伸  
#define BG_STITCH   0x1000
//  平铺
#define BG_FLAT     0x1001

class GR_Background: public GR_Element 
{
    public:
        GR_Background();
        GR_Background(Uint32 type);
        void Render(int Screen_w, int Screen_h, SDL_Renderer *ren);
};

#endif