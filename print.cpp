// file:    print.cpp
// created: Tue Sep  5 22:09:23 2017
// author:  Ivan Bondarev
// аналог print() python3

#include <iostream>
#include <string>
using namespace std;

string print(string text);

int main(int args, char *argv[])
{
    int num = std::stoi(print("Введите число "));
    cout << "\nЧисло = " << num*num << endl;
    return 0;
}

string print(string text)
{
    string num;
    cout << text;
    cin >> num;
    return num;
}
