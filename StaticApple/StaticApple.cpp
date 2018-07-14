#include "stdafx.h"
#include "Fruit.h"
#include "Apples.h"
#include "Pear.h"
#include <iostream>

int main()
{
	Apples Apl1(212, "red");
	Apples Apl2(430, "green");
	Apples Apl3(254, "red");
	Pear Pear1(159, "yellow");
	Pear Pear2(189, "yellow");

	Apl1.Print();
	Pear1.Print();
	std::cout << std::endl;
	Apl3.~Apples();
	Pear2.~Pear();

	Apl1.Print();
	Pear1.Print();

	return 0;
}

