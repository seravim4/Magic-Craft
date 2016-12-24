#pragma once

#include <SFML\System\Thread.hpp>
#include <SFML\System\Mutex.hpp>
#include <SFML\System\Lock.hpp>
#include <SfML\System\Clock.hpp>

class ParallelTask
{
public:
	
					ParallelTask();
	void			execute();
	bool			isFinished();
	float			getComplection();

private:

	void			runTask();

private:

	sf::Thread		mThread;
	bool			mFinished;
	sf::Clock		mElapsedTime;
	sf::Mutex		mMutex;
};

