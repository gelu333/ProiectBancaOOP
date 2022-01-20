#include "ManagerConturi.h"
#include<iostream>

std::string ManagerConturi::CreateIban()
{
	return std::string();
}

void ManagerConturi::adaugareCont()
{
	std::string nume, prenume, iban;
	std::cout << "introduceti numele persoanei: \n";
	std::cin >> nume;
	std::cout << "introduceti prenumele persoanei: \n";
	std::cin >> prenume;
	//TODO: replace whith createIban()
	iban = "TestIban";
	ContBancar* cont = new ContBancar(nume, prenume, iban);
	m_listaConturi.push_back(cont);
	system("cls");
}
