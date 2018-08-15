#include "stdafx.h"
#include "Fruit.h"
#include "Apples.h"
#include "Pear.h"
#include "Basket.h"
#include <iostream>
#include <vector>

int main()
{
	Fruit *Apl1 = new Apples(212, "red");
	Fruit *Apl2 = new Apples(130, "green");
	Fruit *Apl3 = new Apples(254, "red");
	Fruit *Pr1 = new Pear(159, "yellow");
	Fruit *Pr2 = new Pear(189, "yellow");

	Apples::Print(); // prints out amount of Apples and combined wieght
	Pear::Print(); // prints out amount of Pears and combined wieght
	delete Apl3;
	Apples::Print();

	Apl1->SaveFile(); // Saves weight and colour of an object to a file "object.bin"
	Apl1->showInfo(); // Shows weight and colour of an object
	
	Fruit *Apl4 = new Apples();
	Apl4->ReadFile(); // Loads weight and colour from "object.bin" into an object Apl4
	Apl4->showInfo(); // Shows weight and colour of an object

	Basket BO;
	BO.BasketPrime();

	return 0;
}