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
ContBancar* ManagerConturi::FindAccount()
{
	std::cout << "numele tutularului: \n";
	std::string nume;
	std::cin >> nume;
	//TOLDO-done trebuie extins sie facem o metoda ce accepta NUme sau Prenume, fie facem cumva in aceasta metoda
	for (auto& cont : m_listaConturi)
	{
		if (cont->getNume() == nume)
			return cont;
	}
	std::cout << "titularul nu a fost gasit\n";
	return nullptr;
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
	m_fileManager->WriteToCSV(nume, prenume, iban,cont->getSold());
	system("cls");
	//cont bancar creat 
	/*std::cout << "cont bancar creat: " << std::endl;
	std::cout << nume << std::endl;
	std::cout << prenume << std::endl;
	std::cout << iban << std::endl;*/


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
	/*std::cout << "Apasati tasta 0 pentru a va intoarce"<<std::endl;
	char back;
	std::cin >> back;*/
	//return back;
}

void ManagerConturi::EraseAccount()
{
	std::cout << "Introduceti datele pentru contul ce urmeaza sa fie sters\n";
	ContBancar* cont = FindAccount();
	std::vector<ContBancar*>::iterator it = std::find(m_listaConturi.begin(), m_listaConturi.end(), cont);
	m_listaConturi.erase(it);
	delete cont;	
}

void ManagerConturi::Eliberare_Depunere()
{
	ContBancar* cont = FindAccount();
	if (cont != nullptr)
	{
		float valoare;
		std::cout << "introdu valoare: \n";
		std::cin >> valoare;
		cont->manipulareSold(valoare);
		/*if (valoare >= 0)
		{
			cont->depunere(valoare);
		}
		else
		{
			cont->retragere(valoare);
		}*/
	}
	else
	{
		std::cout << "contul este inexistent\n";
	}
}

ManagerConturi::ManagerConturi()
{
	m_fileManager = new FileManager();
	//populam lista conturi cu ce se afla in .csv
	m_listaConturi = m_fileManager->ReadContBancarFromCSV();
	/*while (ptr!=nullptr)
	{
		m_listaConturi.push_back(ptr);
		ptr = m_fileManager->ReadContBancarFromCSV();
	}*/
}

ManagerConturi::~ManagerConturi()
{
	delete m_fileManager;
	//m_listaConturi.clear();
	//TODO: Iteran m_lista conturi si stergem fiecare cont in parte dupa care cler-uim
}

void ManagerConturi::PrintASpecificCont(const std::string& cautaNume,const std::string& cautaPrenume)
{
	bool n = false;

	for (auto& cont : m_listaConturi)
	{
		if (cautaNume == cont->getNume() && cautaPrenume == cont->getPrenume())
		{
			std::cout << "nume: " << cont->getNume() << std::endl;
			std::cout << "prenume: " << cont->getPrenume() << std::endl;
			std::cout << "iban: " << cont->getIban() << std::endl;
			std::cout << "sold: " << cont->getSold() << std::endl;
			n=true;
		}
	}
	if (n == false)
	{
		std::cout << "ne pare rau, dar criteriile de cautare nu se potrivesc cu nici un cont existent\n";
	}
	char back;
	std::cout << "apasati orice tasta pentru a va intoarce\n";
	std::cin >> back;
}

void ManagerConturi::Modificare_cont()
{
	ContBancar* cont = FindAccount();
	if(cont !=nullptr)
	{ 
		std::cout << "daca doriti sa modificati numele apasati orice tasta in afara de 0\n";
		bool n, m = false;
		std::cin >> n;
		if (n)
		{
			std::cout << "Introduceti numele nou\n";
			std::string nume;
			std::cin >> nume;
			cont->changeNume(nume);
		}
		std::cout << "daca doriti sa schimbati prenumele apasati orice tasta in afara de 0\n";
		std::cin >> m;
		if (m)
		{
			std::cout << "Introduceti prenume nou\n";
			std::string prenume;
			std::cin >> prenume;
			cont->changeNume(prenume);
		}
	}
	else
	{
		std::cout << "cont inexistent\n";
	}
}
