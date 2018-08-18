#pragma once
#pragma comment(lib, "Ws2_32.lib")

#include <sdkddkver.h>
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <string>

#define SCK_VERSION2 0x0202

class Client
{
public:
	Client();
	void connection();
	~Client();
};