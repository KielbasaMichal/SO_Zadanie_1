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
	data = Generator("less.txt").getProcessList();
	//data = Generator("more.txt").getProcessList();
	//data = Generator("onebig.txt").getProcessList();
	/*data.push_back(Process(0, 21, 0));
	data.push_back(Process(1, 3, 2));
	data.push_back(Process(2, 17, 4));
	data.push_back(Process(3, 13, 8));
	data.push_back(Process(4, 15, 4));
	data.push_back(Process(5, 7, 20));
	*/
	
	int kwantCzasu = -1;
	int choose = 0;
	while (choose != 7)
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
			cout << endl;
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
			cout << endl;
			break;
		}
		case 3:
		{
			//Algorytm SJFw
			cout << "Algorytm SJFw\n";
			SJFw sjfw(data);
			sjfw.run();
			sjfw.processList();
			sjfw.statistic();
			cout << endl;
			break;
		}
		case 4:
		{
			//Algorytm RR
			cout << "Algorytm RR\n";
			RR rr(data);
			if (kwantCzasu != -1) {
				rr.setRotationTime(kwantCzasu);
			}
			rr.run();
			rr.processList();
			rr.statistic();
			cout << endl;
			break;
		}
		case 5:
		{
			cout << "W kolejce bylo: " << data.size() << " procesow\n";
			FCFS fcfs(data);
			fcfs.run();
			fcfs.statictic();
			SJF sjf(data);
			sjf.run();
			sjf.statistic();
			SJFw sjfw(data);
			sjfw.run();
			sjfw.statistic();
			RR rr(data);
			if (kwantCzasu != -1) {
				rr.setRotationTime(kwantCzasu);
			}
			rr.run();
			rr.statistic();
			cout << endl;
			break;
		}
		case 6:
		{
			char a = 'f';
			cout << "\ta. Zmiana kwantu czasu\n"
				<< "\tb. Wczytaj plik less.txt\n"
				<< "\tc  Wczytaj plik more.txt\n"
				<< "\td. Wczytaj plik onebig.txt\n"
				<< "\te. Wlasny...\n"
				<< "\tf. Wroc\n"
				<< "=====================================\n"
				<< "Twoj wybor:";
			cin >> a;
			switch (a)
			{
			case 'a':
				cout << "Aktualny kwant czasu wynosi: " << kwantCzasu << "\nPodaj nowa wartosc (-1 dla automatyczego wyliczania): ";
				cin >> kwantCzasu;
				break;
			case 'b':
				data = Generator("less.txt").getProcessList();
				break;
			case 'c':
				data = Generator("more.txt").getProcessList();
				break;
			case 'd':
				data = Generator("onebig.txt").getProcessList();
				break;
			case 'e':
			{
				string src;
				cout << "Podaj nazwe pliku: ";
				cin >> src;
				data = Generator(src).getProcessList();
			}
			default:
				break;
			}
			
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
		<< "3. Algorytm SJF z wywlaszczeniem\n"
		<< "4. Algorytm RR\n"
		<< "5. Statystyki dla wszystkich algorytmow\n"
		<< "6. Konfiguracja\n"
		<< "7. Wyjscie\n"
		<< "=========================\n"
		<< "Twoj wybor to: ";
}