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

	Apl1->ReadFile();
	
	Apples *Apl4 = new Apples();
	Apl4->ReadFile();
	Apl4->showInfo();

	/*std::cout << &Apl1 << std::endl;

	std::fstream ass("object.bin", std::ios::binary | std::ios::in | std::ios::out);
	ass.read((char *)&Apl4, sizeof(Fruit));

	Apl1.showInfo();
	Apl4->showInfo();

	//delete Apl3;
	//Apples::Print();
	
	/*std::fstream file("object.bin", std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
	file.write((char *)&Apl1, sizeof(Fruit));
	file.seekg(0);
	Apl1->SaveFile(Apl1);
	std::fstream file("object.bin", std::ios::binary | std::ios::in | std::ios::out);
	file.read((char *)&Apl4, sizeof(Fruit));

	//Apl4->ReadFile();

	Apl1->showInfo();
	Apl4->showInfo();*/

	return 0;
}