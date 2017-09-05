#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(int args, char *argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    int number = rand() % 100 +1;   // от 1 до 100
    int n = 0;
    while (n < 10)
    {
        number = rand() % 100 +1;   // от 1 до 100
        cout << "number = " << number << endl;
        n++;
    }
    cout << static_cast<unsigned int>(time(0)) << endl;
    return 0;
}
