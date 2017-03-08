#include <iostream>
#include "header.h"

using namespace std;

int main()
{
	std::vector<Process> data;
	data.push_back(Process(0, 21));
	data.push_back(Process(1, 6));
	data.push_back(Process(2, 3));

	//Algorytm FCFS
	FCFS test(data);
	test.run();
	test.processList();
	test.statictic();

	cout << endl;
	//Algorytm SJF
	SJF sjf(data);
	sjf.run();
	sjf.processList();
	sjf.statistic();

	int a;
	cin >> a;
}