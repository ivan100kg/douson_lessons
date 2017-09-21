// file:    krest_nol.cpp
// created: Mon Sep 18 09:29:57 2017
// author:  Ivan Bondarev
// крестики-нолики своя версия

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
#if defined(linux) || defined(__linux)
    int sys = 1;
#endif
#if defined(_WIN32) || defined (_WIN64) /*первый для обеих определён*/
    int sys = 2;
#endif

void clear();
void sleep(int sec);
void display(const char* const pole);
int victory(const char* const pole);
void playerGo(char* const pole, char player);
void computerGo(char* const pole, char player, char computer);

int main(int args, char *argv[])
{
    clear();
    cout << "\t\tИгра Крестики-Нолики\n";
    cout << "\nПравила: для победы необходимо поставить 3 символа в ряд или"
        " по диаганали\n";

    sleep(1);
    char krest = 'X';
    char nol = 'O';
    char empty = ' ';
    const int NUM = 9;
    char pole[NUM];
    for(int i=0; i<NUM; i++)
        pole[i] = empty;
    srand(time(0));
    char player, computer;
    bool step;
    if((rand() % 2 +1) == 1)
    {
        player = krest;
        computer = nol;
        step = true;
    }
    else
    {
        player = nol;
        computer = krest;
        step = false;
    }

    // основной цикл
    while(victory(pole) == 3)
    {
        display(pole);
        if(step)
        {
            playerGo(pole, player);
            step = false;
        }
        else
        {
            computerGo(pole, player, computer);
            step = true;
        }
    }
    display(pole);
    cout << "status = " << victory(pole) << endl;

    return 0;
}

void clear()
{
    if(sys == 1)
        system("clear");
    else
        system("cls");
}
void sleep(int sec)
{
    time_t start, finish;
    time(&start);
    finish = start + sec;
    while(time(&start) != finish)
        continue;
}
void display(const char* const pole)
{
    clear();
    cout << "\t " << pole[0] << " | " << pole[1] << " | " << pole[2] << endl;
    cout << "\t" << "-----------" << endl;
    cout << "\t " << pole[3] << " | " << pole[4] << " | " << pole[5] << endl;
    cout << "\t" << "-----------" << endl;
    cout << "\t " << pole[6] << " | " << pole[7] << " | " << pole[8] << endl;
}

