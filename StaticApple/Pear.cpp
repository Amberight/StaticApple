#include "stdafx.h"
#include "Pear.h"
#include <iostream>

static int s_Amount = 0;
static int s_sumWeight = 0;

Pear::Pear(int wei, std::string col)
{
	s_Amount++;
	this->weight = wei;
	this->colour = col;
	s_sumWeight = s_sumWeight + wei;
}

int Pear::getWei()
{
	return weight;
}

std::string Pear::getCol()
{
	return colour;
}

void Pear::setWeight(int x)
{
	this->weight = x;
}

void Pear::setColour(std::string y)
{
	this->colour = y;
}

void Pear::Print()
{
	printf("There are %d %s %d %s", s_Amount, "pears, weighing", s_sumWeight, "gramms.\n");
}

void Pear::showInfo()
{
	printf("This pear is %s %s %d %s ", colour.c_str(), " and weighs ", weight, "\n");
}

Pear::~Pear()
{
	s_Amount--;
	s_sumWeight = s_sumWeight - weight;
}