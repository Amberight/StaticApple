#include "stdafx.h"
#include "Apples.h"
#include <iostream>

static int s_Amount = 0;

Apples::Apples(int weight, std::string colour)
{
	s_Amount++;
	this->weight = weight;
	this->colour = colour;
}

void Apples::Print()
{
	printf("There are %d %s %s %d %s", s_Amount, colour.c_str(), "apples, weighing", weight, "gramms.\n");
}

Apples::~Apples()
{
}