#pragma once
#include "header.h"
#include "Process.h"
#include <ctime>
class Generator
{
private:
	std::vector<Process> lista;
public:
	Generator(int ileProcesow, int minCzas, int maxCzas);
	Generator(std::string file);
	~Generator();

	std::vector<Process> getProcessList();
};

