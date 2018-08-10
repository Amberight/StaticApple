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

	Apples::Print(); // prints out amount of Apples and combined wieght
	Pear::Print(); // prints out amount of Pears and combined wieght
	delete Apl3;
	Apples::Print();

	Apl1->SaveFile(); // Saves weight and colour of an object to a file "object.bin"
	Apl1->showInfo(); // Shows weight and colour of an object
	
	Apples *Apl4 = new Apples();
	Apl4->ReadFile(); // Loads weight and colour from "object.bin" into an object Apl4
	Apl4->showInfo(); // Shows weight and colour of an object

	return 0;
}