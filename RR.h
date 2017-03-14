#pragma once
#include "header.h"
#include "Process.h"

class RR
{
private:
	std::queue<Process> queue;
	std::vector<Process> finishList;
	std::vector<Process> waitList;
	int kwantCzasu;
public:
	RR(std::vector<Process> process);
	~RR();

	void setRotationTime(int time);
	void run();
	void statistic();
	void processList();
};

