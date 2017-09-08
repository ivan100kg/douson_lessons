// ссылки
#include <iostream>

using namespace std;

int main()
{
    int myScore = 1000;
    int& vanoScore = myScore;  // Создание ссылки
    cout << "myScore is: " << myScore << endl;
    cout << "vanoScore is: " << vanoScore << endl;
    cout << "adding 500 to myScore" << endl;
    myScore += 500;
    cout << "myScore is: " << myScore << endl;
    cout << "vanoScore is: " << vanoScore << endl;
    cout << "adding 500 to vanoScore" << endl;
    vanoScore += 500;
    cout << "myScore is: " << myScore << endl;
    cout << "vanoScore is: " << vanoScore << endl;
    return 0;
}
