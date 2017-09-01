#ifndef TEXTURE_H
#define TEXTURE_H

#include "../include/SDL.h"
#include "../include/SDL_image.h"
#include "Vector2D.h"
#include <string>

/*****************************
#	文件名：	Texture.h 
#	日期：		2016-12-28 
#	版本号：	0.3.1
#	功能：		纹理对象抽象 
#	mpsk's game engine proj
*****************************/ 



class Texture
{
	public:
		void Load(SDL_RWops *src, SDL_Renderer *ren);

		void LoadFromFile(const std::string &file, SDL_Renderer *ren);
		//释放SDL_Texture对象
		void Free();
		//设定颜色模式
		void SetColor(Uint8 red, Uint8 green, Uint8 blue);
		//设定混合模式
		void SetBlendMode(SDL_BlendMode blending);
		//设定透明度alpha值
		void SetAlpha(Uint8 alpha);
		//简单定比渲染函数
		void Render(int x, int y, SDL_Renderer *ren);
		//切片渲染
		void Render_clip(SDL_Rect dest, SDL_Rect clip, SDL_Renderer *ren);
		void Render_clip(int dstX, int dstY, int dstW, int dstH, int srcX, int srcY, int srcW, int srcH, SDL_Renderer *ren);
		//标定渲染
		void Render_dst(SDL_Rect dest, SDL_Renderer *ren);
		int GetWidth();
		int GetHeight();
	private:
		//纹理顶点位置
		SDL_Rect dst;
		SDL_Texture *texture;
};

#endif
