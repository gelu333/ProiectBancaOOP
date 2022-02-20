#include "ContBancar.h"

ContBancar::ContBancar(std::string nume, std::string prenume, std::string iban)
{
	m_nume = nume;;
	m_prenume = prenume;
	m_sold = 0;
	m_IBAN = iban;
	//TODO: tipul soldului va trebui sa fie modificat intr-un enum 0=RON, 1=EUR
	m_tipSold = TipMoneda::RON;

}

std::string ContBancar::getNume() const
{
	return m_nume;
}

std::string ContBancar::getPrenume() const
{
	return m_prenume;
}

std::string ContBancar::getIban() const
{
	return m_IBAN;
}

float ContBancar::getSold() const
{
	return m_sold;
}

void ContBancar::manipulareSold(float suma)
{
	m_sold += suma;
}

void ContBancar::changeNume(const std::string& changenume)
{
	m_nume = changenume;
}

void ContBancar::changePrenume(const std::string& changeprenume)
{
	m_prenume = changeprenume;
}

//void ContBancar::retragere(float suma)
//{
//	m_sold += suma;
//
//}
