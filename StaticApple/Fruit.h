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
	virtual int getWei();
	virtual std::string getCol();
	virtual void showInfo();
	virtual void SaveFile();
	virtual void ReadFile();
	virtual ~Fruit();
};