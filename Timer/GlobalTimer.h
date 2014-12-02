#ifndef GLOBALTIMER_H
#define GLOBALTIMER_H

// Singleton instance of a global timer

class globalTimer
{
public:

	// create it
	static void create()
	{
		privGetInstance()->privCreate();
	};

	// get updated time
	static float getTimerInSec()
	{
		return privGetInstance()->privGetTimerInSec();
	};

private:

	timer	gTimer;

	static globalTimer *privGetInstance()
	{
		static globalTimer instance;
		return &instance;
	};

	void privCreate()
	{
		gTimer.tic();
	};

	float privGetTimerInSec()
	{
		gTimer.toc();
		return gTimer.timeInSeconds();
	};

};


#endif