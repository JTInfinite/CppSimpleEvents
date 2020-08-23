#include <iostream>
#include "Dispatcher.h"
#include "Event.h"


void Print()
{
	std::cout << "Hello World" << std::endl;
}

void Print2()
{
	std::cout << "Second Hello" << std::endl;
}

int main()
{
	Dispatcher::Subscribe("Test Channel", Print);
	Dispatcher::Subscribe("Test Channel", Print2);
	new Event("Test Event", "Test Channel");
	return 0;
}