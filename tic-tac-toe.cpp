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
bool isLegal(int move, const vector<char>& board);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char>& board, char computer);
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
int askNumber(string question, int high, int low)
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
    vector<char> OX;
    OX.push_back(O);
    OX.push_back(X);

    random_shuffle(OX.begin(), OX.end());
    return OX[0];
}
char opponent(char piece)
{
    if(piece == X)
        return O;
    else
        return X;
}
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
    };
    const int TOTAL_ROW = 8;
    // если в одном из выигрышных рядов присутствуют 3 одинаковых значения
    // причем они не равны EMPTY , то победитель определился
    for (int row = 0; row < TOTAL_ROW; ++row)
    {
        if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
            (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
            (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
        {
            return board[WINNING_ROWS[row][0]];
        }
     }
    // поскольку победитель не определился, но и ни ничья еще не наступила
    // игра продолжается
    return NO_ONE;
}

bool isLegal(int move, const vector<char>& board)
{
    return (board[move] == EMPTY);
}
int humanMove(const vector<char>& board, char human)
{
    int move = askNumber("В какую клетку поставить?" , (board.size() - 1));
    while (!isLegal(move, board))
    {
        cout << "\nКлетка занята\n";
        move = askNumber("В какую клетку поставить?" , (board.size() - 1));
    }
    cout << "Хорошо...\n";
    return move;
}
int computerMove(vector<char>& board, char computer)
{
    unsigned int move = 0;
    bool found = false;
    // если комп может выиграть следующим ходом, то он это сделает
    while (!found && move < board.size())
    {
        if (isLegal(move, board))
        {
            board[move] = computer;
            found = (winner(board) == computer);
            board[move] = EMPTY;
        }
        if(!found)
            ++move;
    }
    // Если человек следующим ходом может победить - блокировать этот ход
    if(!found)
    {
        move = 0;
        char human = opponent(computer);
        while(!found && move < board.size())
        {
            if(isLegal(move, board))
            {
                board[move] = human;
                found = winner(board) == human;
                board[move] = EMPTY;
            }
            if(!found)
                ++move;
        }
    }
    // иначе занять следующим ходом оптимальную свободную клетку
    move = 0;
    unsigned int i = 0;
    const int BEST_MOVES[] = {4,0,2,6,8,1,3,5,7};
    // выбрать оптимальную свободную клетку
    while(!found && i < board.size())
    {
        move = BEST_MOVES[i];
        if(isLegal(move, board))
            found = true;
        ++i;
    }
    cout << "Я занял клетку " << move << endl;
    return move;
}
void announceWinner(char winner, char computer, char human)
{
    if(winner == computer)
    {
        cout << winner << " победил!\n";
    }
    else if(winner == human)
        cout << winner << " победил!\n";
    else
        cout << "НИЧЬЯ" << endl;

}
