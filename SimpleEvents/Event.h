#pragma once
#include<string>
#include<vector>

class Dispatcher;

class Event
{
public:
	Event(); // Perhaps in the initialisation on the event it should "broadcast" itself - in essence send it to the dispatcher
	~Event();
	std::string ToString() { return m_EventName; };


private:
	std::string m_EventName;
};

