// ProiectBancaOOP.cpp : 
//Banca Proiect.
//ITSchoolBank
//
//1. O clasa cont bancar ce trebuie sa aibe atribute precum nume, prenume, sold, tip de cont(valuta sau lei) IBAN
//Un cont trebuie neaparat sa aibe un nume, prenume si un IBAN care trebuie sa fie unic
//
//2.in maine se afla terminalul principal al bancii in care trebuie sa avem urmatoarele optiunii
//2.1 numar de conturi-- > ce ne da numarul de conturi inregistrate in banca
//2.2 creare cont-- > cu aceasta optiune se poate crea un cont nou
//2.2.1 -- > ar trebui un scrren diferit si un set de optiuni in care
//operatorul bancii sa introduca datele pentru crearea contului.(trebuie ca aceasta procedura sa verifice daca exista deja contul ce
//    se doreste creat iar daca da sa anunte opreatorul)
//    2.2.2 -- > o optiune de return la main screen(ecranul cu optiunie principale)
//    2.3 O optiune de modificare cont->in care operatorul poate sa modifice date despre cont(ex schimbare nume, schimbare sume etc)
//    2.4 O optiune prin care un cont se poate sterge din sistemul bancii
//    2.5 O optiune prin care un cont poate sa extraga sume - > vrei sa adaugi sau sa extragi o suma de bani
//    2.6 O optiune prin care un cont sa vada care este suma din cont
//    Trebuie cautat contul intordu- s iar daca exista se poate vizualiza
//    Daca nu exista putem incepe o procedura de creare cont
//
//    3. Un sistem in care putem sa salvam datele acestea intr - un fisier local(CSV file)

#include <iostream>
//#include "ContBancar.h"
#include "ManagerConturi.h"
//TODO-done:la optiunea Modificare Cont , schimbarea in cauza trebuie sa fie reflectata si in .csv
//TODO-done:la optiunea stergere cont dupa ce este sters din m_lista_conturi trebuie sters si din .csv
//TODO: un sistem de user si parola ca sa asiguram ca operatorul poate sa lucreze pe statia respectiva
//TODO: la optiunea la eliberare/depunere modificarile sa fie reflectate si in .csv
int main()
{
    
         
     //ContBancar test("popistas", "Sergiu", "ro10235");
     //ContBancar* cont = new ContBancar("popistas", "sergiu", "ro938475");
    int optiune;
    ManagerConturi manager;
    int tasta;
    int temp = 0;
    do {
        
        std::cout << "alege una din urmatoare optiuni: \n";
        std::cout << "1-> numar conturi\n";
        std::cout << "2-> creare cont\n";
        std::cout << "3-> modificare cont\n";//TODO-done?: homework - > Modificare cont poate schimba nume, prenume
        std::cout << "4-> stergere cont\n";
        std::cout << "5-> eliberare/depunere\n";
        std::cout << "6-> detalii cont\n";//TODO: tema restanta
        std::cout << "0-> exit\n";
        std::cout << "introduceti operatia pe care o doriti\n";
        std::cin >> optiune;
        switch (optiune)
        {
        case 1:
            std::cout << "ati ales optiunea 1\n";
            std::cout << "numarul total de conturi este:    " << manager.GetNumarConturi() << std::endl;
            break;
        case 2:
            std::cout << "ati ales optiunea 2\n";
            system("cls");
            manager.adaugareCont();
            break;
        case 3:
            std::cout << "ati ales optiunea 3\n";
            //int temp=0;
            temp = manager.Modificare_cont();
            if (temp == 0)
            {
                std::cout << "cont inexistent sau nume si prenume gresit, reluati operatiunea de la inceput\n";
                //std::cout << "Apasati tasta 0 pentru a va intoarce la meniul principal\n 3 pentru a reincerca\n";
                //std::cin >> optiune;
            }
            else
            {
                std::cout << "operatiune realizata cu succes\n";
            }
            break;
        case 4:
            std::cout << "ati ales optiunea 4\n";
            temp = manager.EraseAccount();
            if (temp == 0)
            {
                std::cout << "cont inexistent sau nume si prenume gresit, reluati operatiunea de la inceput\n";
                //std::cout << "Apasati tasta 0 pentru a va intoarce la meniul principal\n 3 pentru a reincerca\n";
                //std::cin >> optiune;
            }
            else
            {
                std::cout << "stergere realizata cu succes\n";
            }
            break;
        case 5:
            std::cout << "ati ales optiunea 5\n";
            //ToDoforMe - sa il aduc la o forma ca cele de mai sus
            manager.Eliberare_Depunere();
            break;
        case 6:
            std::cout << "ati ales optiunea 6\n";
            system("cls");
            //TODO-done:tema2:vreti sa cautati un anumit cont?->apasati tasta 1
            //      o metoda prin care cereti detalii despre contul pe care vrem sa il gasim
            //      si desigur sa il cautam iar dupa aceea sa il printam
            //Vrei sa le accesati pe toate->apasati tasta 2
            std::cout << "Daca vreti sa cautati un anumit cont apasati tasta 1\n";
            std::cout << "Daca vreti afisati toate conturile apasati tasta 2\n";
            
            std::cin >> tasta;
            do {                
                std::string cautaNume;
                std::string cautaPrenume;
                //int temp = 1;
                switch (tasta)
                {
                case 1:
                    std::cout << "Ati ales sa accesati un anumit cont\n";                    
                    std::cout << "Va rugam sa introduceti numele beneficiarului de cont\n";
                    std::cin >> cautaNume;
                    std::cout << "Va rugam sa introduceti prenumele beneficiarului de cont\n";
                    std::cin >> cautaPrenume;
                    temp = manager.PrintASpecificCont( cautaNume, cautaPrenume);
                    if (temp == 0)
                    {
                        std::cout << "Apasati tasta 0 pentru a va intoarce la meniul principal\n 1 sau 2 pentru a face operatiile anterioare\n";
                        std::cin >> tasta;
                    }
                    tasta = 0;
                    break;
                case 2:
                    std::cout << "Ati ales sa accesati toate conturile\n";
                    temp = manager.printAllConturi();
                    if (temp == 0)
                    {
                        std::cout << "Apasati tasta 0 pentru a va intoarce la meniul principal\n 1 sau 2 pentru a face operatiile anterioare\n";
                        std::cin >> tasta;
                    }
                    tasta = 0;
                    break;
                default:
                    std::cout << "Optiune invalida\n";
                    std::cout << "Apasati tasta 0 pentru a va intoarce la meniul principal\n 1 sau 2 pentru a face operatiile anterioare\n";
                    std::cin >> tasta;
                    break;
                }
            } while (tasta != 0);
            break;
        case 0:
            std::cout << "Multumim,la revedere\n";
            break;
        default:
            std::cout << "Optiune invalida\n";
            break;
        }
    } while (optiune != 0); 
}

