#pragma once
#include "ContBancar.h"
#include<vector>
#include"FileManager.h"

class ManagerConturi
{
private:
	std::vector<ContBancar*> m_listaConturi;
	//TODO-done: metoda createIban trebuie sa genereze un Iban unic care sa fie folosit 
	//pentru a crea conturi
	std::string CreateIban();//TODO-done: BUG: Iban is not entirely unique brecause if we stop the program it starts reusing keys
	ContBancar* FindAccount();
	FileManager* m_fileManager;
	//incercam sa il facem singleton
	static ManagerConturi* instance;

public:

	//avem nevoie de o metoda publica ca sa accesam poointerul static singleton
	static ManagerConturi* getInstance();

	void adaugareCont();

	int GetNumarConturi();

	int printAllConturi();

	int EraseAccount();

	void Eliberare_Depunere();

	ManagerConturi();
	~ManagerConturi();
	int PrintASpecificCont(const std::string& cautaNume,const std::string& cautaPrenume);

	int Modificare_cont();

};

