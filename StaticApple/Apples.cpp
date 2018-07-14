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
	printf("There are %d %s %s %d %s", s_Amount, colour.c_str(), "apples, weighing", s_sumWeight, "gramms.\n");
}

Apples::~Apples()
{
}