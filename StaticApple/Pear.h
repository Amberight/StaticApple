#pragma once
#include <string>
#include "Fruit.h"

class Pear : public Fruit
{
private:
	int weight;
	std::string colour;
public:
	Pear(int x = 0, std::string y = "NA");
	static void Print();
	~Pear();
};

