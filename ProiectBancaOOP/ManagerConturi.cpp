#include "ManagerConturi.h"
#include<iostream>
//#include<string>
//TODO-done: Adaptati metoda CreateIban pentru a genera Ibanuri unice 
//Format:RO44ItSchool(caractere alfa-numerice - 5) astea ultimele 5 sa fie unice pentru IBAN
std::string ManagerConturi::CreateIban()
{

	//old method, not completley 
	//int iban = 11111 + (std::rand() % (99999));
	
	//new method
	//https://www.cplusplus.com/reference/cstdlib/rand/
	//https://www.programiz.com/cpp-programming/library-function/cstdlib/srand
	 /* initialize random seed: */
	srand(time(NULL));
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
	//ToDo: trebuie extins sie facem o metoda ce accepta NUme sau Prenume, fie facem cumva in aceasta metoda
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
	float sold=0;
	std::cout << "introduceti numele persoanei: \n";
	std::cin >> nume;
	std::cout << "introduceti prenumele persoanei: \n";
	std::cin >> prenume;
	//TODO-done: replace whith createIban()
	iban = CreateIban();
	//ContBancar* cont = new ContBancar(nume, prenume, iban);
	ContBancar* cont = new ContBancar(nume, prenume, iban,sold);
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

int ManagerConturi::printAllConturi()
{
	if (GetNumarConturi()!=0)
	{
		for (auto& cont : m_listaConturi)
		{
			//cont->getNume();
			std::cout << "nume: " << cont->getNume() << std::endl;
			std::cout << "prenume: " << cont->getPrenume() << std::endl;
			std::cout << "iban: " << cont->getIban() << std::endl;
			std::cout << "sold: " << cont->getSold() << std::endl;
		}
		return 1;
	}
	else
	{
		return 0;
	}
	
	
}

int ManagerConturi::EraseAccount()
{
	std::cout << "Introduceti datele pentru contul ce urmeaza sa fie sters\n";
	ContBancar* cont = FindAccount();
	if (cont != nullptr)
	{
		std::vector<ContBancar*>::iterator it = std::find(m_listaConturi.begin(), m_listaConturi.end(), cont);
		m_listaConturi.erase(it);
		delete cont;		
		//1 erase file
		//https://www.cplusplus.com/reference/cstdio/remove/
		if (remove("ConturiDataBase.csv") != 0)
		{
				std::cout<<"Error deleting file"<<std::endl;
		}
		else
		{
			std::cout << "File successfully deleted" << std::endl;
		}
		//2 write the whole .csv file from scratch
		if (GetNumarConturi() != 0)
		{
			for (auto& cont : m_listaConturi)
			{			
				m_fileManager->WriteToCSV(cont->getNume(), cont->getPrenume(), cont->getIban(), cont->getSold());
			}			
		}		
		return 1;
	}
	else
	{
		return 0;
	}
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
		//1 erase file
		//https://www.cplusplus.com/reference/cstdio/remove/
		if (remove("ConturiDataBase.csv") != 0)
		{
			std::cout << "Error deleting file" << std::endl;
		}
		else
		{
			std::cout << "File successfully deleted" << std::endl;
		}
		//2 write the whole .csv file from scratch
		if (GetNumarConturi() != 0)
		{
			for (auto& cont : m_listaConturi)
			{
				m_fileManager->WriteToCSV(cont->getNume(), cont->getPrenume(), cont->getIban(), cont->getSold());
			}
		}
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
	//TODO?: Iteran m_lista conturi si stergem fiecare cont in parte dupa care clear-uim
	//de intrebat daca mai trebe facut ceva?
}

int ManagerConturi::PrintASpecificCont(const std::string& cautaNume,const std::string& cautaPrenume)
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
		return 0;
	}
	/*char back;
	std::cout << "apasati orice tasta pentru a va intoarce\n";
	std::cin >> back;*/
	return 1;

}

int ManagerConturi::Modificare_cont()
{
	ContBancar* cont = FindAccount();
	if(cont !=nullptr)
	{ 
		int n, m;
		std::cout << "daca doriti sa modificati numele apasati orice tasta in afara de 0, doar numere\n";		
		std::cin >> n;
		if (n)
		{
			std::cout << "Introduceti numele nou\n";
			std::string nume;
			std::cin >> nume;
			cont->changeNume(nume);
		}
		std::cout << "daca doriti sa schimbati prenumele apasati orice tasta in afara de 0, doar numere\n";
		std::cin >> m;
		if (m)
		{
			std::cout << "Introduceti prenume nou\n";
			std::string prenume;
			std::cin >> prenume;
			cont->changePrenume(prenume);
		}
		// 1 erase file
		//https://www.cplusplus.com/reference/cstdio/remove/
		if (remove("ConturiDataBase.csv") != 0)
		{
			std::cout << "Error deleting file" << std::endl;
		}
		else
		{
				std::cout << "File successfully deleted" << std::endl;
		}
		//2 write the whole .csv file from scratch
		if (GetNumarConturi() != 0)
		{
			for (auto& cont : m_listaConturi)
			{
				m_fileManager->WriteToCSV(cont->getNume(), cont->getPrenume(), cont->getIban(), cont->getSold());
			}
		}
		return 1;
	}
	else
	{		
		return 0;
	}
}

// initializez aici din comoditate
//varaibila astatica trebuie initializata la prima chemare
ManagerConturi* ManagerConturi::instance = 0;

ManagerConturi* ManagerConturi::getInstance()
{
	
	if (instance != nullptr)
	{
		return instance;
	}
	else
	{
		instance = new ManagerConturi();
		return instance;

	}

	//return nullptr;
}