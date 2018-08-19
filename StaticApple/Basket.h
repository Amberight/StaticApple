#pragma once
#pragma comment(lib, "Ws2_32.lib")
#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <vector>
#include "Fruit.h"
#include "Apples.h"
#include "Pear.h"
#include "time.h"
#include <random>
#include <thread>

#define SCK_VERSION2 0x0202

class Basket
{
private:
	void serverSetup();
	void fruitBasket();
	static void throwBasket(SOCKET &S);
	void fillBasket(std::vector<Fruit *> & vector);
public:
	Basket();
	void BasketPrime();
	~Basket();
};

