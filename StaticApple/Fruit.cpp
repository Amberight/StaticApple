#include "stdafx.h"
#include "Fruit.h"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

static  int s_Amount = 0;

Fruit::Fruit(int weight, std::string colour)
{
	s_Amount++;
	this->weight = weight;
	this->colour = colour;
}

void Fruit::Print()
{
	printf("Default output\n");
}

void Fruit::SaveFile(Fruit *ob)
{
	std::fstream file("object.bin", std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
	if (!file.is_open())
	{
		printf("Error reading file\n");
	}
	else
	{
		file.write((char *)&ob, sizeof(Fruit));
		file.seekg(0);
		printf("Object saved succsefully\n");
	}
}

void Fruit::ReadFile(Fruit *ob)
{
	std::ifstream file("object.bin", std::ios::binary | std::ios::in);
	if (!file.is_open())
	{
		printf("Error reading file\n");
	}
	else
	{
		file.read((char *)&ob, sizeof(Fruit));
		printf("Object copied succsefully\n");
	}
}

void Fruit::showInfo()
{

}

Fruit::~Fruit()
{
}