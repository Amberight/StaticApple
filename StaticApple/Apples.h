#pragma once
#include <string>
#include "Fruit.h"

class Apples: public Fruit
{
private:
	int weight;
	std::string colour;
public:
	Apples(int x = 0, std::string y = "NA");
	void showInfo();
	void changeValues(int x, std::string col);
	void SaveFile();
	void ReadFile();
	static void Print();
	~Apples();
};