// Дружественные ф-ии и перегрузка операторов

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using namespace std;


class Critter
{
	// Объявляем дружественные ф-ии классу Critter
	friend void Peek(const Critter& aCritter);
	friend ostream& operator<<(ostream& os, const Critter& aCritter);
    public:
    Critter(const string& name = "");
	
    private:
    string m_Name;
};

Critter::Critter(const string& name):
m_Name(name)
{}

void Peek(const Critter& aCritter);
ostream& operator<<(ostream& os, const Critter& aCritter);

int main(int args, char* argv[])
{
    Critter crit("Poochie");
	cout << "Calling Peek() to access crit's private data member, m_Name: \n";
	Peek(crit);
	cout << "\nSending crit object to cout with the << operator:\n";
	cout << crit << endl;

    return 0;
}

// глобальная дружественная ф-ия - имеет доступ ко всем членам объекта класса Critter
void Peek(const Critter& aCritter)
{
	cout << aCritter.m_Name << endl;
}

// глобальная дружественная ф-ия - имеет доступ ко всем членам объекта класса Critter
// перегруженный оператор << позволяет отправить объект типа Critter в cout
ostream& operator<<(ostream& os, const Critter& aCritter)
{
	os << "Critter Object - ";
	os << "m_Name: " << aCritter.m_Name;
	return os;
}