#pragma once
#include <string>
#include <vector>
#include <map>

class Event;

// Needs to be a singleton
class Dispatcher
{
public:
	Dispatcher(const Dispatcher&) = delete; // This gets rid of the copy constructor so the class cannot be copied
	static Dispatcher& Get()
	{
		static Dispatcher s_Instance;
		return s_Instance;
	};

	static void Subscribe(std::string channel, void(*fn)())
	{
		return Get().Subscribe_Internal(channel, fn);
	};

	static void Publish(std::string channel)
	{
		return Get().Publish_Internal(channel);
	}

	static void ReceiveEvent(Event* event)
	{
		return Get().ReceiveEvent_Internal(event);
	}

private:
	Dispatcher() {}; // Private constructor
	std::map<std::string, std::vector<void (*)()>> m_Subscriptions; // Vector of function pointers to be executer upon event. The keys of the map should be the channel.

private:
	void Subscribe_Internal(std::string channel, void(*fn)());
	void Publish_Internal(std::string channel);
	void ReceiveEvent_Internal(Event* event);
};

