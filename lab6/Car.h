//
// Created by Darius on 3/25/2026.
//

#ifndef LAB6_CAR_H
#define LAB6_CAR_H
#include "Weather.h"
#pragma once
using namespace std;


class Car {
public:
    virtual ~Car()=default;
    virtual double FuelCapacity() const = 0;
    virtual double FuelCost() const = 0;
    virtual double AverageSpeed(Weather weather) const = 0;
    virtual const char* Name() const = 0;
};


#endif //LAB6_CAR_H
