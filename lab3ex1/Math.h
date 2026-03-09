
#ifndef LABORATOR3_MATH_H
#define LABORATOR3_MATH_H
#include<cstdarg>
class Math
{
public:
    static int Add(int x,int y);
    static int Add(int x,int y,int z);
    static int Add(double x,double y);
    static int Add(double x,double y,double z);
    static int Mul(int x,int y);
    static int Mul(int x,int y,int z);
    static int Mul(double x,double y);
    static int Mul(double x,double y,double z);
    static int Add(int count,...); // sums up a list of integers
    static char* Add(const char* sir1, const char * sir2);
};



#endif //LABORATOR3_MATH_H
