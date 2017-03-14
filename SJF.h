#pragma once
#include "header.h"
#include "Process.h"

class SJF
{
private:
	std::priority_queue<Process> queue;
	std::vector<Process> finishList;
	std::vector<Process> waitList;
public:
	SJF(std::vector<Process> list);
	~SJF();

	void run();
	void statistic();
	void processList();
};

