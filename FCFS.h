#pragma once
#include "header.h"

class FCFS
{
private:
	std::vector <Process> list;
public:
	FCFS(std::vector <Process> process);
	~FCFS();

	void run();
	void statictic();
	void processList();
};

