//
// Created by Darius on 3/25/2026.
//

#ifndef LAB6_CIRCUIT_H
#define LAB6_CIRCUIT_H
#include "Car.h"
#include "Weather.h"


class Circuit {
private:
        Car* cars[100];
        double finishTimes[100];
        bool finished[100];
        int carCount;
        double lenght;
        Weather weather;

public:
        Circuit();
        ~Circuit();
        void SetLength(double length);
        void SetWeather(Weather weather);
        void AddCar(Car* car);
        void Race();
        void ShowFinalRank();
        void ShowWhoDidNotFinish();
};


#endif //LAB6_CIRCUIT_H
