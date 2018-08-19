#include "stdafx.h"
#include "Basket.h"
#include <fstream>

int fruit_count;
std::vector<Fruit *> basketVec;

Basket::Basket()
{
	srand((time(0)) * 2);
}

void Basket::BasketPrime()
{
	int n;
	serverSetup();
}

void Basket::fruitBasket()
{
	//std::vector<Fruit *> basketVec;
	//fillBasket(basketVec);
}

void Basket::fillBasket(std::vector<Fruit *> & tempVec)
{
	fruit_count = (rand() % 10) + 1;
	for (int i = 0; i <= fruit_count; i++)
	{
		if (rand() % 2 == 1)
		{
			std::string tempCol = (rand()%2 < 1) ? "Red" : (((rand() % 2) < 1) ? "Green" : "Yellow");
			int tempWei = (rand() % 180) + 60;
			Fruit *Apl = new Apples(tempWei, tempCol);
			tempVec.push_back(Apl);
		}
		else
		{
			std::string tempCol = ((rand()%2) < 1) ? "Green" : "Yellow";
			int tempWei = (rand()% 150) + 80;
			Fruit *Par = new Pear(tempWei, tempCol);
			tempVec.push_back(Par);
		}
	}
}

void Basket::serverSetup()
{
	long SUCCESSFUL;
	WSAData WinSockData;
	WORD DLLVERSION;

	char tempAdr[20];
	char tempPort[20];

	std::string clientAdr;
	std::string clientPort;

	DLLVERSION = MAKEWORD(2, 1);

	SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

	SOCKADDR_IN ADDRESS;
	int(AddressSize) = sizeof(ADDRESS);

	SOCKET sock_Listen;
	SOCKET sock_Connection1;
	SOCKET sock_Connection2;
	SOCKET sock_Connection3;

	sock_Connection1 = socket(AF_INET, SOCK_STREAM, NULL);
	sock_Connection2 = socket(AF_INET, SOCK_STREAM, NULL);
	sock_Connection3 = socket(AF_INET, SOCK_STREAM, NULL);


	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);

	sock_Listen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sock_Listen, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
	listen(sock_Listen, 3);

	fillBasket(basketVec);

	for (;;)
	{
		printf("\n\tWaiting for connection... ");
		if (sock_Connection1 = accept(sock_Listen, (SOCKADDR*)&ADDRESS, &AddressSize));
		{
			printf("\n\tConnection found! \n");

			SUCCESSFUL = recv(sock_Connection1, tempAdr, sizeof(tempAdr), NULL);
			clientAdr = tempAdr;
			SUCCESSFUL = recv(sock_Connection1, tempPort, sizeof(tempPort), NULL);
			clientPort = tempPort;
			std::cout << "Client address: " << clientAdr << ", client port: "<<  clientPort << std::endl;
			
			printf("\nCommencing fruit transfer.");

			std::thread first(&Basket::throwBasket, sock_Connection1);
			first.detach();
			break;
		}
	}
	for (;;)
	{
		printf("\n\tWaiting for connection... ");
		if (sock_Connection2 = accept(sock_Listen, (SOCKADDR*)&ADDRESS, &AddressSize));
		{
			printf("\n\tConnection found! \n");

			SUCCESSFUL = recv(sock_Connection2, tempAdr, sizeof(tempAdr), NULL);
			clientAdr = tempAdr;
			SUCCESSFUL = recv(sock_Connection2, tempPort, sizeof(tempPort), NULL);
			clientPort = tempPort;
			std::cout << "Client address: " << clientAdr << ", client port: " << clientPort << std::endl;

			printf("\nCommencing fruit transfer.");

			std::thread second(&Basket::throwBasket, sock_Connection2);
			second.detach();
			break;
		}
	}
	for (;;)
	{
		printf("\n\tWaiting for connection... ");
		if (sock_Connection3 = accept(sock_Listen, (SOCKADDR*)&ADDRESS, &AddressSize));
		{
			printf("\n\tConnection found! \n");

			SUCCESSFUL = recv(sock_Connection3, tempAdr, sizeof(tempAdr), NULL);
			clientAdr = tempAdr;
			SUCCESSFUL = recv(sock_Connection3, tempPort, sizeof(tempPort), NULL);
			clientPort = tempPort;
			std::cout << "Client address: " << clientAdr << ", client port: " << clientPort << std::endl;

			printf("\nCommencing fruit transfer.");

			std::thread third(&Basket::throwBasket, sock_Connection3);
			third.detach();
			break;
		}
	}
}

void Basket::throwBasket(SOCKET &S)
{
	for (;;)
	{
		int i = (rand() % fruit_count);
		std::string transWei = std::to_string(basketVec[i]->getWei());
		std::string transCol = basketVec[i]->getCol();
		int result;
		result = send(S, transWei.c_str(), 20, NULL);
		result = send(S, transCol.c_str(), 20, NULL);

		Sleep(3000);
	}
}

Basket::~Basket()
{
}
