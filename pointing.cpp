// file:    pointing.cpp
// created: Wed Sep 13 12:38:26 2017
// author:  Ivan Bondarev
// указатели

#include <iostream>
#include <string>
using namespace std;

int main(int args, char *argv[])
{
    int *pAPointer;  // объявления указателя
    int *pScore = 0;
    int score = 1000;
    pScore = &score; // присваиваем адрес
    cout << "\nscore = " << score << endl;
    cout << "pScore = &score = " << &score << " = " << pScore << endl;
    cout << "*pScore = " << *pScore << endl;
    score+=500;
    cout << "\nscore = " << score << endl;
    cout << "pScore = &score = " << &score << " = " << pScore << endl;
    cout << "*pScore = " << *pScore << endl;
    return 0;
}
