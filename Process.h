#pragma once
#include <iostream>

class Process
{
private:
	int id;
	int procTime;
	int remainingTime;
	int waitingTime;

public:
	Process();
	Process(int id, int time);
	~Process();
	
	void doOnce();
	bool isDone();

	int getID();
	int getProcTime();
	int getRemainingTime();
	int getWaitingTime();
	void addWaitingTime(int time);
	friend std::ostream& operator<<(std::ostream& os, const Process& dt);
	friend bool operator<(const Process a, const Process b);
};

