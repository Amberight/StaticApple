#pragma once
#include <string>

class Fruit
{
protected:
	
private:
	int weight;
	std::string colour;
public:
	Fruit(int x = 0, std::string y = "NA");
	virtual void Print()=0;
	~Fruit();
};