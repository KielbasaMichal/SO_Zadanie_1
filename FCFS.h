#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Process.h"

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

