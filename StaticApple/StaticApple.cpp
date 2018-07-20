#include "stdafx.h"
#include "Fruit.h"
#include "Apples.h"
#include "Pear.h"
#include <iostream>

int main()
{
	Apples *Apl1 = new Apples(212, "red");
	Apples *Apl2 = new Apples(130, "green");
	Apples *Apl3 = new Apples(254, "red");
	Pear *Pear1 = new Pear(159, "yellow");
	Pear *Pear2 = new Pear(189, "yellow");
	
	Apl1->Print();
	delete Apl3;
	Apl1->Print();

	return 0;
}

