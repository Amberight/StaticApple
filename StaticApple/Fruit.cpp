#include "stdafx.h"
#include "Fruit.h"
#include <iostream>
#include <cstdio>

static  int s_Amount = 0;

Fruit::Fruit(int weight, std::string colour)
{
	s_Amount++;
	this->weight = weight;
	this->colour = colour;
}

void Fruit::Print()
{
	std::cout << "Default output." << std::endl;
}

Fruit::~Fruit()
{
}