#pragma once
#include "header.h"

class SJF
{
private:
	std::vector<Process> list;
public:
	SJF(std::vector<Process> list);
	~SJF();

	void run();
	void statistic();
	void processList();
};

