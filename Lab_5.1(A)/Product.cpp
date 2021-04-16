#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>

#include "My_Error_Range.h"
#include "Product.h"


Product::Product() {   //конструктор за умовчанням(без параметрів)
	first = 0;
	second = 0;
}

Product::Product(int value_f, double value_s) throw(My_Error_Range) {  //конструктор ініціалізації
	if ((value_f <= 0) || (value_s <= 0))
		throw new My_Error_Range("\n\n!!!Incorrectly entered data!!!");		//генерування об'єкта винятка

	first = value_f;
	second = value_s;
}

Product::Product(const Product& obj) {   //конструктор копіювання
	first = obj.first;
	second = obj.second;
}

void Product::set_f(int value)   //встановлення значення поля "first"
{
	first = value;
}

void Product::set_s(double value)  //встановлення значення поля "second"
{
	second = value;
}

int Product::get_f() const       //отримання значення поля "first"
{
	return first;
}

double Product::get_s() const      //отримання значення поля "second"
{
	return second;
}

Product& Product::operator = (const Product& obj) {   //перевантаження операції "присвоєння"
	first = obj.first;
	second = obj.second;

	return *this;
}

Product::operator std::string() const {    //приведення типу – перетворення у літерний рядок
	std::stringstream sout;
	sout << "\n\nPeretvorenya v liternuy radok";
	sout << "\nfirst: " << first;
	sout << "\nsecond: " << second;

	return sout.str();
}

//перевантаження операції "виводу"(виводу на екран)
std::ostream& operator << (std::ostream& out, const Product& obj) {
	out << "\n\nPokaz vvedenux vamu znachenuy";
	out << "\nfirst: " << obj.first;
	out << "\nsecond: " << obj.second;

	return out;
}

//перевантаження операції "вводу"(введення з клавіатури)
std::istream& operator >> (std::istream& in, Product& obj) throw(std::out_of_range) {
	int  value_fir{};
	double value_sec{};

	std::cout << "\nVveid znachenua argymentiv: ";

	std::cout << "\n\nVvedit first: "; in >> value_fir;
	std::cout << "Vvedit second: ";    in >> value_sec;


	/*Використання стандартного винятка
	Успадкований від std :: logic_error.
	Визначає виняток, яке повинно бути кинуто в тому випадку,
	коли відбувається вихід за межі допустимого діапазону значень об'єкта*/
	if ((value_fir <= 0) || (value_sec <= 0))
		throw std::out_of_range{ "\n\n!!!Data entered incorrectly!!!" };	//генерування об'єкта винятка

	obj.first = value_fir;
	obj.second = value_sec;

	return in;
}

Product& Product::operator ++() {     //перевантаження операції "інкременту"(префіксна форма)
	++first;
	return *this;
}

Product& Product::operator --() {     //перевантаження операції "дикременту"(префіксна форма)
	--first;
	return *this;
}

Product Product::operator ++(int) {   //перевантаження операції "інкременту"(постфіксна форма)
	Product a(*this);
	second++;
	return a;
}

Product Product::operator --(int) {   //перевантаження операції "дикременту"(постфіксна форма)
	Product a(*this);
	second--;
	return a;
}

double Product::power() const  //обчислення загальна калорійність продукту
{
	return first * 10.0 * second;
}