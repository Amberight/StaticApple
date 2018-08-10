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
	void showInfo();
	void setWeight(int x);
	void setColour(std::string y);
	static void Print();
	~Pear();
};

