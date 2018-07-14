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
	//printf("In total, there are %d %s", s_Amount, "fruit(s).");
}

Fruit::~Fruit()
{
}