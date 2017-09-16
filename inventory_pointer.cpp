// file:    inventory_pointer.cpp
// created: Sat Sep 16 13:54:42 2017
// author:  Ivan Bondarev
// возврат указателя

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// возвращает ссылку на строку
string* ptrToElement(vector<string>* const inventory, int i);

int main(int args, char *argv[])
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    // отображается строка, на которую указывает возвращенная ссылка
    cout << "Sanding the returned ref to cout:" << endl;
    cout << *(ptrToElement(&inventory, 0)) << endl;
    // присваивание ссылки другой - незатратная операция
    cout << "\nAssinging the returned reference to another reference"
         << endl;
    string* pStr = ptrToElement(&inventory, 1);
    cout << "Sanding the new ref to cout:" << endl;
    cout << *pStr << endl;
    // копирование строкового объекта - затратная операция
    cout << "\nAssinging the returned reference to a string object"
         << endl;
    string str = *(ptrToElement(&inventory, 2));
    cout << "Sanding the new string object to cout:" << endl;
    cout << str << endl;
    // изменение строкового объекта посредством возвращаемой ссылки
    cout << "\nAltering an object throught reference.\n";
    *pStr = "Healing Potion";
    cout << "Sanding the altered object to cout:" << endl;
    cout << inventory[1] << endl;


    return 0;
}

string* ptrToElement(vector<string>* const inventory, int i)
{
    return &((*inventory)[i]);
}
