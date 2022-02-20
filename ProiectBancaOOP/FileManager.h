#pragma once
#include<iostream>
#include <fstream>
#include<string>
#include"ContBancar.h"
#include<vector>
#include<sstream>
class FileManager
{
public:
	void WriteToCSV(std::string nume, std::string prenume, std::string iban,float sold);
	std::vector<ContBancar*> ReadContBancarFromCSV();
};

 