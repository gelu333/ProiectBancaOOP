#pragma once
#include "ContBancar.h"
#include<vector>

class ManagerConturi
{
private:
	std::vector<ContBancar*> m_listaConturi;
	//TODO: metoda createIban trebuie sa genereze un Iban unic care sa fie folosit 
	//pentru a crea conturi
	std::string CreateIban();
	ContBancar* FindAccount();
public:
	void adaugareCont();

	int GetNumarConturi();

	void printAllConturi();

	void EraseAccount();

	void Eliberare_Depunere();


};

