#pragma once
#include "header.h"

class RR
{
private:
	std::queue<Process> queue;
	std::vector<Process> finishList;
	int kwantCzasu;
public:
	RR(std::vector<Process> process, int kwant);
	~RR();

	void run();
	void statistic();
	void processList();
};

