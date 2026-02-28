#include <iostream>
#include "NumberList.h"

int main() {
    NumberList listaMea;

    listaMea.Init();

    listaMea.Add(50);
    listaMea.Add(20);
    listaMea.Add(80);
    listaMea.Add(10);
    listaMea.Add(90);

    std::cout << "Lista initiala: ";
    listaMea.Print();

    listaMea.Sort();
    std::cout << "Lista dupa sortare: ";
    listaMea.Print();

    std::cout << "\nIncercam sa depasim capacitatea maxima..." << std::endl;
    for (int i = 1; i <= 7; i++) {
        if (!listaMea.Add(i * 5)) {
            std::cout << "Eroare: Nu s-a putut adauga numarul " << (i * 5) << ". Lista este plina!" << std::endl;
        } else {
            std::cout << "S-a adaugat cu succes numarul " << (i * 5) << "." << std::endl;
        }
    }

    std::cout << "Lista finala: ";
    listaMea.Print();

    return 0;
}
