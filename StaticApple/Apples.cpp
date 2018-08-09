#include "stdafx.h"
#include "Apples.h"
#include <iostream>

static int s_Amount = 0;
static int s_sumWeight = 0;

Apples::Apples(int weight, std::string colour)
{
	s_Amount++;
	this->weight = weight;
	this->colour = colour;
	s_sumWeight = s_sumWeight + weight;
}

 void Apples::Print()
{
	printf("There are %d %s %d %s", s_Amount, "apples, weighing", s_sumWeight, "gramms.\n");
}

void Apples::changeValues(int x, std::string col)
{
	weight = x;
	colour = col;
}

void Apples::SaveFile()
{
	std::ofstream file;
	file.open("object.bin", std::ios::binary | std::ios::out);
	if (!file.is_open())
	{
		printf("Error reading file\n");
	}
	else
	{
		file << weight << "\n";
		file << colour << "\n";
		printf("Object saved succesfully\n");
	}
}

void Apples::ReadFile()
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
		//weight = std::stoi(tempW);
		//colour = tempC;
		Apples::changeValues(std::stoi(tempW), tempC);
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