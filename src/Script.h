#ifndef SCRIPT_H
#define SCRIPT_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Message.h"


/*****************************
#	文件名：	Script.h
#	日期：		2016-08-21
#	版本号：	0.3.0
#	功能：		脚本对象的定义 	
#	mpsk's game engine proj
*****************************/ 
 
class Script
{
	public:
		int Init();
		int Load(char* file);
		//Message Docode(); 
		void Docode(); 
		void Free();
	private:
		//lua_State* lua;
		int linenum;	
		std::ifstream script; 
};


#endif
