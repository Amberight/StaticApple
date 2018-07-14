#include "stdafx.h"
#include "Pear.h"
#include <iostream>

static int s_Amount = 0;
static int s_sumWeight = 0;

Pear::Pear(int weight, std::string colour)
{
	s_Amount++;
	this->weight = weight;
	this->colour = colour;
	s_sumWeight = s_sumWeight + weight;
}

void Pear::Print()
{
	printf("There are %d %s %s %d %s", s_Amount, colour.c_str(), "pears, weighing", s_sumWeight, "gramms.\n");
}

Pear::~Pear()
{
	s_Amount--;
	s_sumWeight = s_sumWeight - weight;
}