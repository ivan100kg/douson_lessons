// file:    iterator.cpp
// created: Sat Aug 26 21:37:33 2017
// author:  Ivan Bondarev

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int args, char *argv[])
{
    vector<string> inventory;
    inventory.push_back("sword");   // добавляет элемент в конец списка
    inventory.push_back("armor");
    inventory.push_back("shield");

    vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
    {
        cout << *iter << endl;
    }

    cout << "\nYou trade your sword for a battle axe.";
    myIterator = inventory.begin();
    *myIterator = "battle axe";

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
    {
        cout << *iter << endl;
    }

    cout << "\nThe item name " << *myIterator << " has ";
    cout << (*myIterator).size() << " letters in it.\n";
    cout << "\nThe item name " << *myIterator << " has ";
    cout << myIterator->size() << " letters in it.\n";
    cout << "\nYour recover a crossbow from a slain enemy.";
    inventory.insert(inventory.begin(), "crossbow");

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
    {
        cout << *iter << endl;
    }

    cout << "\nYour amor is destroyed in a fierce battle." << endl;
    inventory.erase((inventory.begin() + 2));

    cout << "Your items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
    {
        cout << *iter << endl;
    }

    cout << "\nThe item name " << *myIterator << " has ";
    cout << (*myIterator).size() << " letters in it.\n";
    return 0;
}
