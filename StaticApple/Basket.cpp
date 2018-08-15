#include "stdafx.h"
#include "Basket.h"

int fruit_count;

Basket::Basket()
{
	srand((time(0)) * 2);
}

void Basket::BasketPrime()
{
	serverSetup();
}

void Basket::fruitBasket()
{
	std::vector<Fruit *> basketVec;
	fillBasket(basketVec);
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
	SOCKET sock_Connection;

	sock_Connection = socket(AF_INET, SOCK_STREAM, NULL);
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);

	sock_Listen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sock_Listen, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
	listen(sock_Listen, SOMAXCONN);

	std::vector<Fruit *> basketVec;
	fillBasket(basketVec);

	for (;;)
	{
		printf("\n\tWaiting for connection... ");
		if (sock_Connection = accept(sock_Listen, (SOCKADDR*)&ADDRESS, &AddressSize));
		{
			printf("\n\tConnection found! \n");

			SUCCESSFUL = recv(sock_Connection, tempAdr, sizeof(tempAdr), NULL);
			clientAdr = tempAdr;
			SUCCESSFUL = recv(sock_Connection, tempPort, sizeof(tempPort), NULL);
			clientPort = tempPort;
			std::cout << "Client address: " << clientAdr << ", client port: "<<  clientPort << std::endl;
			
			printf("\nCommencing fruit transfer.");

			for (;;)
			{
				int i = (rand() % fruit_count);
				std::string transWei = std::to_string(basketVec[i]->getWei());
				std::string transCol = basketVec[i]->getCol();

				SUCCESSFUL = send(sock_Connection, transWei.c_str(), 20, NULL);
				SUCCESSFUL = send(sock_Connection, transCol.c_str(), 20, NULL);

				Sleep(30000);
			}

		}
	}
}

Basket::~Basket()
{
}
