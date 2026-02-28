#include <iostream>
#include <string.h>
#include "student.h"
void student::SetName(const char* NumeIntrodus)
{
    strncpy(this->nume, NumeIntrodus, 99);
    this->nume[99] = '\0';
}
const char* student::GetName()
{
    return this->nume;
}
bool student::SetNotaMate(float nota)
{
    if (nota >= 1 && nota <= 10)
    {
        this->notaMate = nota;
        return true;
    }
    return false;
}
float student::GetNotaMate()
{
    return this->notaMate;
}
bool student::SetNotaEngleza(float nota2)
{
    if (nota2>=1 && nota2<=10)
    {
        this->notaEngleza=nota2;
        return true;
    }
    return false;
}
float student::GetNotaEngleza()
{
    return this->notaEngleza;
}
bool student::SetNotaIstorie(float nota3)
{
    if(nota3>=1 && nota3<=10)
    {
        this->notaIstorie=nota3;
        return true;
    }
    return false;
}
float student::GetNotaIstorie()
{
    return this->notaIstorie;
}
float student::Medie()
{
    float const S=notaEngleza+notaIstorie+notaMate;
    medie=S/3;
    return medie;
}
int ComparaNume(student& s1 , student& s2)
{
    int rezultat= strcmp(s1.GetName(), s2.GetName());
    if(rezultat==0)return 0;
    if(rezultat==1)return 1;
    return -1;
}
int ComparaMedie(student& s1 , student& s2)
{
    if(s1.Medie()>s2.Medie())return 1;
    if(s1.Medie()<s2.Medie())return -1;
    return 0;
}
int ComparaMate(student& s1,student& s2)
{
    if(s1.GetNotaMate()>s2.GetNotaMate())return 1;
    if(s2.GetNotaMate()<s2.GetNotaMate())return -1;
    return 0;
}
int ComparaEngleza(student& s1 , student& s2)
{
    if(s1.GetNotaEngleza()>s2.GetNotaEngleza())return 1;
    if(s2.GetNotaEngleza()<s2.GetNotaEngleza())return -1;
    return 0;
}
int ComparaIstorie(student& s1 , student& s2)
{
    if(s1.GetNotaIstorie()>s2.GetNotaIstorie())return 1;
    if(s2.GetNotaIstorie()<s2.GetNotaIstorie())return -1;
    return 0;
}

