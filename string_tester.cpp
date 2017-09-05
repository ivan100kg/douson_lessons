#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main(int args, char *argv[])
{
    string word1 = "Game";  // Разные способы создания строк
    string word2("Over");
    string word3(3, '!');
    string phrase = word1 + word2 + word3;  // конкатенация
    cout << "word1 = " << word1 << endl;
    cout << "word2 = " << word2 << endl;
    cout << "word3 = " << word3 << endl;
    cout << "phrase = " << phrase << endl;
    cout << "word1[0] = " << word1[0] << endl;
    cout << "phrase.size() = " << phrase.size() << endl;
    cout << "word1[0] = 'F'" << endl;
    word1[0] = 'F';
    cout << "word1 = " << word1 << endl;
    cout << "phrase.find(\"Over\") = " << phrase.find("Over") << endl;
    cout << "string::npos = " << string::npos << endl;
    cout << "phrase.erase(0, 2)" << endl;
    phrase.erase(0, 2);
    cout << "phrase = " << phrase << endl;

    return 0;
}

