#include "GR_Particle.h"
#include "GR_Log.h"
#include <iostream>

/*****************************
#	文件名：	Particle.cpp 
#	日期：		2016-08-05 
#	版本号：	0.2.4 
#	功能：		粒子系统功能实现 
#	mpsk's game engine proj
*****************************/ 

GR_ParticleSys::GR_ParticleSys(int num, int life, int speed_x, int speed_y)
{
	this->ptnum = num;
	this->ptlife = life;
	this->init_speed.x = speed_x;
	this->init_speed.y = speed_y;
	this->particles = new std::vector<Particle>;
}

GR_ParticleSys::~GR_ParticleSys()
{
	this->Free();
}


/*--------------------------
//向粒子栈压入固定数目的元素 
*/
void GR_ParticleSys::Push(int num, int life, Vector2D speed)
{
	//将粒子压入栈 (按照数量压栈） 
	for (int i = 1; i <= num; i++ )
	{
		Particle p;
		p.speed.x = speed.x + ptdispersion*(float(rand()%1000)/1000) - ptdispersion/2;
		p.speed.y = speed.y + ptdispersion*(float(rand()%1000)/1000) - ptdispersion/2;
		p.position.x = rand()%ptwidth;
		p.position.y = 0;
		p.life = ptlife;
		p.age = 1;
		this->particles->push_back(p);
	}
}

void GR_ParticleSys::SetLife(int life)
{
	for(iter=this->particles->begin();iter!=this->particles->end();iter++)
	{
		iter->life = life;
	}
}

void GR_ParticleSys::SetKinematic(int _width, int _height, int _dispersion, Vector2D _gravity)
{
	ptwidth = _width;
	ptheight = _height;
	ptdispersion = _dispersion;
	gravity = _gravity;
}


void GR_ParticleSys::SetColor(Uint8 Red, Uint8 Green, Uint8 Blue){this->tex->SetColor(Red, Green, Blue);}
void GR_ParticleSys::SetAlpha(Uint8 alpha){this->tex->SetAlpha(alpha);}


void GR_ParticleSys::Render_Central(int x, int y, SDL_Renderer * ren)
{
	this->Push(this->ptnum, this->ptlife, this->init_speed);
	for(iter=this->particles->begin();iter!=this->particles->end();iter++)
	{
		if(iter->age >= iter->life)
		{
			//弹出第一个元素
			iter = this->particles->erase(iter); 
		}
		//计算速度与位置 
		iter->speed.x = iter->speed.x + gravity.x*iter->age;
		iter->speed.y = iter->speed.y + gravity.y*iter->age;
		iter->position.x =iter->speed.x*iter->age + gravity.x*(iter->age^2)/2;
		iter->position.y =iter->speed.y*iter->age + gravity.y*(iter->age^2)/2;
		//将栈指针指向的元素压入位置栈中
		iter->age += 1;
		this->tex->Render(x + iter->position.x, y + iter->position.y, ren);
	}
}
void GR_ParticleSys::Free()
{
	this->particles->clear();
	this->tex->Free();
	delete this->tex;
	delete this->particles;
	std::cout << "GR_ParticleSys is terminated" << std::endl;
}
