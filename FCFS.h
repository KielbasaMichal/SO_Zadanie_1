#pragma once
#include <iostream>
#include <vector>
#include "Process.h"

class FCFS
{
private:
	std::queue<Process> queue;
	std::vector<Process> finishList;
	std::vector<Process> waitList;
public:
	FCFS(std::vector <Process> process);
	~FCFS();

	void run();
	void statictic();
	void processList();
};

