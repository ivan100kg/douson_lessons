// Статические члены данных, функции-члены
#include <iostream>
using namespace std;

class Critter
{
    public:
    static int s_Total;         // статическая переменная
    Critter(int hunger = 0);    // конструктор
    static int GetTotal();      // статическая ф-ия
    private:
    int m_Hunger;    
};
int Critter::s_Total = 0;
Critter::Critter(int hunger):
m_Hunger(hunger)
{
    cout << "A critter has been born!" << endl;
    ++s_Total;
}
int Critter::GetTotal()
{
    return s_Total;
}

int main()
{
    cout << "The total number of critters is: ";
    cout << Critter::s_Total << endl;
    Critter crit1, crit2, crit3;
    cout << "The total number of critters is: ";
    cout << Critter::GetTotal() << endl;
    
    return 0;
}