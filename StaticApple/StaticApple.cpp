#include "stdafx.h"
#include "Fruit.h"
#include "Apples.h"
#include "Pear.h"
#include <iostream>

int main()
{
	Fruit *Apl1 = new Apples(212, "red");
	Fruit *Apl2 = new Apples(130, "green");
	Fruit *Apl3 = new Apples(254, "red");
	Fruit *Pr1 = new Pear(159, "yellow");
	Fruit *Pr2 = new Pear(189, "yellow");
	
	Apl1->Print();
	Pr1->Print();
	delete Apl3;
	Apl1->Print();

	return 0;
}

