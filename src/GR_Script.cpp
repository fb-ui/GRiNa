#include "GR_Script.h"
#define DEBUG

/*****************************
#	文件名：	Script.cpp
#	日期：		2016-08-23
#	版本号：	0.3.0
#	功能：		脚本对象的实现	
#	mpsk's game engine proj
*****************************/ 

int GR_Script::Init()
{
    return 0;
}

int GR_Script::Load(const std::string file)
{
    this->script.open(file, std::ifstream::binary);
    if(this->script.is_open())
        return 0;
    else
        return -1;
}

int GR_Script::Docode(std::string &s)
{
    if(this->script.eof())
        return -1;
    //  执行一行以后返回下一行。
    this->script >> s;
    //getline(this->script, s);
    //cout << s << endl;
    return 0;
}

bool GR_Script::Free()
{
    this->script.clear();
    this->script.close();
    return true;
}

