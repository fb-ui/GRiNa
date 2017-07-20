#include "Message.h"
 
 /*****************************
#	文件名：	Message.cpp
#	日期：		2016-08-06 
#	版本号：	0.2.6
#	功能：		消息队列的实现 
#	mpsk's game engine proj
*****************************/ 
 
void Messages::Push(int msgtype, std::string msg)
{
	Message message;
	message.msg_type = msgtype;
	message.msg_content = msg;
	messages.push_back(message);
}


void Messages::Free()
{
	messages.clear();
}


Message Messages::Poll()
{
	Message tmp;
	std::vector<Message>::iterator iter = messages.begin();
	tmp = *iter;
	iter = messages.erase(iter);
	return tmp;
}
