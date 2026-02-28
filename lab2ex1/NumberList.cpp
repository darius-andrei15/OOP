#include <iostream>
#include "NumberList.h"
void NumberList::Init()
{
    this->count = 0;
}
bool NumberList::Add(int x)

{
    if (this->count >= 10) {
        return false;
    }

    numbers[this->count] = x;
    this->count++;
    return true;
}

void NumberList::Sort() {
    for (int i = 0; i < this->count - 1; i++) {
        for (int j = 0; j < this->count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void NumberList::Print() {
    for (int i = 0; i < this->count; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}
