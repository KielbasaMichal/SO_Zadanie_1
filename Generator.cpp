#include "Generator.h"

Generator::Generator(int ileProcesow, int minCzas, int maxCzas)
{
	srand(time(NULL));
	for (int i = 0; i < ileProcesow; i++)
	{
		int czas = rand() % (maxCzas + 1 - minCzas) + minCzas;
		std::cout << czas << std::endl;
		lista.push_back(Process(i, czas));
	}
}

Generator::Generator(std::string file)
{

}

Generator::~Generator()
{
}

std::vector<Process> Generator::getProcessList()
{
	return lista;
}
