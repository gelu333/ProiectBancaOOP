#pragma once
#include "ContBancar.h"
#include<vector>
#include"FileManager.h"

class ManagerConturi
{
private:
	std::vector<ContBancar*> m_listaConturi;
	//TODO: metoda createIban trebuie sa genereze un Iban unic care sa fie folosit 
	//pentru a crea conturi
	std::string CreateIban();//TODO: BUG: Iban is not entirely unique brecause if we stop the program it starts reusing keys
	ContBancar* FindAccount();
	FileManager* m_fileManager;

public:
	void adaugareCont();

	int GetNumarConturi();

	void printAllConturi();

	void EraseAccount();

	void Eliberare_Depunere();

	ManagerConturi();
	~ManagerConturi();
	void PrintASpecificCont(const std::string& cautaNume,const std::string& cautaPrenume);


};