int victory(const char* const pole)
{
    int winner = 0;
    const int ROW[8][3] = {
                 {0,1,2},
                 {3,4,5},
                 {6,7,8},
                 {0,3,6},
                 {1,4,7},
                 {2,5,8},
                 {0,4,8},
                 {2,4,6}
             };
    for(int i = 0; i < 8; i++)
    {
        if((pole[ROW[i][0]] == pole[ROW[i][1]]) &&
                (pole[ROW[i][0]] == pole[ROW[i][2]]))
        {
            if(pole[ROW[i][0]] == 'X')
            {
                winner = 1;
                break;
            }
            else if(pole[ROW[i][0]] == 'O')
            {
                winner = 2;
                break;
            }
        }
        for(int j = 0; j < 9; j++)
        {
            if(pole[j] == ' ')
                winner = 3;
        }
    }
    return winner;
}
void playerGo(char* const pole, char player)
{
    int choise;
    while(true)
    {
        cout << "\nВ какую клетку поставить символ? (1-9) ";
        cin >> choise;
        choise -= 1;
        if(pole[choise] != ' ')
        {
            cout << "клетка занята" << endl;
            continue;
        }
        else
            pole[choise] = player;
        break;
    }
}
void computerGo(char* const pole, char player, char computer)
{
    cout << "ходит комп" << endl;
    sleep(2);
    if(pole[0] == computer && pole[1] == computer && pole[2] == ' ')
        pole[2] = computer;
    else if(pole[0] == computer && pole[2] == computer && pole[1] == ' ')
        pole[1] = computer;
    else if(pole[1] == computer && pole[2] == computer && pole[0] == ' ')
        pole[0] = computer;

    else if(pole[4] == computer && pole[5] == computer && pole[3] == ' ')
        pole[3] = computer;
    else if(pole[3] == computer && pole[5] == computer && pole[4] == ' ')
        pole[4] = computer;
    else if(pole[3] == computer && pole[4] == computer && pole[5] == ' ')
        pole[5] = computer;

    else if(pole[7] == computer && pole[8] == computer && pole[6] == ' ')
        pole[6] = computer;
    else if(pole[6] == computer && pole[8] == computer && pole[7] == ' ')
        pole[7] = computer;
    else if(pole[6] == computer && pole[7] == computer && pole[8] == ' ')
        pole[8] = computer;

    else if(pole[6] == computer && pole[3] == computer && pole[0] == ' ')
        pole[0] = computer;
    else if(pole[6] == computer && pole[0] == computer && pole[3] == ' ')
        pole[3] = computer;
    else if(pole[0] == computer && pole[3] == computer && pole[6] == ' ')
        pole[6] = computer;

    else if(pole[4] == computer && pole[7] == computer && pole[1] == ' ')
        pole[1] = computer;
    else if(pole[1] == computer && pole[7] == computer && pole[4] == ' ')
        pole[4] = computer;
    else if(pole[1] == computer && pole[4] == computer && pole[7] == ' ')
        pole[7] = computer;

    else if(pole[5] == computer && pole[8] == computer && pole[2] == ' ')
        pole[2] = computer;
    else if(pole[2] == computer && pole[8] == computer && pole[5] == ' ')
        pole[5] = computer;
    else if(pole[2] == computer && pole[5] == computer && pole[8] == ' ')
        pole[8] = computer;

    else if(pole[4] == computer && pole[8] == computer && pole[0] == ' ')
        pole[0] = computer;
    else if(pole[0] == computer && pole[8] == computer && pole[4] == ' ')
        pole[4] = computer;
    else if(pole[0] == computer && pole[4] == computer && pole[8] == ' ')
        pole[8] = computer;

    else if(pole[4] == computer && pole[6] == computer && pole[2] == ' ')
        pole[2] = computer;
    else if(pole[2] == computer && pole[6] == computer && pole[4] == ' ')
        pole[4] = computer;
    else if(pole[2] == computer && pole[4] == computer && pole[6] == ' ')
        pole[6] = computer;


    else if(pole[0] == player && pole[1] == player && pole[2] == ' ')
        pole[2] = computer;
    else if(pole[0] == player && pole[2] == player && pole[1] == ' ')
        pole[1] = computer;
    else if(pole[1] == player && pole[2] == player && pole[0] == ' ')
        pole[0] = computer;

    else if(pole[4] == player && pole[5] == player && pole[3] == ' ')
        pole[3] = computer;
    else if(pole[3] == player && pole[5] == player && pole[4] == ' ')
        pole[4] = computer;
    else if(pole[3] == player && pole[4] == player && pole[5] == ' ')
        pole[5] = computer;

    else if(pole[7] == player && pole[8] == player && pole[6] == ' ')
        pole[6] = computer;
    else if(pole[6] == player && pole[8] == player && pole[7] == ' ')
        pole[7] = computer;
    else if(pole[6] == player && pole[7] == player && pole[8] == ' ')
        pole[8] = computer;

    else if(pole[3] == player && pole[6] == player && pole[0] == ' ')
        pole[0] = computer;
    else if(pole[6] == player && pole[0] == player && pole[3] == ' ')
        pole[3] = computer;
    else if(pole[3] == player && pole[0] == player && pole[6] == ' ')
        pole[6] = computer;

    else if(pole[4] == player && pole[7] == player && pole[1] == ' ')
        pole[1] = computer;
    else if(pole[1] == player && pole[7] == player && pole[4] == ' ')
        pole[4] = computer;
    else if(pole[1] == player && pole[4] == player && pole[7] == ' ')
        pole[7] = computer;

    else if(pole[5] == player && pole[8] == player && pole[2] == ' ')
        pole[2] = computer;
    else if(pole[2] == player && pole[8] == player && pole[5] == ' ')
        pole[5] = computer;
    else if(pole[2] == player && pole[5] == player && pole[8] == ' ')
        pole[8] = computer;

    else if(pole[4] == player && pole[8] == player && pole[0] == ' ')
        pole[0] = computer;
    else if(pole[0] == player && pole[8] == player && pole[4] == ' ')
        pole[4] = computer;
    else if(pole[0] == player && pole[4] == player && pole[8] == ' ')
        pole[8] = computer;

    else if(pole[4] == player && pole[6] == player && pole[2] == ' ')
        pole[2] = computer;
    else if(pole[2] == player && pole[6] == player && pole[4] == ' ')
        pole[4] = computer;
    else if(pole[2] == player && pole[4] == player && pole[6] == ' ')
        pole[6] = computer;

    else if(pole[1] == player && pole[3] == player && pole[0] == ' ')
        pole[0] = computer;
    else if(pole[1] == player && pole[6] == player && pole[0] == ' ')
        pole[2] = computer;
    else if(pole[5] == player && pole[7] == player && pole[0] == ' ')
        pole[8] = computer;
    else if(pole[7] == player && pole[3] == player && pole[0] == ' ')
        pole[6] = computer;

    else if(pole[0] == ' ' &&
            pole[1] == ' ' &&
            pole[2] == ' ' &&
            pole[3] == ' ' &&
            pole[4] == ' ' &&
            pole[5] == ' ' &&
            pole[6] == ' ' &&
            pole[7] == ' ' &&
            pole[8] == ' ')
    {
        vector<int> numbers;
        numbers.push_back(0);
        numbers.push_back(2);
        numbers.push_back(6);
        numbers.push_back(8);
        random_shuffle(numbers.begin(), numbers.end());
        pole[numbers[0]] = computer;
    }

    else if(pole[4] == ' ' && pole[0] == computer && (pole[1] == player || pole[2] == player) && pole[6] == ' ')
        pole[6] = computer;
    else if(pole[4] == ' ' && pole[2] == computer && (pole[0] == player || pole[1] == player) && pole[8] == ' ')
        pole[8] = computer;
    else if(pole[4] == ' ' && pole[0] == computer && (pole[3] == player || pole[6] == player) && pole[2] == ' ')
        pole[2] = computer;
    else if(pole[4] == ' ' && pole[2] == computer && (pole[5] == player || pole[8] == player) && pole[0] == ' ')
        pole[0] = computer;
    else if(pole[4] == ' ' && pole[6] == computer && (pole[0] == player || pole[3] == player) && pole[8] == ' ')
        pole[8] = computer;
    else if(pole[4] == ' ' && pole[6] == computer && (pole[7] == player || pole[8] == player) && pole[0] == ' ')
        pole[0] = computer;
    else if(pole[4] == ' ' && pole[8] == computer && (pole[2] == player || pole[4] == player) && pole[6] == ' ')
        pole[6] = computer;
    else if(pole[4] == ' ' && pole[8] == computer && (pole[6] == player || pole[6] == player) && pole[2] == ' ')
        pole[2] = computer;

    else if(pole[4] == ' ')
        pole[4] = computer;
    else if(pole[0] == ' ')
        pole[0] = computer;
    else if(pole[2] == ' ')
        pole[2] = computer;
    else if(pole[6] == ' ')
        pole[6] = computer;
    else if(pole[8] == ' ')
        pole[8] = computer;
    else if(pole[2] == ' ')
        pole[2] = computer;
    else if(pole[3] == ' ')
        pole[3] = computer;
    else if(pole[5] == ' ')
        pole[5] = computer;
    else if(pole[7] == ' ')
        pole[7] = computer;


}

