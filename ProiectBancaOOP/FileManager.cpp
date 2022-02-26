#include "FileManager.h"
//https://www.geeksforgeeks.org/csv-file-management-using-c/
//https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp/

void FileManager::WriteToCSV(std::string nume,std::string prenume,std::string iban,float sold)
{
	std::fstream csv_file;
	csv_file.open("ConturiDataBase.csv",std::ios::out|std::ios::app);
	if (csv_file.is_open())
	{
		csv_file << nume << ','<<prenume<<',' << iban <<','<< sold<< '\n';
	}
	else
	{
		std::cout << "ERROR, file not opened\n";
	}
	csv_file.close();
}

std::vector<ContBancar*> FileManager::ReadContBancarFromCSV()
{
	std::ifstream  fileInput("ConturiDataBase.csv");
	//fileInput.open("ConturiDataBase.csv", std::ios::in);
	std::vector<ContBancar*> conturiDinCsv;
	std::vector<std::string> randuri;
	std::string linie;
	if (!fileInput.is_open())
	{
		std::cout << "Error file cannot be accesd\n";
	}
	//parsam toate liniile din fisier
	while (std::getline(fileInput, linie))
	{
		randuri.push_back(linie);
	}
	std::vector<std::string> cuvinte;
	//parsam rand cu rand si spargem in cuvinte 
	//instantam conturile si le pushuim in vecotrul nostru
	for (auto& rand : randuri)
	{
		cuvinte.clear();
		std::string nume, prenume, iban, cuvant;
		float sold;
		std::stringstream s(rand);
		while (std::getline(s, cuvant, ','))
		{
			if (!cuvant.empty())
				cuvinte.push_back(cuvant);
		}
		if (!cuvinte.empty()) {
			ContBancar* cont = new ContBancar(cuvinte[0], cuvinte[1], cuvinte[2],std::stof((cuvinte[3])));//ToDo-done:mai un constructor pentru sold pentru ContBancar
			conturiDinCsv.push_back(cont);
		}

	}
	return conturiDinCsv;
}

//ContBancar* FileManager::ReadContBancarFromCSV()
//{
//	std::fstream fileInput;
//	//fileInput.open("ConturiDataBase.csv", std::ios::in);
//	std::vector<ContBancar> conturiDinCsv;
//	std::vector<std::string> randuri;
//	std::string linie, cuvant, temp;
//	if (!fileInput.is_open())
//	{
//		std::cout << "error file cannot be accesd\n";
//	}
//	//parsam toate linile di  fisier
//	while (std::getline(fileInput,linie)
//	{
//		randuri.push_back(linie);
//	}
//	std::vector<std::string> cuvinte;
//	//parsam rand cu rand si spargem in cuvinte
//	//instantam conturile si le pusuim in vectorul nostru 
//	for (auto& rand : randuri)
//	{
//		cuvinte.clear();
//		std::string nume, prenume, iban, cuvant;
//		float sold;
//		std::stringstream s(rand);
//		while (std::getline(s, temp, ',')
//		{
//			if (!cuvant.empty())
//			{
//				cuvinte.push_back(cuvant);
//			}
//			
//		}
//		if(cuvinte.empty())
//			ContBancar* cont = new ContBancar(cuvinte[0],cuvinte[1],cuvinte[2]);//TODO: mai un constructor pentru sold
//			conturiDinCsv.push_back(cont);
//	}
//
//	//while (fileInput >> temp)
//	//{
//	//	rand.clear();
//	//	//citim o linie din fisier si o salvam in var linie
//	//	std::getline(fileInput,linie);
//	//	//este folosit pentru a sparge in cuvinte
//	//	std::stringstream s(linie);
//	//	//citim fiecare coloana dinntr-un rand
//	//	//si o salvam intro variabil string numita cuvant
//	//	while (std::getline(s, cuvant, ',')
//	//	{
//	//		rand.push_back(cuvant);
//	//	}
//	//}
//	return nullptr;
//}
