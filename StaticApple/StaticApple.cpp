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
	Pear *Pr1 = new Pear(159, "yellow");
	Pear *Pr2 = new Pear(189, "yellow");

	Apples::Print();
	Pear::Print();
	delete Apl3;
	Apples::Print();

	Apl1->SaveFile();
	Apl1->showInfo();
	
	Apples *Apl4 = new Apples();
	Apl4->ReadFile();
	Apl4->showInfo();

	return 0;
}