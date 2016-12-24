#include "Game.h"
#include <exception>

int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (std::exception& msg)
	{
		std::cout << msg.what() << std::endl;
	}
}