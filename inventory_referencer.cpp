// file:    inventory_referencer.cpp
// created: Fri Sep  8 20:28:42 2017
// author:  Ivan Bondarev
// возврат ссылок

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// возвращает ссылку на строку
string& refToElement(vector<string>& inventory, int i);

int main(int args, char *argv[])
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    // отображается строка, на которую указывает возвращенная ссылка
    cout << "Sanding the returned ref to cout:" << endl;
    cout << refToElement(inventory, 0) << endl;
    // присваивание ссылки другой - незатратная операция
    cout << "\nAssinging the returned reference to another reference"
         << endl;
    string& rStr = refToElement(inventory, 1);
    cout << "Sanding the new ref to cout:" << endl;
    cout << rStr << endl;
    // копирование строкового объекта - затратная операция
    cout << "\nAssinging the returned reference to a string object"
         << endl;
    string str = refToElement(inventory, 2);
    cout << "Sanding the new string object to cout:" << endl;
    cout << str << endl;
    // изменение строкового объекта посредством возвращаемой ссылки
    cout << "\nAltering an object throught reference.\n";
    rStr = "Healing Potion";
    cout << "Sanding the altered object to cout:" << endl;
    cout << inventory[1] << endl;


    return 0;
}

string& refToElement(vector<string>& inventory, int i)
{
    return inventory[i];
}
