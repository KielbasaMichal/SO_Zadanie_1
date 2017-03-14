#include "Generator.h"

Generator::Generator(int ileProcesow, int minCzas, int maxCzas)
{
	srand(time(NULL));
	for (int i = 0; i < ileProcesow; i++)
	{
		int czas = rand() % (maxCzas + 1 - minCzas) + minCzas;
		lista.push_back(Process(i, czas));
	}
}

Generator::Generator(std::string filesrc)
{
	std::fstream file;
	file.open(filesrc);
	int ile = 0;
	file >> ile;
	for (int i = 0; i < ile; i++) {
		int a, b, c;
		file >> a >> b >> c;
		lista.push_back(Process(a, b, c));
	}
}

Generator::~Generator()
{
}

std::vector<Process> Generator::getProcessList()
{
	return lista;
}
