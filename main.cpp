#include <iostream>
#include "Student.h"

int main()
{
    student elev1;
    elev1.SetName("Lionel Messi");
    elev1.SetNotaMate(10);
    elev1.SetNotaEngleza(10);
    elev1.SetNotaIstorie(10);
    std::cout<<elev1.GetName()<<" Are media: "<<elev1.Medie()<<std::endl;

    student elev2;
    elev2.SetName("Cristiano Ronaldo");
    elev2.SetNotaMate(7);
    elev2.SetNotaEngleza(7);
    elev2.SetNotaIstorie(7);
    std::cout<<elev2.GetName()<<" Are media: "<<elev2.Medie()<<std::endl;

    int rezultatNume=ComparaNume(elev1,elev2);
    if (rezultatNume==1)
        std::cout<<"Messi>Ronaldo"<<std::endl;
    if(rezultatNume==0)
        std::cout<<"Messi=Ronaldo"<<std::endl;
    if(rezultatNume==-1)
        std::cout<<"Messi<Ronaldo"<<std::endl;

    int rezultatMate=ComparaMate(elev1,elev2);
    if(rezultatMate==1)
        std::cout<<"Messi>Ronaldo"<<std::endl;
    if(rezultatMate==0)
        std::cout<<"Messi=Ronaldo"<<std::endl;
    if(rezultatMate==-1)
        std::cout<<"Messi<Ronaldo"<<std::endl;

    int rezultatEngleza=ComparaEngleza(elev1,elev2);
    if(rezultatEngleza==1)
        std::cout<<"Messi>Ronaldo"<<std::endl;
    if(rezultatEngleza==0)
        std::cout<<"Messi=Ronaldo"<<std::endl;
    if(rezultatEngleza==-1)
        std::cout<<"Messi<Ronaldo"<<std::endl;

    int rezultatIstorie=ComparaIstorie(elev1,elev2);
    if(rezultatIstorie==1)
        std::cout<<"Messi>Ronaldo"<<std::endl;
    if(rezultatIstorie==0)
        std::cout<<"Messi=Ronaldo"<<std::endl;
    if(rezultatIstorie==-1)
        std::cout<<"Messi<Ronaldo"<<std::endl;
return 0;
}

