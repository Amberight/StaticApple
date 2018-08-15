#include "stdafx.h"
#include "Apples.h"
#include <iostream>

static int s_Amount = 0;
static int s_sumWeight = 0;

Apples::Apples(int wei, std::string col)
{
	s_Amount++;
	this->weight = wei;
	this->colour = col;
	s_sumWeight = s_sumWeight + wei;
}

int Apples::getWei()
{
	return weight;
}

std::string Apples::getCol()
{
	return colour;
}

void Apples::setWeight(int x)
{
	this->weight = x;
}

void Apples::setColour(std::string y)
{
	this->colour = y;
}

 void Apples::Print()
{
	printf("There are %d %s %d %s", s_Amount, "apples, weighing", s_sumWeight, "gramms.\n");
}

 void Apples::SaveFile() // save function
{
	std::ofstream file;
	file.open("object.bin", std::ios::binary | std::ios::out);
	if (!file.is_open()) // checks if file is open succesfully 
	{
		printf("Error reading file\n");
	}
	else
	{
		file << weight << "\n"; // saves variables to binary a file
		file << colour << "\n";
		printf("Object saved succesfully\n");
	}
}

void Apples::ReadFile() // load function
{
	std::ifstream file;
	file.open("object.bin", std::ios::binary | std::ios::in);
	if (!file.is_open())
	{
		printf("Error reading file\n");
	}
	else
	{
		std::string tempW;
		std::string tempC;

		std::getline(file, tempW);
		std::getline(file, tempC);
		Apples::setWeight(std::stoi(tempW));
		Apples::setColour(tempC);
		printf("Object loaded succesfully\n");
	}
}

void Apples::showInfo()
{
	printf("This apple is %s %s %d %s ", colour.c_str(), " and weighs ", weight, "\n");
}

Apples::~Apples()
{
	s_Amount--;
	s_sumWeight = s_sumWeight - weight;
}