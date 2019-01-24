#include "GR_Log.h"
#include "../include/SDL.h"
 /*****************************
#	文件名：	GR_Log.cpp 
#	日期：		2016-08-06 
#	版本号：	0.2.6
#	功能：		日志系统 
#	mpsk's game engine proj
*****************************/ 
void GR_LogError(std::ostream &os, const std::string &msg)
{
	os << msg << " error: " << SDL_GetError() << std::endl;
}
