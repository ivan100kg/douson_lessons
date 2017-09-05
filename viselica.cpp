// file:    viselica.cpp
// created: Mon Sep  4 18:37:41 2017
// author:  Ivan Bondarev
// игра "Виселица"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>   // ф-ии для перевода в верхний регистр

using namespace std;

int main(int args, char *argv[])
{
    system("clear");
    // Подготовка
    const int MAX_WRONG = 8;    // максимальное число ошибок
    vector<string> words;       // набор слов для загадывания
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    srand(static_cast<unsigned int>(time(0)));  // случайная генерация
    random_shuffle(words.begin(), words.end()); // перемешивание
    const string THE_WORD = words[0];           // загаданное слово
    int wrong = 0;                              // кол-во ошибок
    string soFar(THE_WORD.size(), '-');         // открытая часть слова
    string used = "";                           // отгаданные буквы
    cout << "Welcome to Hangman. Good luck!" << endl;

    // основной цикл
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect gueses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); // перевод в верхний регистр
        while (used.find(guess) != string::npos)
        {   // проверяем не гадали ли мы раньше эту букву
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        used += guess;
        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word\n";
            // обновляем soFar
            for (int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                    soFar[i] = guess;
            }
        }
        else
        {
            cout << "Sorry. " << guess << " isn't in the word.\n";
            ++wrong;
        }
        system("clear");
    }
    if (wrong == MAX_WRONG)
        cout << "\nYou've been hanged!";
    else
        cout << "\nYou guesser it";
    cout << "\nThe word was " << THE_WORD << endl;

    return 0;
}
