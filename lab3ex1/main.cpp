#include <algorithm>
#include<iostream>
#include<cstdarg>
#include "Math.h"
int main()
{
    double x=4,y=4,z=3;
    std::cout<<"Adunarea a doua numere naturale: "<<Math::Add(x,y)<<std::endl;
    std::cout<<"Inmultirea a doua numere reale: "<<Math::Mul(x,y)<<std::endl;
    std::cout<<Math::Add(3,4,5,6)<<std::endl;
    std::cout<<Math::Add("Darius","Andrei")<<std::endl;
    return 0;

}
