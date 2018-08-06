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

void Apples::showInfo()
{
	printf("This apple is %s %s %d %s ", colour.c_str(), " and weighs ", weight, "\n");
}

Apples::~Apples()
{
	s_Amount--;
	s_sumWeight = s_sumWeight - weight;
}