// кострукторы

#include <iostream>

class Critter
{
    public:
        int m_Hunger;
        Critter(int hunger = 0);    // прототип коструктора
        void Greet();
};

Critter::Critter(int hunger)    // определение конструктора
{
    std::cout << "A new critter hasbeen born with " << hunger <<
                " hungary level" << std::endl;
    m_Hunger = hunger;
}
void Critter::Greet()
{
    std::cout << "I'am a crit with hunger = " << m_Hunger << std::endl;
}

int main()
{
    Critter crit(7);
    crit.Greet();

    return 0;
}
