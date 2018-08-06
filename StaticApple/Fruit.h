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
	void Print();
	void showInfo();
	static void SaveFile(Fruit *ob);
	static void ReadFile(Fruit *ob);
	virtual ~Fruit();
};