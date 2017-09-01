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
#define	SCRPT_LOAD_BG			0x0001
#define SCRPT_LOAD_PARTCLE		0x0002
#define SCRPT_LOAD_BUTTON 		0x0003
#define SCRPT_LOAD_DIALOG		0x0004
#define SCRPT_ACTION_PLAY		0x1001
#define SCRPT_ACTION_NEXT		0x1002
#define SCRPT_ACTION_ANIMATION	0x1003
#define SCRPT_ACTION_JUMP		0x1004

using namespace std;

class Script
{
	public:
		int Init();
		int Load(const string file);
		//Message Docode(); 
		int Docode(string &s); 
		bool Free();
	private:
		//lua_State* lua;
		int linenum;	
		ifstream script; 
};


#endif
