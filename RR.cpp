#include "RR.h"

RR::RR(std::vector<Process> process, int kwant)
{
	for (const auto e : process)
		queue.push(e);
	kwantCzasu = kwant;
}


RR::~RR()
{
}

void RR::run()
{
	int time = 0;
	while (!queue.empty())
	{
		Process tmp = queue.front();
		queue.pop();
		tmp.setStartTime(time);
		tmp.addWaitingTime(tmp.getStartTime() - tmp.getEndTime());
		for (int i = 0; i < kwantCzasu && !tmp.isDone(); i++)
		{
			tmp.doOnce();
			time++;
		}
		tmp.setEndTime(time);
		if (tmp.isDone()) {
			finishList.push_back(tmp);
		}
		else {
			queue.push(tmp);
		}
	}
}

void RR::statistic()
{
	double sumWaitingTime = 0;
	for (int i = 0; i < finishList.size(); i++)
	{
		sumWaitingTime += finishList[i].getWaitingTime();
	}
	std::cout << std::endl << "Sredni czas oczekiwania wynosil: " << sumWaitingTime / finishList.size() << std::endl;
}

void RR::processList()
{
	printf("%-20s %-20s %-20s\n", "ID", "Czas procesu", "Czas oczekiwania");
	for (int i = 0; i < finishList.size(); i++)
	{
		Process tmp = finishList.at(i);
		printf("%-20d %-20d %-20d\n", tmp.getID(), tmp.getProcTime(), tmp.getWaitingTime());
	}
}
