//
// Created by Darius on 3/25/2026.
//

#ifndef LAB6_BMW_H
#define LAB6_BMW_H
#include "Car.h"

class BMW: public Car {
public:
    double FuelCapacity() const override;
    double FuelCost() const override;
    double AverageSpeed(Weather weather) const override;
    const char* Name() const override;
};


#endif //LAB6_BMW_H
