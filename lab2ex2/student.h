#ifndef STUDENT_H
#define STUDENT_H


class student
{
    int count[10];
    int numbers [10];
    char nume[100];
    float notaMate;
    float notaEngleza;
    float notaIstorie;
    float medie;

    public:
        void SetName(const char*NumeIntrodus);
        const char*GetName();
        float Medie();
        bool SetNotaMate(float nota);
        float GetNotaMate();
        bool SetNotaEngleza(float nota2);
        float GetNotaEngleza();
        bool SetNotaIstorie(float nota3);
        float GetNotaIstorie();

};
int ComparaNume(student& s1 , student& s2);
int ComparaMedie(student& s1 , student& s2);
int ComparaMate(student& s1 , student& s2);
int ComparaEngleza(student& s1 , student& s2);
int ComparaIstorie(student& s1 , student& s2);

#endif // STUDENT_H
