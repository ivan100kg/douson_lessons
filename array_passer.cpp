// file:    array_passer.cpp
// created: Tue Sep 19 10:03:26 2017
// author:  Ivan Bondarev
// указатели и массивы

#include <iostream>
using namespace std;

void increase(int* const array, const int NUM_ELEMENTS);
void display(const int* const array, const int NUM_ELEMENTS);

int main(int args, char *argv[])
{
    cout << "creating array\n\n";
    const int NUM_SCORES = 3;
    int highScores[NUM_SCORES] = {5000, 3500, 2700};
    cout << "Отобразим значения используя имя массива как костантный указатель *highscores = " << *highScores << endl;
    cout << "*(highScores+1) = " << *(highScores+1) << endl;
    cout << "*(highScores+2) = " << *(highScores+2) << endl;
    display(highScores, NUM_SCORES);
    cout << "добавим значения к членам массива с помощью указателя" << endl;
    increase(highScores, NUM_SCORES);
    display(highScores, NUM_SCORES);
    return 0;
}

void increase(int* const array, const int NUM_ELEMENTS)
{
    for(int i = 0; i < NUM_ELEMENTS; ++i)
    {
        array[i] += 500;
    }

}
void display(const int* const array, const int NUM_ELEMENTS)
{
    for(int i = 0; i < NUM_ELEMENTS; ++i)
        cout << array[i] << endl;
}
