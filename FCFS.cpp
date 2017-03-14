#include "FCFS.h"

FCFS::FCFS(std::vector<Process> process)
{
	for (Process e : process) {
		if (e.getEndTime() == 0) {
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

FCFS::~FCFS()
{
}

void FCFS::run()
{
	int time = 0;
	int lastTime = 0;
	int lastExec = 0;
	while(!queue.empty())
	{
		if (!queue.empty() || !waitList.empty()) {
			Process tmp = queue.front();
			queue.pop();
			tmp.setStartTime(time);
			tmp.addWaitingTime(time - tmp.getEndTime());
			while (!tmp.isDone())
			{
				tmp.doOnce();
				time++;
			}
			//Pêtla zakoñczona a zatem proces wykonany
			finishList.push_back(tmp);
			lastTime = tmp.getWaitingTime();
			lastExec = tmp.getProcTime();
		}
		else {
			time++;
		}
		//Sprawdzamy czy pojawi³y siê jakieœ nowe procesy podczas wykonywania
		for (int i = 0; !waitList.empty() && time >= waitList[i].getStartTime(); )
		{
			queue.push(waitList[i]);
			waitList.erase(waitList.begin());
		}
	}
}

void FCFS::statictic()
{
	double sumWaitingTime = 0;
	for (unsigned int i = 0; i < finishList.size(); i++)
	{
		sumWaitingTime += finishList[i].getWaitingTime();
	}
	std::cout << "Sredni czas oczekiwania dla FCFS wynosil: " << sumWaitingTime / finishList.size() << std::endl;
}

void FCFS::processList()
{
	printf("%-20s %-20s %-20s\n", "ID", "Czas procesu", "Czas oczekiwania");
	for (unsigned int i = 0; i < finishList.size(); i++)
	{
		Process tmp = finishList.at(i);
		printf("%-20d %-20d %-20d\n", tmp.getID(), tmp.getProcTime(), tmp.getWaitingTime());
	}
}
