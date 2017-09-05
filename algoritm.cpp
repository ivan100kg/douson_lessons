// file:    algoritm.cpp
// created: Sun Sep  3 22:51:19 2017
// author:  Ivan Bondarev
// демонстрируем работу с алгоритмами

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int args, char *argv[])
{
    vector<int>::const_iterator iter;

    cout << "Создание списка рекордов" << endl;
    vector<int> scores;
    scores.push_back(1500);
    scores.push_back(3500);
    scores.push_back(7500);

    cout << "Рекорды:" << endl;
    for (iter=scores.begin(); iter!=scores.end(); iter++)
        cout << *iter << ' ';
    cout << endl;

    cout << "\nПоиск рекордов.";
    int score;
    cout << "\nВведите значение для поиска: ";
    cin >> score;
    iter = find(scores.begin(), scores.end(), score);
    if (iter != scores.end())
        cout << "Значение найдено." << endl;
    else
        cout << "Значение не найдено." << endl;

    cout << "\nРандомизация значений." << endl;
    srand(time(NULL));
    random_shuffle(scores.begin(), scores.end());

    cout << "Рекорды:" << endl;
    for (iter=scores.begin(); iter!=scores.end(); iter++)
        cout << *iter << ' ';
    cout << endl;

    cout << "\nСортировка значений." << endl;
    sort(scores.begin(), scores.end());

    cout << "Рекорды:" << endl;
    for (iter=scores.begin(); iter!=scores.end(); iter++)
        cout << *iter << ' ';
    cout << endl;


    return 0;
}
