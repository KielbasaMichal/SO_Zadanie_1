#include "header.h"
#include "Process.h"
#include "FCFS.h"
#include "SJF.h"
#include "SJFw.h"
#include "RR.h" 
#include "Generator.h"

//https://www.ii.pwr.edu.pl/~juszczyszyn/so.htm

void printMenu();

using namespace std;

int main()
{
	std::vector<Process> data;
	data = Generator(50, 5, 100).getProcessList();
	/*data.push_back(Process(0, 21));
	data.push_back(Process(1, 6));
	data.push_back(Process(2, 3));
	*/
	int kwantCzasu = 7;
	int choose = 0;
	while (choose != 5)
	{
		printMenu();
		cin >> choose;
		cout << endl;

		switch (choose)
		{
		case 1:
		{
			//Algorytm FCFS
			cout << "Algorytm FCFS\n";
			FCFS fcfs(data);
			fcfs.run();
			fcfs.processList();
			fcfs.statictic();
			break;
		}
		case 2:
		{
			//Algorytm SJF
			cout << "Algorytm SJF\n";
			SJF sjf(data);
			sjf.run();
			sjf.processList();
			sjf.statistic();
			break;
		}
		case 3:
		{
			//Algorytm RR
			cout << "Algorytm RR\n";
			RR rr(data, kwantCzasu);
			rr.run();
			rr.processList();
			rr.statistic();
			break;
		}
		case 4:
		{
			//Konfiguracja TODO...
			cout << "Aktualny kwant czasu wynosi: " << kwantCzasu << "Podaj nowa wartosc: ";
			cin >> kwantCzasu;
			break;
		}
		default:
			break;
		}
	}
}

void printMenu()
{
	cout << "====== MENU WYBORU ======\n"
		<< "1. Algorytm FCFS\n"
		<< "2. Algorytm SJF\n"
		<< "3. Algorytm RR\n"
		<< "4. Konfiguracja\n"
		<< "5. Wyjscie\n"
		<< "=========================\n"
		<< "Twoj wybor to: ";
}