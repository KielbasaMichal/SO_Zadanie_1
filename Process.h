#pragma once
#include "header.h"

class Process
{
private:
	int id;
	int procTime;
	int remainingTime;
	int waitingTime;
	int startTime;
	int endTime;

public:
	Process();
	Process(int id, int time);
	Process(int id, int time, int timeStart);
	~Process();
	
	void doOnce();
	bool isDone();

	int getStartTime();
	void setStartTime(int startTime);
	int getEndTime();
	void setEndTime(int endTime);
	int getID();
	int getProcTime();
	int getRemainingTime();
	int getWaitingTime();
	void addWaitingTime(int time);
	friend std::ostream& operator<<(std::ostream& os, const Process& dt);
	friend bool operator<(const Process a, const Process b);
	friend bool operator>(const Process a, const Process b);
};

