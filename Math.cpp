#include<iostream>
#include "Math.h"
#include <cstdarg>
#include <cstring>

int Math::Add(int x, int y) {
    return x+y;
}
int Math::Add(int x, int y, int z) {
    return x+y+z;
}
int Math::Add(double x, double y) {
    return x+y;
}
int Math::Add(double x, double y, double z) {
    return x+y+z;
}
int Math::Mul(int x, int y) {
    return x*y;
}
int Math::Mul(int x, int y, int z) {
    return x*y+z;
}
int Math::Mul(double x, double y) {
    return x*y;
}

int Math::Add(int count, ...) {
        va_list args;
        va_start(args, count);
        int suma=0;
        for (int i=0;i<count;i++) {
            suma=suma+va_arg(args,int);
        }
        va_end(args);
        return suma;
}
char* Math::Add(const char* sir1, const char* sir2) {
    if (sir1==NULL || sir2==NULL) {
        return "NULL";
    }
    size_t len1=strlen(sir1);
    size_t len2=strlen(sir2);
    char* rezultat=new char[len1+len2+1];
    strcpy(rezultat,sir1);
    for (size_t i=0;i<len2;i++) {
        rezultat[len1+i]=sir2[i];
    }
    rezultat[len1+len2]='\0';
    return rezultat;
}
