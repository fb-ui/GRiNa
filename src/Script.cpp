#include "Script.h"
#define DEBUG
using namespace std;

/*****************************
#	文件名：	Script.cpp
#	日期：		2016-08-23
#	版本号：	0.3.0
#	功能：		脚本对象的实现	
#	mpsk's game engine proj
*****************************/ 

int Script::Init()
{
    return 0;
}

int Script::Load(const string file)
{
    this->script.open(file, ifstream::binary);
    return 0;
}

int Script::Docode(string &s)
{
    //  执行一行以后返回下一行。
    getline(this->script, s);
    cout << s << endl;
    if(this->script.eof())
        return -1;
    return 0;
}

bool Script::Free()
{
    this->script.clear();
    this->script.close();
    return true;
}

