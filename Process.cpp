#include "Process.h"



Process::Process()
{
	id = -1;
	procTime = 0;
	remainingTime = 0;
	waitingTime = 0;
	startTime = 0;
	endTime = 0;
}

Process::Process(int id, int time)
{
	Process::id = id;
	Process::procTime = time;
	Process::remainingTime = time;
	Process::waitingTime = 0;
	Process::startTime = 0;
	Process::endTime = 0;
}

Process::Process(int id, int time, int timeStart)
{
	Process::id = id;
	Process::procTime = time;
	Process::remainingTime = time;
	Process::waitingTime = 0;
	Process::startTime = timeStart;
	Process::endTime = timeStart;
}


Process::~Process()
{
}

void Process::doOnce()
{
	remainingTime--;
}

bool Process::isDone()
{
	return remainingTime < 1;
}

int Process::getStartTime()
{
	return startTime;
}

void Process::setStartTime(int startTime)
{
	Process::startTime = startTime;
}

int Process::getEndTime()
{
	return endTime;
}

void Process::setEndTime(int endTime)
{
	Process::endTime = endTime;
}

int Process::getID()
{
	return id;
}

int Process::getProcTime()
{
	return procTime;
}

int Process::getRemainingTime()
{
	return remainingTime;
}

int Process::getWaitingTime()
{
	return waitingTime;
}

void Process::addWaitingTime(int time)
{
	waitingTime += time;
}

std::ostream & operator<<(std::ostream & os, const Process & dt)
{
	os << dt.id;
	return os;
}

bool operator<(const Process a, const Process b)
{
	return a.procTime > b.procTime;
}

bool operator>(const Process a, const Process b)
{
	return a.procTime > b.procTime;
}