#include <iostream>
#include "GR_Texture.h"
#include "GR_Log.h"

/*****************************
#	文件名：	GR_Texture.cpp
#	日期：		2017-09-01 
#	版本号：	0.4.1
#	功能：		纹理对象实现 
#	mpsk's game engine proj
*****************************/
GR_Texture::GR_Texture(SDL_RWops *src, SDL_Renderer *ren, int id)
{
	this->Load(src, ren);
	this->id = id;
}

void GR_Texture::Load(SDL_RWops *src, SDL_Renderer *ren)
{
	SDL_Surface *image;
	image = IMG_Load_RW(src, 1);
	if(image == NULL)
	{
		GR_LogError(std::cout, "LoadGR_Texture");
	}
	else
	{
		this->texture = SDL_CreateTextureFromSurface(ren, image);
		if(this->texture == NULL)
		{
			GR_LogError(std::cout, "LoadGR_Texture");
			return;
		}
		else
		{
			SDL_QueryTexture(this->texture, NULL, NULL, &dst.w, &dst.h);
		}
		SDL_FreeSurface(image);
	}
	return;
}

void GR_Texture::LoadFromFile(const std::string &file, SDL_Renderer *ren)
{
	this->texture = IMG_LoadTexture(ren, file.c_str());
	if (this->texture == NULL){
		GR_LogError(std::cout, "LoadGR_Texture");
	}
	//renderer = ren;
	SDL_QueryTexture(this->texture, NULL, NULL, &dst.w, &dst.h);
}


void GR_Texture::Free()
{
	//释放纹理
	SDL_DestroyTexture(texture);
}


void GR_Texture::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//设置颜色模式
	SDL_SetTextureColorMod(texture, red, green, blue);
}


void GR_Texture::SetBlendMode(SDL_BlendMode blending)
{
	//设置混合模式
	SDL_SetTextureBlendMode(texture, blending);
}


void GR_Texture::SetAlpha(Uint8 alpha)
{
	//设置不透明度
	SDL_SetTextureAlphaMod(texture, alpha);
}

//将来接入切片clip
//void GR_Texture::Render(int x, int y, SDL_Rect* clip)
void GR_Texture::Render(int x, int y, SDL_Renderer *ren)
{
	dst.x = x;
	dst.y = y;
	SDL_RenderCopy(ren, this->texture, NULL , &dst);
}

void GR_Texture::Render_clip(SDL_Rect dest, SDL_Rect clip, SDL_Renderer *ren)
{
	//SDL_Rect是由点坐标以及纹理宽高组成的结构
	SDL_RenderCopy(ren, this->texture, &clip , &dest);
}

void GR_Texture::Render_clip(int dstX, int dstY, int dstW, int dstH, int srcX, int srcY, int srcW, int srcH, SDL_Renderer *ren)
{
	SDL_Rect dst, src;
	dst.x = dstX;
	dst.y = dstY;
	dst.w = dstW;
	dst.h = dstH;
	src.x = srcX;
	src.y = srcY;
	src.w = srcW;
	src.h = srcH;
	//SDL_Rect是由点坐标以及纹理宽高组成的结构
	SDL_RenderCopy(ren, texture, &src , &dst);
}


void GR_Texture::Render_dst(SDL_Rect dest, SDL_Renderer *ren)
{
	//SDL_Rect是由点坐标以及纹理宽高组成的结构
	SDL_RenderCopy(ren, texture, NULL, &dest);
}


int GR_Texture::GetWidth()
{
	//printf("loaded texture width @%4d.\n", dst.w);
	return dst.w;
}
int GR_Texture::GetHeight()
{
	//printf("loaded texture height @%4d.\n", dst.h);
	return dst.h;
}
