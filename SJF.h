#pragma once
#include "header.h"
#include "Process.h"

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

