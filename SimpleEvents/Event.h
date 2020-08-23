#pragma once
#include<string>
#include<vector>

class Dispatcher;

class Event
{
public:
	Event(std::string name, std::string channel); // Perhaps in the initialisation on the event it should "broadcast" itself - in essence send it to the dispatcher
	~Event();
	std::string ToString() { return m_EventName; };
	std::string GetChannel() { return m_Channel; };


private:
	std::string m_EventName;
	std::string m_Channel;
};

