#include "stdafx.h"
#include "Fruit.h"
#include "Apples.h"
#include "Pear.h"

int main()
{
	Apples Apl1(200, "red");
	Apples Apl2(200, "green");
	Apples Apl3(200, "red");
	Pear Pear1(200, "yellow");
	Pear Pear2(200, "yellow");

	Apl1.Print();
	Pear1.Print();

	return 0;
}

