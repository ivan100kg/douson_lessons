// file:    ref_and_point.cpp
// created: Sat Sep 16 10:33:13 2017
// author:  Ivan Bondarev
// указатели и ссылки разбор полетов

#include <iostream>
#include <string>
using std::string;
using std::getline; // принимает строку с пробелами

using namespace std;

void copy_func(int x, int y);   // передача копирование
void ref_func(int& x, int& y);  // ссылка
void const_ref_func(const int& x, const int& y);    // ссылка на константу
void point_func(int* x, int* y);    // указатель
void const_point_func(const int* x, const int* y);  // указатель на константу
// константный указатель, направлен только на опред адрес
void const_point_func2(int* const x, int* const y);
// константный указатель на константу
void const_point_func3(const int* const x, const int* const y);
void string_ref_point(string* str_point, string& str_ref, string str_copy);

int main(int args, char *argv[])
{
    int number1 = 100;
    int number2 = 200;
    int& reference = number1;   // ссылка на int number1
    int* pointer = &number2;    // указатель на int number2
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;
    cout << "меняем значения с помощью ссылки и указателя\n";
    cout << "reference += 1,  *pointer += 1\n";
    reference += 1;
    *pointer += 1;
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;
    cout << "\nвызываем по очереди ф-ии и пробуем изменить числа на +1\n";
    copy_func(number1, number2);
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;
    ref_func(number1, number2);
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;
    const_ref_func(number1, number2);
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;
    point_func(&number1, &number2);
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;
    const_point_func(&number1, &number2);
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;
    const_point_func2(&number1, &number2);
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;
    cout << "Итого: константный указатель = ссылка, а ссылка на костанту ="
        " константный указатель на костанту\n";
	string str1, str2, str3;
	str1 = "point";
	str2 = "ref";
	str3 = "copy";
	string_ref_point(&str1, str2, str3);

    return 0;
}

void copy_func(int x, int y)
{
    cout << "into copy_func" << endl;
    x += 1;
    y += 1;
}
void ref_func(int& x, int& y)
{
    cout << "into ref_func" << endl;
    x += 1;
    y += 1;
}
void const_ref_func(const int& x, const int& y)
{
    cout << "into const_ref_func" << endl;
    cout << "Не меняет значения!\n";
}
void point_func(int* x, int* y)
{
    cout << "into point_func" << endl;
    *x += 1;
    *y += 1;
}
void const_point_func(const int* x, const int* y)
{
    cout << "into const_point_func" << endl;
    cout << "Не меняет значения!\n";
}
void const_point_func2(int* const x, int* const y)
{
    cout << "into const_point_func2" << endl;
    *x += 1;
    *y += 1;
}
void string_ref_point(string* str_point, string& str_ref, string str_copy)
{
	cout << *str_point << endl;
	cout << str_ref << endl;
	cout << str_copy << endl;	
}