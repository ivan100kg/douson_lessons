#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(int args, char *argv[])
{

    vector<string> inventory;
    inventory.push_back("sword");   // добавляет элемент в конец списка
    inventory.push_back("armor");
    inventory.push_back("shield");
    cout << "you have: " << inventory.size() << " items.\n";
    cout << "\nyour items:\n";
    for (int i=0; i < inventory.size(); ++i)
    {
        cout << inventory[i] << endl;
    }
    inventory.pop_back();   // удаляет последний элемент
    cout << "you have: " << inventory.size() << " items.\n";
    cout << "\nyour items:\n";
    for (int i=0; i < inventory.size(); ++i)
    {
        cout << inventory[i] << endl;
    }

    return 0;
}

