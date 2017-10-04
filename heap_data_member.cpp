// класс с членом-данных, память под который выделяется динамически
// heap__data_member.cpp

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::getline; // принимает строку с пробелами


class Critter
{
    public:
    Critter(const string& name = "", int age = 0);
	~Critter();	// прототип диструктора
	Critter(const Critter& c);	// прототип конструктора копирования
	Critter& Critter::operator=(const Critter& c);	// перегруженная операция присваивания
	void Greet() const;
	
    private:
    string* m_pName;
	int m_Age;
};

Critter::Critter(const string& name, int age)
{
	cout << "Constructor called\n";		
	m_pName = new string(name);	// присваиваем указателю адрес из кучи
	m_Age = age;
}

Critter::~Critter()	// деструктор
{
	cout << "destructor called\n";
	delete m_pName;	// освобождаем память
	m_pName = 0;		// висящий указатель
}

Critter::Critter(const Critter& c)	// коструктор копирования
{
	cout << "copy Constructor called\n";		
	m_pName = new string(*(c.m_pName));	// присваиваем указателю адрес из кучи
	m_Age = c.m_Age;
}

Critter& Critter::operator=(const Critter& c)
{
	cout << "Overloaded assignment operator called\n";
	if (this != &c)
	{
		delete m_pName;
		m_pName = new string(*(c.m_pName));
		m_Age = c.m_Age;
	}
	return *this;
}

void Critter::Greet() const
{
	cout << "I'm " << *m_pName << " and I'm " << m_Age << " years old" << endl;
	cout << "&m_pName: " << &m_pName << endl;
}

void testDestructor();
void testCopyConstructor(Critter aCopy);
void testAssignmentOp();

int main(int args, char* argv[])
{
    testDestructor();
	cout << endl;
	
	Critter crit("Poochie", 5);
	crit.Greet();
	testCopyConstructor(crit);
	crit.Greet();
	cout << endl;
	
	testAssignmentOp();

    return 0;
}

void testDestructor()
{
	Critter toDestroy("Rover", 3);
	toDestroy.Greet();
}
void testCopyConstructor(Critter aCopy)
{
	aCopy.Greet();
}
void testAssignmentOp()
{
	Critter crit1("crit1", 7);
	Critter crit2("crit2", 9);
	crit1 = crit2;
	crit1.Greet();
	crit2.Greet();
	cout << endl;
	Critter crit3("crit3", 11);
	crit3 = crit3;
	crit3.Greet();
}
	
