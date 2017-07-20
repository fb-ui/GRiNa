#include "Script.h"
#define DEBUG

/*****************************
#	文件名：	Script.cpp
#	日期：		2016-08-23
#	版本号：	0.3.0
#	功能：		脚本对象的实现	
#	mpsk's game engine proj
*****************************/ 

int Script::Init()
{

#ifdef DEBUG
    std::cout << "lua libs loaded..." << std::endl;
#endif
    return 0;
}

int Script::Load(char* file)
{

#ifdef DEBUG
    std::cout << "lua file loaded..." << std::endl;
#endif
    return 0;
}

void Script::Docode()
{

#ifdef DEBUG
    std::cout << "lua code done!" << std::endl;
#endif
}

void Script::Free()
{
    
}

