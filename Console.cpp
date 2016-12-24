#include "Console.h"



Console::Console()
{
}


Console::~Console()
{
}

void Console::Info(const char* text)
{
	std::cout << "[INFO] " << text << std::endl;
}

void Console::Err(const char* text)
{
	std::cout << "[ERROR] " << text << std::endl;
}
