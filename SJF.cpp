#include "SJF.h"



SJF::SJF(std::vector<Process> lista)
{
	for (Process e : lista) {
		if (e.getStartTime() == 0) {
			queue.push(e);
		}
		else {
			waitList.push_back(e);
		}
	}
	//Sortujemy wzglêdem czasu dodania
	std::sort(waitList.begin(), waitList.end(), [](Process& a, Process& b) {
		return a.getStartTime() < b.getStartTime(); });
}


SJF::~SJF()
{
}

void SJF::run()
{
	int time = 0;
	while (!queue.empty() || !waitList.empty())
	{
		if (!queue.empty()) {
			Process tmp = queue.top();
			queue.pop();
			tmp.setStartTime(time);
			tmp.addWaitingTime(tmp.getStartTime() - tmp.getEndTime());
			while (!tmp.isDone())
			{
				tmp.doOnce();
				time++;
			}
			//Pêtla zakoñczona a zatem proces wykonany
			finishList.push_back(tmp);
		}
		else {
			time++;
		}
		for (;!waitList.empty() && time >= waitList[0].getStartTime();)
		{
			queue.push(waitList[0]);
			waitList.erase(waitList.begin());
		}
	}
}

void SJF::statistic()
{
	double sumWaitingTime = 0;
	for (unsigned int i = 0; i < finishList.size(); i++)
	{
		sumWaitingTime += finishList[i].getWaitingTime();
	}
	std::cout << "Sredni czas oczekiwania dla SJF wynosil: " << sumWaitingTime / finishList.size() << std::endl;
}

void SJF::processList()
{
	printf("%-20s %-20s %-20s\n", "ID", "Czas procesu", "Czas oczekiwania");
	for (unsigned int i = 0; i < finishList.size(); i++)
	{
		Process tmp = finishList.at(i);
		printf("%-20d %-20d %-20d\n", tmp.getID(), tmp.getProcTime(), tmp.getWaitingTime());
	}
}
