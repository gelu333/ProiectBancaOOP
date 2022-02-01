#include "FileManager.h"


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
}
