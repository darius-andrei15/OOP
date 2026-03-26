#include "Circuit.h"
#include<iostream>
using namespace std;

Circuit::Circuit(): carCount(0), lenght(0), weather(Weather::Rain) {}

Circuit::~Circuit() {
    for (int i=0; i<carCount; i++) {
        delete cars[i];
    }
}

void Circuit::SetLength(double length) {
    this->lenght = length;
}

void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
}

void Circuit::AddCar(Car *car) {
    if (carCount<100 && car!=NULL) {
        cars[carCount] = car;
        carCount++;
    }
}

void Circuit::Race() {
    for (int i=0; i<carCount; i++) {
        double speed=cars[i]->AverageSpeed(weather);
        double fuelCapacity=cars[i]->FuelCapacity();
        double fuelCost=cars[i]->FuelCost();
        double fuelNeeded=(lenght/100.00)*fuelCost;

        if (fuelCapacity>=fuelNeeded) {
            finished[i]=true;
            finishTimes[i]=lenght/speed;
        }
        else {
            finished[i]=false;
            finishTimes[i]=-1.0;
        }
    }
}

void Circuit::ShowFinalRank() {
    int rank[100];
    int rankCount=0;
    for (int i=0; i<carCount; i++) {
        if (finishTimes[i]>0) {
            rank[rankCount++]=i;
        }
    }
    for (int i=0; i<rankCount; i++) {
        for (int j=0; j<rankCount-i-1; j++) {
            if (finishTimes[j]<finishTimes[j+1]) {
                int temp=rank[j];
                rank[j]=rank[j+1];
                rank[j+1]=temp;
            }
        }
    }
    for (int i = 0; i < rankCount; ++i) {
        int carIdx = rank[i];
        std::cout << (i + 1) << ". " << cars[carIdx]->Name()
                  << " - Time: " << finishTimes[carIdx] << " hours\n";
    }
    std::cout << "\n";
}

void Circuit::ShowWhoDidNotFinish() {
    std::cout << "Did Not Finish\n";
    bool allFinished = true;
    for (int i = 0; i < carCount; ++i) {
        if (!finished[i]) {
            std::cout << "- " << cars[i]->Name() << " (Not enough fuel)\n";
            allFinished = false;
        }
    }
    if (allFinished) {
        std::cout << "Everyone finished the circuit!\n";
    }
    std::cout << "\n";
}

