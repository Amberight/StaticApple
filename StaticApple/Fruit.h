#pragma once
#include <string>
#include <fstream>

class Fruit
{
protected:
	
private:
	int weight;
	std::string colour;
public:
	Fruit(int x = 0, std::string y = "NA");
	void Print();
	void showInfo();
	void SaveFile();
	void ReadFile();
	virtual ~Fruit();
};