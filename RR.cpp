#include "RR.h"


RR::RR(std::vector<Process> process)
{
	int sredni = 0;
	for (Process e : process) {
		sredni += e.getProcTime();
		if (e.getStartTime() == 0) {
			queue.push(e);
		}
		else {
			waitList.push_back(e);
		}
	}
	std::sort(waitList.begin(), waitList.end(), [](Process& a, Process& b) {
		return a.getStartTime() < b.getStartTime(); });
	
	//Kwant ustawiany standardowo na sredni czas wykonywania procesu
	kwantCzasu = sredni/process.size();
}


RR::~RR()
{
}

void RR::setRotationTime(int time)
{
	kwantCzasu = time;
}

void RR::run()
{
	int time = 0;
	while (!queue.empty() || !waitList.empty())
	{
		if (!queue.empty()) {
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
		else {
			time++;
		}
		for (int i = 0; !waitList.empty() && time >= waitList[i].getStartTime(); )
		{
			queue.push(waitList[i]);
			waitList.erase(waitList.begin());
		}
	}
}

void RR::statistic()
{
	double sumWaitingTime = 0;
	for (unsigned int i = 0; i < finishList.size(); i++)
	{
		sumWaitingTime += finishList[i].getWaitingTime();
	}
	std::cout << "Sredni czas oczekiwania dla rotacyjnego wynosil: " << sumWaitingTime / finishList.size() << ", dla kwantu czasu wynoszacego: " << kwantCzasu << std::endl;
}

void RR::processList()
{
	printf("%-20s %-20s %-20s\n", "ID", "Czas procesu", "Czas oczekiwania");
	for (unsigned int i = 0; i < finishList.size(); i++)
	{
		Process tmp = finishList.at(i);
		printf("%-20d %-20d %-20d\n", tmp.getID(), tmp.getProcTime(), tmp.getWaitingTime());
	}
}
