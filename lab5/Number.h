#pragma once
#include <iostream>

class Number
{
private:
    char* value;
    int base;

    long long ToBase10() const;
    void FromBase10(long long val, int newBase);

public:
    Number();
    Number(const char* value, int base);
    Number(int value);
    ~Number();

    Number(const Number& other);
    Number(Number&& other) noexcept;

    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;
    Number& operator=(int val);
    Number& operator=(const char* val);

    void SwitchBase(int newBase);
    void Print() const;
    int  GetDigitsCount() const;
    int  GetBase() const;


    char operator[](int index) const;

    friend Number operator+(const Number& lhs, const Number& rhs);
    friend Number operator-(const Number& lhs, const Number& rhs);
    Number& operator+=(const Number& other);

    friend bool operator>(const Number& lhs, const Number& rhs);
    friend bool operator<(const Number& lhs, const Number& rhs);
    friend bool operator>=(const Number& lhs, const Number& rhs);
    friend bool operator<=(const Number& lhs, const Number& rhs);
    friend bool operator==(const Number& lhs, const Number& rhs);
    friend bool operator!=(const Number& lhs, const Number& rhs);

    Number& operator--();
    Number operator--(int);
};
