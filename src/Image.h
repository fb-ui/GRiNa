#ifndef IMAGE_H
#define IMAGE_H
#include "Texture.h"

/*****************************
#	文件名：	Background.h
#	日期：		2017-1-17
#	版本号：	0.3.2
#	功能：		图像对象抽象类 
#	mpsk's game engine proj
*****************************/ 

class Image
{
    public:
        void LoadTexture();
        void Render();
        void Free();
    private:
        Texture tex;
};


#endif
