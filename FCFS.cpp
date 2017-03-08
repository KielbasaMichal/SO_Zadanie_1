#include "FCFS.h"

FCFS::FCFS(std::vector<Process> process)
{
	list = process;
}

FCFS::~FCFS()
{
}

void FCFS::run()
{
	int time = 0;
	for (int i = 0; i < list.size(); i++)
	{
		//std::cout << "Wykonywanie procesu o ID: " << list[i] << std::endl;
		while (!list[i].isDone())
		{
			list[i].doOnce();
			//std::cout << "\tpozostaly czas: " << list[i].getRemainingTime() << std::endl;
		}
		list[i].addWaitingTime(time);
		time = list[i].getProcTime() + list[i].getWaitingTime();
	}
}

void FCFS::statictic()
{
	int sumWaitingTime = 0;
	std::cout << "Czas oczekiwania na wykonianie poszczegolnych zadan wynosily kolejno:\n";
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list[i].getWaitingTime() << " ";
		sumWaitingTime += list[i].getWaitingTime();
	}
	std::cout << std::endl << "Sredni czas oczekiwania wynosil: " << sumWaitingTime / list.size() << std::endl;
}

void FCFS::processList()
{
	printf("%-20s %-20s %-20s\n", "ID", "Czas procesu", "Czas oczekiwania");
	for (int i = 0; i < list.size(); i++)
	{
		Process tmp = list.at(i);
		printf("%-20d %-20d %-20d\n", tmp.getID(), tmp.getProcTime(), tmp.getWaitingTime());
	}
}
