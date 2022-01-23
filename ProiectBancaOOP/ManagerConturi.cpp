#include "ManagerConturi.h"
#include<iostream>
//#include<string>
//TODO TEMA: Adaptati metoda CreateIban pentru a genera Ibanuri unice 
//Format:RO44ItSchool(caractere alfa-numerice - 5) astea ultimele 5 sa fie unice pentru IBAN
std::string ManagerConturi::CreateIban()
{
	
	int iban = 11111 + (std::rand() % (99999));
	std::string stringIban = std::to_string(iban);
	std::cout << "IBAN generat:  "<< stringIban << std::endl;
	std::string stringIbanComplet = "RO44ItSchool"+stringIban;
	return stringIbanComplet;

}

void ManagerConturi::adaugareCont()
{
	std::string nume, prenume, iban;
	std::cout << "introduceti numele persoanei: \n";
	std::cin >> nume;
	std::cout << "introduceti prenumele persoanei: \n";
	std::cin >> prenume;
	//TODO: replace whith createIban()
	iban = CreateIban();
	//ContBancar* cont = new ContBancar(nume, prenume, iban);
	ContBancar* cont = new ContBancar(nume, prenume, iban);
	//cont bancar creat 
	std::cout << "cont bancar creat: " << std::endl;
	m_listaConturi.push_back(cont);
	system("cls");
	//cont bancar creat 
	std::cout << "cont bancar creat: " << std::endl;
	std::cout << nume << std::endl;
	std::cout << prenume << std::endl;
	std::cout << iban << std::endl;

}
