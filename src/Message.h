#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <vector>

/*****************************
#	文件名：	Message.h 
#	日期：		2016-08-06 
#	版本号：	0.2.6
#	功能：		消息队列的定义 
#	mpsk's game engine proj
*****************************/ 


//AABBCCDDEE	
//A表示相关宏种类
//B表示相关信息功能
//C表示操作对象 
#define MSG_TESTIO_SHOWMESSAGE	1000000
#define	MSG_VIDEO_RENDER_BG00 	1010100
#define MSG_AUDIO_PLAY_BGM00	1020100
#define MSG_STAGE_SHOW_SCRIPT	1030100



typedef struct
{
	int	msg_type;
	std::string msg_content;
}Message; 


class Messages
{
	public:
		void Push(int msgtype, std::string msg); 
		void Free(); 
		Message Poll();
	private:
		std::vector<Message> messages;
};

#endif
