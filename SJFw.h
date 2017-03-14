#pragma once
#include "header.h"
#include "Process.h"

class SJFw
{
private:
	std::priority_queue<Process> queue;
	std::vector<Process> finishList;
	std::vector<Process> waitList;
public:
	SJFw(std::vector<Process> list);
	~SJFw();

	void run();
	void statistic();
	void processList();
};

