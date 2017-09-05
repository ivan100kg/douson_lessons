// file:    instructions.cpp
// created: Tue Sep  5 21:28:32 2017
// author:  Ivan Bondarev
// написание новых ф-ий

#include <iostream>
using namespace std;

// прототип функции(объявление)
void instructions();

int main(int args, char *argv[])
{
    instructions();
    return 0;
}

void instructions()
{
    cout << "Выполняется ф-я instructions()" << endl;
}
