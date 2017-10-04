// heap.cpp
// динамическая память

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int* intOnHeap();	// возвращает целочисленную переменную из кучи
void leek1();	// утечка памяти
void leek2();	// другая утечка памяти

int main(int args, char* argv[])
{
    int* pHeap = new int;	// выделяется память в куче для 1-го int, адрес присваевается указателю
	*pHeap = 10;	
	cout << "*pHeap: " << *pHeap << endl;
	int* pHeap2 = intOnHeap();
	int* pHeap3 = new int(100);	// сразу присваиваем значение 30
	cout << "*pHeap2: " << *pHeap2 << endl;
	cout << "Freeing memory pointed to by pHeap" << endl;
	delete pHeap;	// освобождение памяти из кучи
	cout << "Freeing memory pointed to by pHeap2" << endl;
	delete pHeap2;
	delete pHeap3;
	// избавляемся от висящих указателей
	pHeap = 0;
	pHeap2 = 0;
	pHeap3 = 0;
		
    return 0;
}

int* intOnHeap()
{
	int* pTemp = new int(20);	// память в куче хранит значения даже при закрытии ф-ии
	return pTemp;
}

void leek1()
{
	int* drip1 = new int(30);
}

void leek2()
{
	int* drip2 = new int(50);
	drip2 = new int(100);
	delete drip2;
}