#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <cstdio>
#include <algorithm>

long long Number::ToBase10() const {
    if (!value) return 0;
    long long res = 0;
    int len = strlen(value);
    for (int i = 0; i < len; ++i) {
        int digit = 0;
        if (value[i] >= '0' && value[i] <= '9') digit = value[i] - '0';
        else if (value[i] >= 'A' && value[i] <= 'F') digit = value[i] - 'A' + 10;
        else if (value[i] >= 'a' && value[i] <= 'f') digit = value[i] - 'a' + 10;
        res = res * base + digit;
    }
    return res;
}

void Number::FromBase10(long long val, int newBase) {
    char buffer[100];
    int pos = 0;
    if (val == 0) buffer[pos++] = '0';

    while (val > 0) {
        int rem = val % newBase;
        if (rem < 10) buffer[pos++] = rem + '0';
        else buffer[pos++] = rem - 10 + 'A';
        val /= newBase;
    }
    buffer[pos] = '\0';

    for (int i = 0; i < pos / 2; ++i) {
        std::swap(buffer[i], buffer[pos - 1 - i]);
    }

    delete[] value;
    value = new char[pos + 1];
    strcpy(value, buffer);
    base = newBase;
}

Number::Number() {
    base = 10;
    value = new char[2];
    strcpy(value, "0");
}

Number::Number(const char* value, int base) {
    this->base = base;
    this->value = new char[strlen(value) + 1];
    strcpy(this->value, value);
}

Number::Number(int val) {
    this->base = 10;
    this->value = nullptr;
    FromBase10(val, 10);
}

Number::~Number() {
    delete[] value;
}


Number::Number(const Number& other) {
    base = other.base;
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
}

Number::Number(Number&& other) noexcept {
    base = other.base;
    value = other.value;
    other.value = nullptr;
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        base = other.base;
        value = new char[strlen(other.value) + 1];
        strcpy(value, other.value);
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        base = other.base;
        value = other.value;
        other.value = nullptr;
    }
    return *this;
}

Number& Number::operator=(int val) {
    FromBase10(val, this->base);
    return *this;
}

Number& Number::operator=(const char* val) {
    delete[] value;
    value = new char[strlen(val) + 1];
    strcpy(value, val);
    return *this;
}

void Number::SwitchBase(int newBase) {
    if (base == newBase) return;
    FromBase10(ToBase10(), newBase);
}

void Number::Print() const {
    if (value) printf("%s\n", value);
}

int Number::GetDigitsCount() const {
    return value ? strlen(value) : 0;
}

int Number::GetBase() const {
    return base;
}

char Number::operator[](int index) const {
    if (value && index >= 0 && index < strlen(value)) return value[index];
    return '\0';
}

Number operator+(const Number& lhs, const Number& rhs) {
    int maxBase = std::max(lhs.GetBase(), rhs.GetBase());
    Number res;
    res.FromBase10(lhs.ToBase10() + rhs.ToBase10(), maxBase);
    return res;
}

Number operator-(const Number& lhs, const Number& rhs) {
    int maxBase = std::max(lhs.GetBase(), rhs.GetBase());
    long long diff = lhs.ToBase10() - rhs.ToBase10();
    Number res;
    res.FromBase10(diff > 0 ? diff : 0, maxBase);
    return res;
}

Number& Number::operator+=(const Number& other) {
    long long sum = this->ToBase10() + other.ToBase10();
    int maxBase = std::max(this->base, other.base);
    this->FromBase10(sum, maxBase);
    return *this;
}

bool operator>(const Number& lhs, const Number& rhs) { return lhs.ToBase10() > rhs.ToBase10(); }
bool operator<(const Number& lhs, const Number& rhs) { return lhs.ToBase10() < rhs.ToBase10(); }
bool operator>=(const Number& lhs, const Number& rhs) { return lhs.ToBase10() >= rhs.ToBase10(); }
bool operator<=(const Number& lhs, const Number& rhs) { return lhs.ToBase10() <= rhs.ToBase10(); }
bool operator==(const Number& lhs, const Number& rhs) { return lhs.ToBase10() == rhs.ToBase10(); }
bool operator!=(const Number& lhs, const Number& rhs) { return lhs.ToBase10() != rhs.ToBase10(); }

Number& Number::operator--() {
    if (value && strlen(value) > 0) {
        memmove(value, value + 1, strlen(value));
    }
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    if (value && strlen(value) > 0) {
        value[strlen(value) - 1] = '\0';
    }
    return temp;
}
