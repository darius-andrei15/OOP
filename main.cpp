#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int myAtoi(char *s)
{
    int rez = 0, i=0;

    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
            rez = rez * 10 + (s[i] - '0');
        i++;
    }

    return rez;
}

void ex1()
{
    FILE *file;
    int sum = 0;
    char buffer[100];

    fopen_s(&file, "in.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }


    while (fgets(buffer, sizeof(buffer), file) != NULL)
        {
            int nr = myAtoi(buffer);
            sum += nr;
        }


    fclose(file);
    printf("%d\n", sum);

}

void ex2()
{
   char s[100];
   char cuv[100][100];
   int nr=0;

   printf("Introduceti o propozitie: ");
   cin.getline(s, 100);

   char *p;
   p=strtok(s, " ");
   while(p!=NULL)
   {
        strcpy(cuv[nr], p);
        nr++;
        p=strtok(NULL, " ");
   }

    int ok=0;

   for (int i=0; i<nr-1; i++)
    for (int j=0; j<nr-i-1; j++)
    {
        if(strlen(cuv[j])<strlen(cuv[j+1]))
            ok=1;

        if(strlen(cuv[j])== strlen(cuv[j+1]))
            if (strcmp(cuv[j], cuv[j+1])>0)
                ok=1;

        if(ok==1)
        {
            char temp[100];
            strcpy(temp, cuv[j]);
            strcpy(cuv[j],cuv[j+1]);
            strcpy(cuv[j+1],temp);
        }

        ok=0;
    }

    printf("\nCuvintele sortate:\n");
    for (int i = 0; i < nr; i++) {
        printf("%s\n", cuv[i]);
    }

}


bool isPrime(int n)
{
    for (int tr = 2; tr < n / tr; tr++)
        if ((n % tr) == 0)
            return false;
    return true;
}
int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !\n";
    else
        std::cout << n << " is NOT prime !\n";

    std::cin.ignore();

    std::cout << "\n Exercitiul 1" << std::endl;
    ex1();

    std::cout << "\n Exercitiul 2 " << std::endl;
    ex2();

    return 0;
}

