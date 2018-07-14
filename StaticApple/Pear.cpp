#include "stdafx.h"
#include "Pear.h"
#include <iostream>

static int s_Amount = 0;

Pear::Pear(int weight, std::string colour)
{
	s_Amount++;
	this->weight = weight;
	this->colour = colour;
}

void Pear::Print()
{
	printf("There are %d %s %s %d %s", s_Amount, colour.c_str(), "pears, weighing", weight, "gramms.\n");
}

Pear::~Pear()
{
}