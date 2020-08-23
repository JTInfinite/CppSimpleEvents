#include "Event.h"
#include "Dispatcher.h"

Event::Event(std::string name, std::string channel)
{
	m_EventName = name;
	m_Channel = channel;
	Dispatcher::ReceiveEvent(this);
}
