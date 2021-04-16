#include <iostream>

#include "Make_Product_Class.h"		//додатково підключає файл "Product.h"
#include "Me_Error_size_memorry.h"
#include "My_Error_Range.h"

void test() throw(std::bad_exception);
void my_unexp();

int main(void) {
	std::cout << "\n\n////////////////////////////////////////////////////////////////////11111111\n";

	//визначається власний виняток
	try {	//захищений(контрольований) блок
		Product a(456, 12.4);
		std::cout << a;

		++a;
		std::cout << a;
		--a;
		std::cout << a;
		a++;
		std::cout << a;
		a--;
		std::cout << a;

		std::cout << a.operator std::string();
		std::cout << "\n\nZahalnya kaloriynist: " << a.power();
	}
	catch (My_Error_Range* a) {		//зловлює помилку "My_Error_Range"
		std::cout << a->What();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////2222222\n";

	//використання стандартного винятка
	try { //захищений(контрольований) блок
		Product b;

		std::cin >> b;		//введення даних об'єкта
		std::cout << b;

		++b;
		std::cout << b;
		--b;
		std::cout << b;
		b++;
		std::cout << b;
		b--;
		std::cout << b;

		std::cout << b.operator std::string();
		std::cout << "\n\nZahalnya kaloriynist: " << b.power();
	}
	catch (std::out_of_range obj_1) {		// зловлює помилку "out_of_range"
		std::cout << obj_1.what();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////3333333\n";

	//використання винятків - нащадки від стандартних винятків;
	try { //захищений(контрольований) блок
		int size(0);
		std::cout << "\n\nVvedit size musuva: ";  std::cin >> size;

		if ((size < 0) || (size > 80'000'000))
			throw Me_Error_size_memorry("!!!Incorrectly allocated memory!!!");		//генерування об'єкта винятка
		Product* c = new Product[size];

		int first(0);
		double second(0);
		std::cout << "\n\nVvedit first: "; std::cin >> first;
		std::cout << "Vvedit second: "; std::cin >> second;

		//визначається власний виняток
		try {	//захищений(контрольований) блок
			c[0] = MakeProduct(first, second);
			std::cout << c[0];

			++c[0];
			std::cout << c[0];
			--c[0];
			std::cout << c[0];
			c[0]++;
			std::cout << c[0];
			c[0]--;
			std::cout << c[0];

			std::cout << c[0].operator std::string();
			std::cout << "\n\nZahalnya kaloriynist: " << c[0].power();
		}
		catch (My_Error_Range* a) {		//зловлює помилку "My_Error_Range"
			std::cout << a->What();
		}
	}
	catch (Me_Error_size_memorry& obj_2) {		// зловлює помилку "Me_Error_size_memorry"
		std::cout << obj_2.What();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////3333333\n";

	/*Виняток склала заголовки <exception>
	std :: bad_exception - це тип виключення в C ++, яке виконується в наступних ситуаціях:
	* Якщо порушується динамічна специфікація винятків
	* Якщо std :: exception_ptr зберігає копію спійманого виключення, 
	і якщо конструктор копіювання об'єкта виключення зловив current_exception, 
	тоді генерується виключення захоплених винятків.*/
	set_unexpected(my_unexp);

	try {	//захищений(контрольований) блок
		test();
	}
	catch (const std::bad_exception& e)		//зловлює помилку "std::bad_exception"
	{
		std::cerr << "Caught " << e.what() << '\n';
	}

	std::cout << "\n\n";
	system("pause");
	return 0;
}

void test() throw(std::bad_exception)
{
	throw std::bad_exception{};
}

void my_unexp(){
	throw;
}