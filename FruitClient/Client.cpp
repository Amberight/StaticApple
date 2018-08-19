#include "stdafx.h"
#include "Client.h"


Client::Client()
{
	char response;
	printf("\nEstablish connection? y/n ");
	std::cin >> response;

	if (response == 'y')
	{
		connection();
	}
	else
	{
		printf("\nNope");
	}

}

void Client::connection()
{
	long SUCCESFULL;
	WSAData WinSockData;
	WORD DLLVersion;
	DLLVersion = MAKEWORD(2, 1);
	SUCCESFULL = WSAStartup(DLLVersion, &WinSockData);

	std::string stringWei;
	char transWei[20];
	std::string stringCol;
	char transCol[20];

	SOCKADDR_IN ADDRESS;

	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, NULL);

	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);
	int Adr = ADDRESS.sin_addr.s_addr;
	int Port = ADDRESS.sin_port;

	std::cout << Adr << std::endl;
	std::cout << Port << std::endl;

	std::string tempAdr = std::to_string(Adr);
	std::string tempPort = std::to_string(Port);

	connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
	SUCCESFULL = send(sock, tempAdr.c_str(), 20, NULL);
	SUCCESFULL = send(sock, tempPort.c_str(), 20, NULL);

	for (;;)
	{
		printf("\n\tWaiting for an boject... ");
		SUCCESFULL = recv(sock, transWei, sizeof(transWei), NULL);
		SUCCESFULL = recv(sock, transCol, sizeof(transCol), NULL);
		stringWei = transWei;
		stringCol = transCol;
		std::cout << "\nThis fruit is: " << transCol << " and weighs " << transWei << std::endl;
	}
}

Client::~Client()
{
}
