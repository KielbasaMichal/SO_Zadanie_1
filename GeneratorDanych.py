import random

f = open('data.txt','w')
random.seed(f)
            
ile = 50

f.write(str(ile) + '\n')                         #ilosc danych

for i in range(ile):
    f.write(str(i) + '\t')                       #ID procesu
    f.write(str(random.randint(3, 100)) + '\t')  #Dlugosc trwania procesu
    f.write(str(random.randint(0, 20)) + '\n')   #Czas dodania do kolejni wykonania

f.close()
