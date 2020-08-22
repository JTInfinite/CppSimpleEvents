#include <iostream>
#include "Dispatcher.h"


void Dispatcher::Subscribe_Internal(std::string channel, void(*fn)())
{
	if (m_Subscriptions.find(channel) == m_Subscriptions.end()) {
		// not found
		m_Subscriptions.insert(std::pair<std::string, std::vector<void(*)()>>(channel, {}));
		m_Subscriptions[channel].emplace_back(fn);
	}
	else {
		// found
		m_Subscriptions[channel].emplace_back(fn);
	}
}

void Dispatcher::Publish_Internal(std::string channel)
{
	for (const auto &p : m_Subscriptions) // p for pair
	{
		std::cout << p.first << std::endl;
		for (auto fn : p.second)
		{
			(*fn)();
		}
	}
}
