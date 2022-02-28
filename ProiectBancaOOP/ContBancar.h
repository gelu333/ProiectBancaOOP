#pragma once
#include<string>


enum class TipMoneda
{
	RON,
	EUR,
	DOLLAR
};
/*enum class Esper { Unu, Du, Tri, Kvar, Kvin, Ses, Sep, Ok, Naux, Dek };
 
constexpr const char* EsperToString(Esper e) throw()
{
    switch (e)
    {
        case Esper::Unu: return "Unu";
        case Esper::Du: return "Du";
        case Esper::Tri: return "Tri";
        case Esper::Kvar: return "Kvar";
        case Esper::Kvin: return "Kvin";
        case Esper::Ses: return "Ses";
        case Esper::Sep: return "Sep";
        case Esper::Ok: return "Ok";
        case Esper::Naux: return "Naux";
        case Esper::Dek: return "Dek";
        default: throw std::invalid_argument("Unimplemented item");
    }
}*/



class ContBancar
{
	std::string m_nume;
	std::string m_prenume;
	float m_sold;
	std::string m_IBAN;
	//TODO-pending: tipul soldului va trebui sa fie modificat intr-un enum 0=RON, 1=EUR
	//https://belaycpp.com/2021/08/24/best-ways-to-convert-an-enum-to-a-string/
	//se paote rezolva numai cu un "case"
	TipMoneda m_tipSold;
public:
	ContBancar(std::string nume, std::string prenume, std::string iban,float sold);
	std::string getNume() const;
	std::string getPrenume() const;
	std::string getIban() const;
	float getSold() const;
	//void depunere(float suma);
	void manipulareSold(float suma);
	void changeNume(const std::string& changenume);
	void changePrenume(const std::string& changeprenume);

};

