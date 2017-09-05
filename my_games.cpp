// file:    my_games.cpp
// created: Mon Sep  4 21:28:49 2017
// author:  Ivan Bondarev

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main(int args, char *argv[])
{
    vector<string> games;
    vector<string>::const_iterator iter;
    string poloska(80, '=');
    string game;
    while (true)
    {
        system("clear");
        cout << poloska << endl;
        cout << "         ***Мои любимые игры***" << endl;
        cout << poloska << endl;
        cout << "\n" << endl;
        int i = 1;
        for (iter = games.begin(); iter != games.end(); ++iter)
        {
            cout << i << " " << *iter << endl;
            i++;
        }
        cout << "\n" << endl;
        int j;
        cout << "Введите пункт меню для выполнения соответсвующей команды\n\n";
        cout << "1 - Добавить Игру" << endl;
        cout << "2 - Удалить Игру" << endl;
        cout << "3 - Список Игр" << endl;
        cout << "0 - Выход" << endl;
        cin >> j;
        switch (j)
        {
            case 1: cout << "\nДобавьте название\n";
                    cin >> game;
                    games.push_back(game);
                    break;
            case 2: cout << "\nВведите номер удаляемой игры\n";
                    int k;
                    cin >> k;
                    k -= 1;
                    games.erase(games.begin() + k);
                    break;
            case 3: break;
            case 0:
            default: break;
        }
        if (j == 0)
            break;


    }

    return 0;
}
