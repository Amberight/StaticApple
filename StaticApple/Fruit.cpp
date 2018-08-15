#include "stdafx.h"
#include "Fruit.h"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>

static  int s_Amount = 0;

Fruit::Fruit(int wei, std::string col)
{
	s_Amount++;
	this->weight = wei;
	this->colour = col;
}

void Fruit::Print()
{
	printf("Default output\n");
}

int Fruit::getWei()
{
	return weight;
}

std::string Fruit::getCol()
{
	return colour;
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