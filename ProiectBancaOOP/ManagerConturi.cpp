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
/*alternativa
std::string ManagerConturi::CreateIban()
 {
     std::string IBAN= "RO44ItSchool", IBAn;
     char alphanumeric[] = "0123456789QWERTYUIOPLKJHGFDSAZXCVBNM";
     for (int i = 0; i < 5; i++)
     {
         IBAn = alphanumeric[rand() % (sizeof(alphanumeric) - 1)]; 
         IBAN = IBAN + IBAn;
     }
     return IBAN;*/



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

int ManagerConturi::GetNumarConturi()
{
	int numarConturi = m_listaConturi.size();

	return numarConturi;
}

void ManagerConturi::printAllConturi()
{
	/*for (int i = 0; i < m_listaConturi.size(), i++)
	{
		m_listaConturi[i]->getNume();
	}*/

	/*for (auto it = m_listaConturi.begin(); it != m_listaConturi.end(); it++)
	{
		(*it)->getNume();
	}*/
	for (auto& cont : m_listaConturi)
	{
		//cont->getNume();
		std::cout << "nume: " << cont->getNume() << std::endl;
		std::cout << "prenume: " << cont->getPrenume() << std::endl;
		std::cout << "iban: " << cont->getIban() << std::endl;
		std::cout << "sold: " << cont->getSold() << std::endl;


	}
	std::cout << "Apasati/introduceti orice tasta '0' pentru a va intoarce\n";
	char back;
	std::cin >> back;
}
