Systemy Operacyje 

Zadanie 1  
Program ma symulować działanie algorytmów planowania dostępu do procesora dla zgłaszających się procesów. 
Zbadać średni czas oczekiwania procesów dla różnych algorytmów planowania: 
- FCFS 
- SJF (z wywłaszczaniem i bez) 
- rotacyjnego (z możliwością wyboru kwantu czasu) 
Należy samodzielnie sformułować założenia symulacji. 
Wskazówki: 
- algorytmy najlepiej sprawdzać dla tych samych danych testowych (tj. tych samych ciągów testowych zgłaszających się procesów) 
- ciągów testowych powinno być więcej (20? 50?); wynikiem będą wartości średnie. 
- w każdym ciągu będzie N procesów o losowych długościach fazy procesora (rozkład długości faz dobrać tak, by odpowiadał sytuacji w rzeczywistym systemie, w którym nie jest równomierny), zgłaszających się w losowych momentach (dobrać parametry tak, by mogła powstać kolejka procesów oczekujących na przydział procesora).
- możliwa reprezentacja procesu: rekord (numer, dł.fazy procesora, moment zgłoszenia się, czas oczekiwania /początkowo równy 0/...) 
Uzyskane wyniki należy wytłumaczyć i być gotowym na wyciągnięcie z nich wniosków... :) 
Mile widziana możliwość sterowania parametrami symulacji. 
Przy zaliczeniu należy być przygotowanym na ew. pytania dotyczące materiału omówionego na wykładzie i związanego z tematem zadania...
