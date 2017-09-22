// уровни доступа

#include <iostream>
using namespace std;

class Critter
{
    public:     //открытый раздел
        Critter(int hunger = 0);    // прототип коструктора
        int GetHunger() const;
        void SetHunger(int hunger);
    private:    // закрытый раздел
        int m_Hunger;
};

Critter::Critter(int hunger):    // определение конструктора
m_Hunger(hunger)    // инициализация членов такой ПРИЕМ
{
    std::cout << "A new critter hasbeen born with " << hunger <<
                " hungary level" << std::endl;
}

int Critter::GetHunger() const
{
    return m_Hunger;
}
void Critter::SetHunger(int hunger)
{
    if(hunger <= 0)
        cout << "you can't set a critter's hunger to a negative number\n\n";
    else
        m_Hunger = hunger;
}

int main()
{
    Critter crit(7);
    cout << crit.GetHunger() << endl;;
    crit.SetHunger(100);
    cout << crit.GetHunger() << endl;;
    crit.SetHunger(-1);
    crit.SetHunger(170);
    cout << crit.GetHunger() << endl;

    return 0;
}
