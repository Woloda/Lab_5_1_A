#include <stdlib.h>
#include <iostream>

#include "Make_Product_Class.h"

Product MakeProduct(int value_fir, double value_sec) { //створення об'кта
	Product x(value_fir, value_sec);
	return x;
}