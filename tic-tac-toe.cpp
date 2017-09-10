// file:    tic-tac-toe.cpp
// created: Sat Sep  9 21:01:42 2017
// author:  Ivan Bondarev
// крестики-нолики

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// глобальные переменные
const char O = 'O';
const char X = 'X';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// прототипы ф-ий
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low=0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int nMove(const vector<char>& board, char computer);
void announceWinner(char winner, char computer, char human);

int main(int args, char *argv[])
{
    srand(time(0));
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);
    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(board);
    while(winner(board) == NO_ONE)
    {
        if(turn == human)
        {
            move = computerMove(board, computer);
            board[move] = human;
        }
    }

    return 0;
}

void instructions()
{
    cout << "Добро пожаловать в игру: Крестики-Нолики.\n";
    cout << "Игровое поле:\n\n";
    cout << " 0 | 1 | 2\n";
    cout << " 3 | 4 | 5\n";
    cout << " 6 | 7 | 8\n\n";
    cout << "Делайте ходы с помощью цифр на игровом поле\n" << endl;
}

char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
    } while(response != 'y' || response != 'n');
    return response;
}
int askNumber(string question, int high, int low=0)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);
    return number;
}

char humanPiece()
{
    vector<char> OX = {O, X};
    random_shuffle(OX.begin(), OX.end());
    return OX[0];
}
char opponent(char piece)
{
    if(piece == X)
        return O;
    else
        return X;
void displayBoard(const vector<char>& board)
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "----------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "----------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}
char winner(const vector<char>& board)
{
    // все возможные выиграши
    const int WINNING_ROWS[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    }
    const int TOTAL_ROW = 8;
}

}
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int nMove(const vector<char>& board, char computer);
void announceWinner(char winner, char computer, char human);
