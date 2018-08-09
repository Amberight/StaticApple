#include "stdafx.h"
#include "Fruit.h"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>

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

void Fruit::SaveFile()
{
}

void Fruit::ReadFile()
{
}

void Fruit::showInfo()
{

}

Fruit::~Fruit()
{
}