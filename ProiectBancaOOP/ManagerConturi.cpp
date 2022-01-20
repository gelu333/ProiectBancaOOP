#include "ManagerConturi.h"
#include<iostream>
//TODO TEMA: Adaptati metoda CreateIban pentru a genera Ibanuri unice 
//Format:RO44ItSchool(caractere alfa-numerice - 5) astea ultimele 5 sa fie unice pentru IBAN
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
